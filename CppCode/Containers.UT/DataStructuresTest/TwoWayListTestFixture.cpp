#pragma once
#include "../pch.h"
#include <structures/TwoWayListRawPointer.hpp>
#include <algorithm>
#include <random>
#include <numeric>

class TwoWayListTestFixture :public ::testing::Test {
protected:
	std::vector<int> testData;
	std::unique_ptr<::DataStructures::TwoWayListRawPointer<int>> container = std::make_unique<::DataStructures::TwoWayListRawPointer<int>>();
};

TEST_F(TwoWayListTestFixture, Ctor) {
	ASSERT_NE(container.get(), nullptr);
}

TEST_F(TwoWayListTestFixture, Insert) {
	testData = { 1,2,3,4,5 };

	std::for_each(testData.begin(), testData.end(), [&](const int& elem) {container->Insert(elem); });
	EXPECT_EQ(container->Count(), 5);
	ASSERT_EQ(container->ToString(), "List{size:5,content:[1][2][3][4][5]}");

	std::for_each(testData.begin(), testData.end(), [&](const int& elem) {container->InsertFront(elem); });
	EXPECT_EQ(container->Count(), 10);
	ASSERT_EQ(container->ToString(), "List{size:10,content:[5][4][3][2][1][1][2][3][4][5]}");

	std::for_each(testData.begin(), testData.end(), [&](const int& elem) {container->InsertBack(elem); });
	EXPECT_EQ(container->Count(), 15);
	ASSERT_EQ(container->ToString(), "List{size:15,content:[5][4][3][2][1][1][2][3][4][5][1][2][3][4][5]}");
}

TEST_F(TwoWayListTestFixture, Remove) {
	testData = { 1,2,3,4,5 };
	std::for_each(testData.begin(), testData.end(), [&](const int& elem) {container->Insert(elem); });
	EXPECT_EQ(container->Count(), 5);
	ASSERT_EQ(container->ToString(), "List{size:5,content:[1][2][3][4][5]}");

	EXPECT_TRUE(container->RemoveBack());
	EXPECT_EQ(container->Count(), 4);
	ASSERT_EQ(container->ToString(), "List{size:4,content:[1][2][3][4]}");

	EXPECT_TRUE(container->RemoveFront());
	EXPECT_EQ(container->Count(), 3);
	ASSERT_EQ(container->ToString(), "List{size:3,content:[2][3][4]}");

	EXPECT_TRUE(container->Remove());
	EXPECT_EQ(container->Count(), 2);
	ASSERT_EQ(container->ToString(), "List{size:2,content:[2][3]}");

	EXPECT_TRUE(container->Remove());
	EXPECT_EQ(container->Count(), 1);
	ASSERT_EQ(container->ToString(), "List{size:1,content:[2]}");

	EXPECT_TRUE(container->Remove());
	EXPECT_EQ(container->Count(), 0);
	ASSERT_EQ(container->ToString(), "List{size:0,content:}");
}