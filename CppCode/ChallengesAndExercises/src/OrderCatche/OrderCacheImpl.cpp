#pragma once
#include "OrderCacheImpl.hpp"
#include <iterator>


/// <summary>
/// Checks if there are no securities or users with empty orders.
/// Function mainly for testing
/// </summary>
const bool OrderCacheImpl::noEmptySecurityAndUser() const {
	for (const auto& sec : m_securitiesOrders_buySell) {
		if (sec.second.first.empty() && sec.second.second.empty())
			return false;
	}
	for (const auto& sec : m_usersOrders) {
		if (sec.second.empty())
			return false;
	}
	return true;
}

// Checks if an order does not exist in the order cache by its ID.
inline const bool OrderCacheImpl::orderNotExist(const std::string& orderId) const
{
	return m_ordersByOrderId.find(orderId) == m_ordersByOrderId.end();
}

// Checks if an order has the correct format (i.e., quantity is not zero and side is either "Buy" or "Sell").
inline const bool OrderCacheImpl::orderHasCorrectFormat(const Order& order) const
{
	return order.qty() == 0 || !(order.side() == "Buy" || order.side() == "Sell");
}

// Checks if a user does not exist in the user orders map by their user name.
inline const bool OrderCacheImpl::userNotExist(const std::string& userName) const
{
	return m_usersOrders.find(userName) == m_usersOrders.end();
}

// Checks if a security ID does not exist in the securities orders map.
inline const bool OrderCacheImpl::securityIDNotExist(const std::string& securityId) const
{
	return m_securitiesOrders_buySell.find(securityId) == m_securitiesOrders_buySell.end();
}


void OrderCacheImpl::addOrder(Order order) {
	const std::string& orderId = order.orderId();
	const std::string& securityId = order.securityId();
	const std::string& userId = order.user();
	const bool isBuy = order.side() == "Buy";
	std::lock_guard<std::mutex> guard(m_mutex);

	// If the order already exists or has an incorrect format, do nothing.
	if (!orderNotExist(orderId)) {
		return;
	}

	if (orderHasCorrectFormat(order)) {
		return;
	}

	// Add the order to the orders map.
	m_ordersByOrderId.insert({ orderId,std::make_shared<Order>(std::move(order)) });
	// Associate the order with the user.
	m_usersOrders[userId][orderId] = m_ordersByOrderId[orderId];
	// Store the order in the appropriate buy or sell map based on its side.
	if (isBuy) {
		m_securitiesOrders_buySell[securityId].first[orderId] = m_ordersByOrderId[orderId];
	}
	else {
		m_securitiesOrders_buySell[securityId].second[orderId] = m_ordersByOrderId[orderId];
	}
}

void OrderCacheImpl::cancelOrder(const std::string& orderId) {
	std::lock_guard<std::mutex> guard(m_mutex);
	// If the order doesn't exist, do nothing.
	if (orderNotExist(orderId)) {
		return;
	}
	// Remove the order from the cache.
	removeTargetedFromCashe(orderId);
}

void OrderCacheImpl::cancelOrdersForUser(const std::string& user) {
	std::lock_guard<std::mutex> guard(m_mutex);
	if (userNotExist(user)) {
		return;
	}
	std::vector<std::string> ordersToRemove;
	// Collect all order IDs from the user and add them to the ordersToRemove vector.
	std::transform(m_usersOrders[user].begin(), m_usersOrders[user].end(), std::back_inserter(ordersToRemove),
		[](const std::pair<std::string, OrderPtr> pair) { return pair.first; });

	// Remove the targeted orders from the cache.
	removeTargetedFromCashe(ordersToRemove);
}

void OrderCacheImpl::cancelOrdersForSecIdWithMinimumQty(const std::string& securityId, unsigned int minQty) {
	std::lock_guard<std::mutex> guard(m_mutex);
	// If the security ID doesn't exist, do nothing.
	if (securityIDNotExist(securityId)) {
		return;
	}

	std::vector<std::string> ordersToRemove;
		
	// Collect orders from the buy side that meet the minimum quantity requirement.
	for (const auto& [orderId, orders] : m_securitiesOrders_buySell[securityId].first) {
		if (orders->qty() >= minQty) {
			ordersToRemove.push_back(orders->orderId());
		}
	}
	// Collect orders from the sell side that meet the minimum quantity requirement.
	for (const auto& [orderId, orders] : m_securitiesOrders_buySell[securityId].second) {
		if (orders->qty() >= minQty) {
			ordersToRemove.push_back(orders->orderId());
		}
	}
	// Remove the targeted orders from the cache.
	removeTargetedFromCashe(ordersToRemove);
}

unsigned int OrderCacheImpl::getMatchingSizeForSecurity(const std::string& securityId) {
	std::lock_guard<std::mutex> guard(m_mutex);
	// If the security ID doesn't exist, return 0.
	if (securityIDNotExist(securityId)) {
		return 0;
	}
	const auto& [buys, sells] = m_securitiesOrders_buySell[securityId];

	std::unordered_map<std::string, unsigned int> buyOrders;
	std::unordered_map<std::string, unsigned int> sellOrders;

	// Accumulate the quantities for buy orders by company.
	for (const auto& [id, order] : buys) {
		buyOrders[order->company()] += order->qty();
	}
	// Accumulate the quantities for sell orders by company.
	for (const auto& [id, order] : sells) {
		sellOrders[order->company()] += order->qty();
	}

	unsigned int totalMatch = 0;

	// Calculate the total matching size by comparing buy and sell orders.
	// Worst-case scenario is O(n/2).
	for (auto& [buyCompany, buyValue] : buyOrders) {
		for (auto& [sellCompany, sellValue] : sellOrders) {
			if (buyCompany == sellCompany) {
				continue;
			}
			unsigned int matchQty = std::min(buyValue, sellValue);
			totalMatch += matchQty;
			buyValue -= matchQty;
			sellValue -= matchQty;
		}
	}
	return totalMatch;
}

std::vector<Order> OrderCacheImpl::getAllOrders() const {
	std::lock_guard<std::mutex> guard(m_mutex);
	std::vector<Order> allOrders;
	// Copy all orders from the cache to the allOrders vector.
	for (const auto& pair : m_ordersByOrderId) {
		allOrders.push_back(*pair.second);
	}
	return allOrders;
}

/// <summary>
/// Removes a single order from the cache by its order ID.
/// </summary>
/// <param name="orderId">The ID of the order to remove.</param>
void OrderCacheImpl::removeOrderFromCashe(const std::string& orderId) {
	const Order& order = *(m_ordersByOrderId[orderId].get());
	const std::string& securityId = order.securityId();
	const std::string& userId = order.user();

	// Remove the order from the user's order map.
	// If the user has no more orders, remove the user from the map.
	m_usersOrders[userId].erase(orderId);
	if (m_usersOrders[userId].empty()) {
		m_usersOrders.erase(userId);
	}

	// Remove the order from the security's buy or sell map.
	// If the security has no more buy or sell orders, remove the security from the map.
	m_securitiesOrders_buySell[securityId].first.erase(orderId);
	m_securitiesOrders_buySell[securityId].second.erase(orderId);
	if (m_securitiesOrders_buySell[securityId].first.empty()) {
		if (m_securitiesOrders_buySell[securityId].second.empty()) {
			m_securitiesOrders_buySell.erase(securityId);
		}
	}

	// Finally, remove the order from the orders map.
	m_ordersByOrderId.erase(orderId);
}