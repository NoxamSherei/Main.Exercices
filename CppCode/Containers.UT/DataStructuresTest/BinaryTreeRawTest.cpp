#pragma once
#include "../pch.h"
#include <structures/BinaryTreeRaw.hpp>

class BinaryTreeRawTestFixture :public ::testing::Test {
protected:
	virtual void SetUp()
	{
		
	}

	std::vector<int> testData;
	::DataStructures::RawBinaryTree<int> tree;
};

TEST_F(BinaryTreeRawTestFixture, InsertOperation) {
	ASSERT_TRUE(tree.IsEmpty());

	testData = { 2,1,3 };
	auto it = testData.begin();
	tree.Insert(*it);

	EXPECT_EQ(tree.Depth(),1);
	EXPECT_EQ(tree.Count(),1);
	ASSERT_FALSE(tree.IsEmpty());
	it++;
	tree.Insert(*it);

	EXPECT_EQ(tree.Depth(), 2);
	EXPECT_EQ(tree.Count(), 2);
	ASSERT_FALSE(tree.IsEmpty());
	it++;
	tree.Insert(*it);

	EXPECT_EQ(tree.Depth(), 2);
	EXPECT_EQ(tree.Count(), 3);
	ASSERT_FALSE(tree.IsEmpty());
}