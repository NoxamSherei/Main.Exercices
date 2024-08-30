#pragma once
#include "../pch.h"
#include <structures/StackVector.hpp>
#include <algorithm>
#include <random>
#include <numeric>

class StackVectorTestFixture :public ::testing::Test {
protected:
	virtual void SetUp()
	{
		std::iota(testData.begin(), testData.end(), 1);
	}

	virtual void TearDown()
	{
	}
	std::vector<int> testData = std::vector<int>(100);
	std::unique_ptr<::DataStructures::StackVector<int>> container = std::make_unique<::DataStructures::StackVector<int>>();
};

TEST_F(StackVectorTestFixture, Ctor) {
	ASSERT_NE(container.get(), nullptr);
}

TEST_F(StackVectorTestFixture, EmptyStackCheck) {
	ASSERT_TRUE(container->IsEmpty());
	container->Insert(testData.front());
	ASSERT_FALSE(container->IsEmpty());
}

TEST_F(StackVectorTestFixture, Count) {
	ASSERT_EQ(container->Count(), 0);
	container->Insert(testData.front());
	ASSERT_EQ(container->Count(), 1);
}

TEST_F(StackVectorTestFixture, Contain) {
	ASSERT_FALSE(container->Contain(testData.front()));
	container->Insert(testData.front());
	ASSERT_TRUE(container->Contain(testData.front()));
}

TEST_F(StackVectorTestFixture, Top) {
	ASSERT_EQ(container->Top(), 0);
	container->Insert(testData.front());
	ASSERT_EQ(container->Top(), testData.front());
	container->Insert(testData.at(2));
	ASSERT_EQ(container->Top(), testData.at(2));
}

TEST_F(StackVectorTestFixture, InsertOnStack) {
	ASSERT_TRUE(container->IsEmpty());
	for (int i = 0; i < testData.size(); i++) {
		const auto& elem = testData[i];

		ASSERT_FALSE(container->Contain(elem));

		container->Insert(elem);

		EXPECT_EQ(container->Top(), elem);
		EXPECT_EQ(container->Count(), i + 1);
		EXPECT_TRUE(container->Contain(elem));
		ASSERT_FALSE(container->IsEmpty());
	}
	ASSERT_EQ(container->Count(), testData.size());
}

TEST_F(StackVectorTestFixture, RemoveFromStack) {
	for (const auto& elem : testData) {
		container->Insert(elem);
	}
	ASSERT_EQ(container->Count(), testData.size());
	for (auto it = testData.rbegin(); it != testData.rend(); it++) {
		ASSERT_EQ(container->Top(), *it);
		ASSERT_TRUE(container->Contain(*it));

		container->Remove();

		ASSERT_FALSE(container->Contain(*it));
	}
}