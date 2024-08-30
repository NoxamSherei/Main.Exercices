#pragma once
#include "..\pch.h"
#include <OrderCatche\OrderCacheImpl.hpp>
#include <unordered_map>
#include <algorithm>

class OrderCatcheTestFixture : public ::testing::Test {
public:
	void SetUp() {
		orderCache = std::make_shared<OrderCacheImpl>();
	}
	void TearDown() {
		vec_orders.clear();
		orderCache.reset();
	}
	std::vector<Order*> vec_orders;
	std::shared_ptr<OrderCacheInterface> orderCache;
};

TEST_F(OrderCatcheTestFixture, Example1) {
	vec_orders = {
			new Order("OrdId1", "SecId1", "Buy", 1000, "User1", "CompanyA"),
			new Order("OrdId2", "SecId2", "Sell", 3000, "User2", "CompanyB"),
			new Order("OrdId3", "SecId1", "Sell", 500, "User3", "CompanyA"),
			new Order("OrdId4", "SecId2", "Buy", 600, "User4", "CompanyC"),
			new Order("OrdId5", "SecId2", "Buy", 100, "User5", "CompanyB"),
			new Order("OrdId6", "SecId3", "Buy", 1000, "User6", "CompanyD"),
			new Order("OrdId7", "SecId2", "Buy", 2000, "User7", "CompanyE"),
			new Order("OrdId8", "SecId2", "Sell", 5000, "User8", "CompanyE")
	};
	for (auto elem : vec_orders) {
		orderCache->AddOrder(*elem);
	}
	auto expectedMatch1 = 0;
	auto expectedMatch2 = 2700;
	auto expectedMatch3 = 0;
	EXPECT_EQ(orderCache->GetMatchingSizeForSecurity("SecId1"), expectedMatch1);
	EXPECT_EQ(orderCache->GetMatchingSizeForSecurity("SecId2"), expectedMatch2);
	ASSERT_EQ(orderCache->GetMatchingSizeForSecurity("SecId3"), expectedMatch3);
}
TEST_F(OrderCatcheTestFixture, Example2) {
	vec_orders = {
		new Order("OrdId1", "SecId1", "Sell", 100, "User10", "Company2"),
		new Order("OrdId2", "SecId3", "Sell", 200, "User8", "Company2"),
		new Order("OrdId3", "SecId1", "Buy", 300, "User13", "Company2"),
		new Order("OrdId4", "SecId2", "Sell", 400, "User12", "Company2"),
		new Order("OrdId5", "SecId3", "Sell", 500, "User7", "Company2"),
		new Order("OrdId6", "SecId3", "Buy", 600, "User3", "Company1"),
		new Order("OrdId7", "SecId1", "Sell", 700, "User10", "Company2"),
		new Order("OrdId8", "SecId1", "Sell", 800, "User2", "Company1"),
		new Order("OrdId9", "SecId2", "Buy", 900, "User6", "Company2"),
		new Order("OrdId10", "SecId2", "Sell", 1000, "User5", "Company1"),
		new Order("OrdId11", "SecId1", "Sell", 1100, "User12", "Company2"),
		new Order("OrdId12", "SecId2", "Buy", 1200, "User9", "Company2"),
		new Order("OrdId13", "SecId1", "Sell", 1300, "User1", "Company2"),
	};
	for (auto elem : vec_orders) {
		orderCache->AddOrder(*elem);
	}
	auto expectedMatch1 = 300;
	auto expectedMatch2 = 1000;
	auto expectedMatch3 = 600;
	EXPECT_EQ(orderCache->GetMatchingSizeForSecurity("SecId1"), expectedMatch1);
	EXPECT_EQ(orderCache->GetMatchingSizeForSecurity("SecId2"), expectedMatch2);
	ASSERT_EQ(orderCache->GetMatchingSizeForSecurity("SecId3"), expectedMatch3);
}
TEST_F(OrderCatcheTestFixture, Example3) {
	vec_orders = {
		new Order("OrdId1", "SecId3", "Sell", 100, "User1", "Company1"),
		new Order("OrdId2", "SecId3", "Sell", 200, "User3", "Company2"),
		new Order("OrdId3", "SecId1", "Buy", 300, "User2", "Company1"),
		new Order("OrdId4", "SecId3", "Sell", 400, "User5", "Company2"),
		new Order("OrdId5", "SecId2", "Sell", 500, "User2", "Company1"),
		new Order("OrdId6", "SecId2", "Buy", 600, "User3", "Company2"),
		new Order("OrdId7", "SecId2", "Sell", 700, "User1", "Company1"),
		new Order("OrdId8", "SecId1", "Sell", 800, "User2", "Company1"),
		new Order("OrdId9", "SecId1", "Buy", 900, "User5", "Company2"),
		new Order("OrdId10", "SecId1", "Sell", 1000, "User1", "Company1"),
		new Order("OrdId11", "SecId2", "Sell", 1100, "User16", "Company2"),
	};
	for (auto elem : vec_orders) {
		orderCache->AddOrder(*elem);
	}
	auto expectedMatch1 = 900;
	auto expectedMatch2 = 600;
	auto expectedMatch3 = 0;
	EXPECT_EQ(orderCache->GetMatchingSizeForSecurity("SecId1"), expectedMatch1);
	EXPECT_EQ(orderCache->GetMatchingSizeForSecurity("SecId2"), expectedMatch2);
	ASSERT_EQ(orderCache->GetMatchingSizeForSecurity("SecId3"), expectedMatch3);
}

TEST_F(OrderCatcheTestFixture, CancelOrdersByOrderId) {
	vec_orders = {
		new Order("OrdId1", "SecId1", "Sell", 100, "User10", "Company2"),
		new Order("OrdId2", "SecId3", "Sell", 200, "User8", "Company2"),
		new Order("OrdId3", "SecId1", "Buy", 300, "User13", "Company2"),
	};
	for (auto elem : vec_orders) {
		orderCache->AddOrder(*elem);
	}
	{
		orderCache->CancelOrder("OrdId1");
		std::vector<Order> orders1 = orderCache->GetAllOrders();
		bool x = std::any_of(orders1.begin(), orders1.end(),
			[](const Order& elem) {return elem.OrderId() == "OrdId1"; });
		ASSERT_FALSE(x);
	}
	{
		orderCache->CancelOrder("OrdId3");
		std::vector<Order> orders1 = orderCache->GetAllOrders();
		bool x = std::any_of(orders1.begin(), orders1.end(),
			[](const Order& elem) {return elem.OrderId() == "OrdId3"; });
		ASSERT_FALSE(x);
	}
	ASSERT_TRUE(dynamic_cast<OrderCacheImpl*>(orderCache.get())->NoEmptySecurityAndUser());
}
TEST_F(OrderCatcheTestFixture, CancelOrdersBySecMin) {
	vec_orders = {
		new Order("OrdId1", "SecId1", "Sell", 100, "User10", "Company2"),
		new Order("OrdId2", "SecId3", "Sell", 200, "User8", "Company2"),
		new Order("OrdId3", "SecId1", "Buy", 300, "User13", "Company2"),
		new Order("OrdId4", "SecId2", "Sell", 400, "User12", "Company2"),
		new Order("OrdId5", "SecId3", "Sell", 500, "User7", "Company2"),
		new Order("OrdId6", "SecId3", "Buy", 600, "User3", "Company1"),
	};
	for (auto elem : vec_orders) {
		orderCache->AddOrder(*elem);
	}
	orderCache->CancelOrdersForSecIdWithMinimumQty("SecId3", 300);
	std::vector<Order> orders1 = orderCache->GetAllOrders();
	for (const auto& order : orders1) {
		if (order.SecurityId() != "SecId3") {
			continue;
		}
		if (order.Qty() < 300) {
			continue;
		}
		ASSERT_FALSE(true);
	}
	ASSERT_TRUE(dynamic_cast<OrderCacheImpl*>(orderCache.get())->NoEmptySecurityAndUser());
}

TEST_F(OrderCatcheTestFixture, CancelOrdersByUser) {
	vec_orders.clear();
	vec_orders.push_back(new Order("OrdId1", "SecId2", "Sell", 100, "User1", "Company2"));
	vec_orders.push_back(new Order("OrdId2", "SecId1", "Sell", 100, "User2", "Company2"));
	vec_orders.push_back(new Order("OrdId3", "SecId1", "Sell", 100, "User3", "Company2"));

	for (auto elem : vec_orders) {
		orderCache->AddOrder(*elem);
	}
	{
		orderCache->CancelOrdersForUser("User2");
		std::vector<Order> orders1 = orderCache->GetAllOrders();
		bool x = std::any_of(orders1.begin(), orders1.end(),
			[](const Order& elem) {return elem.User() == "User2"; });
		ASSERT_FALSE(x);
	}
	{
		orderCache->CancelOrdersForUser("User3");
		std::vector<Order> orders1 = orderCache->GetAllOrders();
		bool x = std::any_of(orders1.begin(), orders1.end(),
			[](const Order& elem) {return elem.User() == "User3"; });
		ASSERT_FALSE(x);
	}
	ASSERT_TRUE(dynamic_cast<OrderCacheImpl*>(orderCache.get())->NoEmptySecurityAndUser());
}

TEST_F(OrderCatcheTestFixture, ThreadSafe) {
	for (size_t i = 0; i < 500; i++)
	{
		std::string id = "OrdId" + std::to_string(i);
		std::string SecId = "SecId" + std::to_string((i % 4));
		std::string sell = i % 3 == 0 ? "Sell" : "Buy";
		std::string user = "User" + std::to_string((i % 7));
		std::string Company = "Company" + std::to_string((i % 7));
		vec_orders.push_back(
			new Order(id, SecId, sell, 1000 * ((i % 3) + 1), user, Company));
	}
	for (size_t i = 0; i < 250; i++)
	{
		orderCache->AddOrder(*vec_orders[i]);
	}
	std::list<std::thread> threads;

	for (size_t i = 250; i < vec_orders.size() - 50; i++)
	{
		threads.push_back(std::thread([&]() {orderCache->AddOrder(*vec_orders[i]); }));
	};
	for (size_t i = 0; i < 3; i++)
	{
		threads.push_back(std::thread([&]() {orderCache->GetMatchingSizeForSecurity((*vec_orders[i]).SecurityId()); }));

	};
	for (auto& th : threads)
	{
		th.join();
	}
}