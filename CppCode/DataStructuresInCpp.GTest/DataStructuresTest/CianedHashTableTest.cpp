#include "../pch.h"
#include <structures/ChainedHashTable.cpp>//todo: find way to fix, problem with static lib
#include <algorithm>
#include <random>
#include <numeric>

class ChainedHashTableFixture :public ::testing::Test {
protected:
	virtual void SetUp()
	{
		std::string sentence = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.";
		
		std::stringstream ss(sentence);
		std::string word;
		while (ss >> word) {
			testData.push_back(word);
		}
	}

	virtual void TearDown()
	{
	}
	
	std::vector<std::string> testData;
	::DataStructures::ChainedHashTable hashTable;
};

TEST_F(ChainedHashTableFixture, EmptyhashTableCheck) {
	ASSERT_TRUE(hashTable.IsEmpty());
	hashTable.Insert(testData.front());
	ASSERT_FALSE(hashTable.IsEmpty());
}

TEST_F(ChainedHashTableFixture, Count) {
	ASSERT_EQ(hashTable.Count(), 0);
	hashTable.Insert(testData.front());
	ASSERT_EQ(hashTable.Count(), 1);
}

TEST_F(ChainedHashTableFixture, Contain) {
	ASSERT_FALSE(hashTable.Contain(testData.front()));
	hashTable.Insert(testData.front());
	ASSERT_TRUE(hashTable.Contain(testData.front()));
}

TEST_F(ChainedHashTableFixture, InsertOnhashTable) {
	ASSERT_TRUE(hashTable.IsEmpty());
	for (int i = 0; i < testData.size(); i++) {
		const auto& elem = testData[i];

		hashTable.Insert(elem);

		EXPECT_EQ(hashTable.Count(), i + 1);
		EXPECT_TRUE(hashTable.Contain(elem));
		ASSERT_FALSE(hashTable.IsEmpty());
	}
	ASSERT_EQ(hashTable.Count(), testData.size());
}