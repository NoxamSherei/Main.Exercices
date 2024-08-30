#pragma once
#include "../pch.h"
#include <structures/BinaryTreeRaw.hpp>
#include <stack>


class BinaryTreeRawTestFixture :public ::testing::Test {
protected:
	std::vector<int> testData;
	std::unique_ptr<::DataStructures::RawBinaryTree<int>> container = std::make_unique<::DataStructures::RawBinaryTree<int>>();
};

TEST_F(BinaryTreeRawTestFixture, Ctor) {
	ASSERT_NE(container.get(), nullptr);
}

TEST_F(BinaryTreeRawTestFixture, InsertOperation) {
	ASSERT_TRUE(container->IsEmpty());

	testData = { 2,1,3 };
	auto it = testData.begin();
	container->Insert(*it);

	EXPECT_EQ(container->Depth(),1);
	EXPECT_EQ(container->Count(),1);
	ASSERT_FALSE(container->IsEmpty());
	it++;
	container->Insert(*it);

	EXPECT_EQ(container->Depth(), 2);
	EXPECT_EQ(container->Count(), 2);
	ASSERT_FALSE(container->IsEmpty());
	it++;
	container->Insert(*it);

	EXPECT_EQ(container->Depth(), 2);
	EXPECT_EQ(container->Count(), 3);
	ASSERT_FALSE(container->IsEmpty());
}

TEST(NameOfTheSolutionOrSuite, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
	ASSERT_EQ(1, 1);
	ASSERT_TRUE(true);
}