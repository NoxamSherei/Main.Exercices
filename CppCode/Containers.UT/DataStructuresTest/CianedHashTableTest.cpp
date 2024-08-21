#pragma once
#include "../pch.h"
#include <Structures/ChainedHashTable.hpp>
#include <algorithm>
#include <random>
#include <numeric>

class ChainedHashTableFixture :public ::testing::Test {
protected:
	virtual void SetUp()
	{
		std::stringstream ss(sentence);
		std::string word;
		while (ss >> word) {
			testData.push_back(word);
		}
	}
	std::string sentence = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.";
	std::vector<std::string> testData;
	std::unique_ptr<::DataStructures::ChainedHashTable> container = std::make_unique<::DataStructures::ChainedHashTable>();
};

TEST_F(ChainedHashTableFixture, Ctor) {
	ASSERT_NE(container.get(), nullptr);
}

TEST_F(ChainedHashTableFixture, EmptyhashTableCheck) {
	ASSERT_TRUE(container->IsEmpty());
	container->Insert(testData.front());
	ASSERT_FALSE(container->IsEmpty());
}

TEST_F(ChainedHashTableFixture, Count) {
	ASSERT_EQ(container->Count(), 0);
	container->Insert(testData.front());
	ASSERT_EQ(container->Count(), 1);
}

TEST_F(ChainedHashTableFixture, Contain) {
	ASSERT_FALSE(container->Contain(testData.front()));
	container->Insert(testData.front());
	ASSERT_TRUE(container->Contain(testData.front()));
}

TEST_F(ChainedHashTableFixture, InsertOnhashTable) {
	ASSERT_TRUE(container->IsEmpty());
	for (int i = 0; i < testData.size(); i++) {
		const auto& elem = testData[i];

		container->Insert(elem);

		EXPECT_EQ(container->Count(), i + 1);
		EXPECT_TRUE(container->Contain(elem));
		ASSERT_FALSE(container->IsEmpty());
	}
	ASSERT_EQ(container->Count(), testData.size());
}