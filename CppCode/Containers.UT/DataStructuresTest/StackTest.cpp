#pragma once
#include "../pch.h"
#include <structures/StackVector.hpp>
#include <algorithm>
#include <random>
#include <numeric>

class StackDataStructureTestFixture :public ::testing::Test {
protected:
	virtual void SetUp()
	{
		std::iota(testData.begin(), testData.end(), 1);
	}

	virtual void TearDown()
	{
	}
	std::vector<int> testData = std::vector<int>(100);
	::DataStructures::StackVector<int> stack;
};

TEST_F(StackDataStructureTestFixture, EmptyStackCheck) {
	ASSERT_TRUE(stack.IsEmpty());
	stack.Insert(testData.front());
	ASSERT_FALSE(stack.IsEmpty());
}

TEST_F(StackDataStructureTestFixture, Count) {
	ASSERT_EQ(stack.Count(), 0);
	stack.Insert(testData.front());
	ASSERT_EQ(stack.Count(), 1);
}

TEST_F(StackDataStructureTestFixture, Contain) {
	ASSERT_FALSE(stack.Contain(testData.front()));
	stack.Insert(testData.front());
	ASSERT_TRUE(stack.Contain(testData.front()));
}

TEST_F(StackDataStructureTestFixture, Top) {
	ASSERT_EQ(stack.Top(), 0);
	stack.Insert(testData.front());
	ASSERT_EQ(stack.Top(), testData.front());
}

TEST_F(StackDataStructureTestFixture, InsertOnStack) {
	ASSERT_TRUE(stack.IsEmpty());
	for (int i = 0; i < testData.size(); i++) {
		const auto& elem = testData[i];

		ASSERT_FALSE(stack.Contain(elem));

		stack.Insert(elem);

		EXPECT_EQ(stack.Top(), elem);
		EXPECT_EQ(stack.Count(), i + 1);
		EXPECT_TRUE(stack.Contain(elem));
		ASSERT_FALSE(stack.IsEmpty());
	}
	ASSERT_EQ(stack.Count(), testData.size());
}

TEST_F(StackDataStructureTestFixture, PopFromStack) {
	for (const auto& elem : testData) {
		stack.Insert(elem);
	}
	ASSERT_EQ(stack.Count(), testData.size());
	for (auto it = testData.rbegin(); it != testData.rend(); it++) {
		ASSERT_EQ(stack.Top(), *it);
		ASSERT_TRUE(stack.Contain(*it));

		stack.Pop();

		ASSERT_FALSE(stack.Contain(*it));
	}
}