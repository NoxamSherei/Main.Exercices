#pragma once
#include "OrderCache.h"
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <mutex>

class OrderCacheImpl : public OrderCacheInterface {
private:
	// I used 'using' to create type aliases for specific types to improve code
	// readability and make it easier to navigate through the code.
	// Type alias for a pointer to an Order object, using std::shared_ptr to manage shared resources.
	using OrderPtr = std::shared_ptr<Order>;
	// Type alias for an unordered_map that maps order IDs (std::string) to pointers to Order objects (OrderPtr).
	using OrderMap = std::unordered_map<std::string, OrderPtr>;
	// Type alias for a pair of two OrderMaps, where the first element stores "Buy" orders and the second stores "Sell" orders.
	using BuySellOrderMap = std::pair<OrderMap, OrderMap>;
	
	// mutable mutex to protect the class operation when working on multiple threads.
	// mutable allow update mutex in const funtions
	mutable std::mutex m_mutex;

	//I decided to store the orders in three unordered_maps to achieve O(1) time complexity for both access and modification.
	//hold orders by order ID
	std::unordered_map<std::string, OrderPtr> m_ordersByOrderId;
	//hold pair colections of buy orders and sell orders by security ID
	std::unordered_map<std::string, BuySellOrderMap> m_securitiesOrders_buySell;
	//hold colection of orders by user ID
	std::unordered_map<std::string, OrderMap> m_usersOrders;
public:
	/// <summary>
	/// Checks if there are no securities or users with empty orders.
	/// Function mainly for testing
	/// </summary>
	const bool noEmptySecurityAndUser() const ;

	// Checks if an order does not exist in the order cache by its ID.
	inline const bool orderNotExist(const std::string& orderId) const;

	// Checks if an order has the correct format (i.e., quantity is not zero and side is either "Buy" or "Sell").
	inline const bool orderHasCorrectFormat(const Order& order) const;

	// Checks if a user does not exist in the user orders map by their user name.
	inline const bool userNotExist(const std::string& userName) const;

	// Checks if a security ID does not exist in the securities orders map.
	inline const bool securityIDNotExist(const std::string& securityId) const;

	// Inherited via OrderCacheInterface
	void addOrder(Order order) ;
	void cancelOrder(const std::string& orderId) ;
	void cancelOrdersForUser(const std::string& user) ;
	void cancelOrdersForSecIdWithMinimumQty(const std::string& securityId, unsigned int minQty) ;
	unsigned int getMatchingSizeForSecurity(const std::string& securityId) ;
	std::vector<Order> getAllOrders() const ;
private:
	/// <summary>
	/// I Add this function to simplify code and update readability, this inline function decide if use
	/// single order remove operation or need to use 
	/// </summary>
	/// <typeparam name="TTargeted">
	/// in this case can be std::string or std::vector.
	/// if we decide use other collection like list, set in future it still will work</typeparam>
	/// <param name="target">is element or collection of elements to remove</param>
	template<typename TTargeted>
	inline void removeTargetedFromCashe(TTargeted target) {
		// If the target is a single order ID (std::string), remove it.
		if constexpr (std::is_same_v<TTargeted, std::string>) {
			removeOrderFromCashe(target);
		}
		// If the target is a collection of order IDs, remove each one.
		else
		{
			for (const auto& orderId : target) {
				removeOrderFromCashe(orderId);
			}
		}
	}

	/// <summary>
	/// Removes a single order from the cache by its order ID.
	/// </summary>
	/// <param name="orderId">The ID of the order to remove.</param>
	void removeOrderFromCashe(const std::string& orderId) ;
};
