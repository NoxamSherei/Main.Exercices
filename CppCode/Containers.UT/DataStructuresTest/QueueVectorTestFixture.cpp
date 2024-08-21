#pragma once
#include "../pch.h"
#include <structures/QueueVector.hpp>
#include <algorithm>
#include <random>
#include <numeric>

class QueueVectorTestFixture :public ::testing::Test {
protected:
	virtual void SetUp()
	{
		std::iota(testData.begin(), testData.end(), 1);
	}
	std::vector<int> testData = std::vector<int>(100);
	std::unique_ptr<::DataStructures::QueueVector<int>> container = std::make_unique<::DataStructures::QueueVector<int>>();
};

TEST_F(QueueVectorTestFixture, Ctor) {
	ASSERT_NE(container.get(), nullptr);
}

TEST_F(QueueVectorTestFixture, EmptyQueueCheck) {
	ASSERT_TRUE(container->IsEmpty());
	container->Insert(testData.front());
	ASSERT_FALSE(container->IsEmpty());
}

TEST_F(QueueVectorTestFixture, Count) {
	ASSERT_EQ(container->Count(), 0);
	container->Insert(testData.front());
	ASSERT_EQ(container->Count(), 1);
}

TEST_F(QueueVectorTestFixture, Contain) {
	ASSERT_FALSE(container->Contain(testData.front()));
	container->Insert(testData.front());
	ASSERT_TRUE(container->Contain(testData.front()));
}

TEST_F(QueueVectorTestFixture, Top) {
	ASSERT_EQ(container->Top(), 0);
	container->Insert(testData.front());
	ASSERT_EQ(container->Top(), testData.front());
	container->Insert(testData.at(2));
	ASSERT_EQ(container->Top(), testData.front());
}

TEST_F(QueueVectorTestFixture, InsertOnQueue) {
	ASSERT_TRUE(container->IsEmpty());
	for (int i = 0; i < testData.size(); i++) {
		const auto& elem = testData[i];

		ASSERT_FALSE(container->Contain(elem));

		container->Insert(elem);

		EXPECT_EQ(container->Top(), testData.front());
		EXPECT_EQ(container->Count(), i + 1);
		EXPECT_TRUE(container->Contain(elem));
		ASSERT_FALSE(container->IsEmpty());
	}
	ASSERT_EQ(container->Count(), testData.size());
}

TEST_F(QueueVectorTestFixture, PopFromQueue) {
	for (const auto& elem : testData) {
		container->Insert(elem);
	}
	ASSERT_EQ(container->Count(), testData.size());
	for (auto it = testData.begin(); it != testData.end(); it++) {
		ASSERT_EQ(container->Top(), *it);
		ASSERT_TRUE(container->Contain(*it));

		container->Pop();

		ASSERT_FALSE(container->Contain(*it));
	}
}