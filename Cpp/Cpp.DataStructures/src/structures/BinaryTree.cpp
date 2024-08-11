#include "BinaryTree.hpp"
namespace DataStructures {
	void BinaryTree::Push(int input)
	{
		std::shared_ptr<Node<int>> currentNode = root;
		std::shared_ptr<Node<int>> prevNode = nullptr;
		while (true) {
			if (!currentNode) {
				currentNode = std::make_shared<Node<int>>(prevNode, input);
				size++;
				break;
			}
			prevNode = currentNode;
			if (currentNode->data <= input) {
				currentNode = root->left;
			}
			else {
				currentNode = root->right;
			}
		}
	}

	int BinaryTree::Top() const
	{
		if (IsEmpty()) {
			return NULL;
		}
		return root->data;
	}

	bool BinaryTree::Contain(int input)
	{
		if (IsEmpty()) {
			return false;
		}
		std::shared_ptr<Node<int>> currentNode = root;
		std::shared_ptr<Node<int>> prevNode = nullptr;
		while (currentNode) {
			if (currentNode->data == input) {
				return true;
			}
			prevNode = currentNode;
			if (currentNode->data <= input) {
				currentNode = root->left;
			}
			else {
				currentNode = root->right;
			}
		}
		return false;
	}

	size_t BinaryTree::Deep() const
	{
		return size;
	}

	size_t BinaryTree::Count() const
	{
		return size;
	}

	std::string BinaryTree::Print() const
	{
		std::ostringstream os;
		os << "root:" << root->data << std::endl;
		PrintDeeper(os, root->left, 1, true);
		PrintDeeper(os, root->right, 1, false);
		return os.str();
	}
	void BinaryTree::PrintDeeper(std::ostringstream& os, std::shared_ptr < Node<int>> currentNode, int&& deep, bool isleft) const {
		if (!currentNode) {
			return;
		}
		std::string s = isleft ? "L:" : "R:";
		os << std::string(deep, '|') << '-' << s << currentNode->data << std::endl;

		PrintDeeper(os, currentNode->left, deep + 1, true);
		PrintDeeper(os, currentNode->right, deep + 1, false);
	}
	bool BinaryTree::IsEmpty() const {
		return Count() == 0;
	}
}