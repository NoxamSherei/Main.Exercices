#include "BinaryTree.hpp"
#include <iostream>
#include <stack>
#include <queue>
#include <math.h>

namespace DataStructures {
	void BinaryTree::Insert(int input)
	{
		TreeNodePtr* currentNode = &root;
		TreeNodePtr* prevNode = nullptr;
		while (true) {
			prevNode = currentNode;
			if (!*currentNode) {
				*currentNode = std::make_unique<TreeNode>(input);
				size++;
				break;
			}
			if ((*currentNode)->data <= input) {
				currentNode = &(*prevNode)->left;
			}
			else {
				currentNode = &(*prevNode)->right;
			}
		}
	}

	int BinaryTree::Root() const
	{
		if (IsEmpty()) {
			return NULL;
		}
		return root->data;
	}

	const bool BinaryTree::Contain(int input)
	{
		if (IsEmpty()) {
			return false;
		}
		TreeNodePtr* currentNode = &root;
		TreeNodePtr* prevNode = nullptr;
		while (currentNode) {
			if ((*currentNode)->data == input) {
				return true;
			}
			prevNode = currentNode;
			if ((*currentNode)->data <= input) {
				currentNode = &root->left;
			}
			else {
				currentNode = &root->right;
			}
		}
		return false;
	}

	const size_t BinaryTree::Depth() const
	{
		if (IsEmpty()) {
			return 0;
		}
		return DFSDepth();
	}

	const size_t BinaryTree::Count() const
	{
		return size;
	}

	std::string BinaryTree::ToString() const
	{
		std::ostringstream os;
		os << "root:" << root->data << std::endl;
		PrintDeeper(os, &root->left, 1, true);
		PrintDeeper(os, &root->right, 1, false);
		return os.str();
	}
	void BinaryTree::PrintDeeper(std::ostringstream& os, TreeNodePtr* currentNode, int&& deep, bool isleft) const {
		if (!currentNode) {
			return;
		}
		std::string s = isleft ? "L:" : "R:";
		os << std::string(deep, '|') << '-' << s << (*currentNode)->data << std::endl;

		PrintDeeper(os, &(*currentNode)->left, deep + 1, true);
		PrintDeeper(os, &(*currentNode)->right, deep + 1, false);
	}
	const size_t BinaryTree::DFSDepth() const {
		int maxDeep = 1;
		std::stack<std::pair<const TreeNodePtr*, int>> check;
		check.push({ &root,1});
		while (!check.empty()) {
			auto [currentNode, depth] = check.top();
			check.pop();
			maxDeep = std::max(maxDeep, depth);
			if ((*currentNode)->left) {
				check.push({ &(*currentNode)->left,depth + 1 });
			}
			if ((*currentNode)->right) {
				check.push({ &(*currentNode)->right,depth + 1 });
			}
		}
		return maxDeep;
	}
	const size_t BinaryTree::BFSDepth() const {
		int maxDeep = 1;
		std::queue<std::pair<const TreeNodePtr*, int >> check;
		check.push({ &root,1 });
		while (!check.empty()) {
			auto [currentNode, depth] = check.front();
			check.pop();
			maxDeep = std::max(maxDeep, depth);
			if ((*currentNode)->left) {
				check.push({ &(*currentNode)->left,depth + 1 });
			}
			if ((*currentNode)->right) {
				check.push({ &(*currentNode)->right,depth + 1 });
			}
		}
		return maxDeep;
	}
	const bool BinaryTree::IsEmpty() const {
		return Count() == 0;
	}
}