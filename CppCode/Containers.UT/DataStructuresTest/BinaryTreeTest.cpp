#pragma once
#include "../pch.h"
#include <structures/BinaryTree.hpp>

class BinaryTreeTestFixture :public ::testing::Test {
protected:
	std::vector<int> testData;
	std::unique_ptr<::DataStructures::BinaryTree> container = std::make_unique<::DataStructures::BinaryTree>();
};

TEST_F(BinaryTreeTestFixture, Ctor) {
	ASSERT_NE(container.get(), nullptr);
}

TEST_F(BinaryTreeTestFixture, InsertOperation) {
	ASSERT_TRUE(container->IsEmpty());

	testData = { 2,1,3 };
	auto it = testData.begin();
	container->Insert(*it);

	EXPECT_EQ(container->Depth(), 1);
	EXPECT_EQ(container->Count(), 1);
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