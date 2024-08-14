#pragma once
#include "nodes/TreeNode.hpp"
#include "interfaces/ITree.hpp"
#include <string>
#include <sstream>

namespace DataStructures {
	using namespace Nodes;
	class BinaryTree :public ITree<int> {
	private:
		std::shared_ptr<TreeNode<int>> root;
		size_t size = 0;
		void PrintDeeper(std::ostringstream& os, std::shared_ptr < TreeNode<int>> currentNode, int&& deep, bool isleft) const;
	public:
		BinaryTree() = default;
		~BinaryTree() = default;
		// Inherited via ITree
		void Push(int input);
		int Top() const;
		bool Contain(int input);
		size_t Depth() const;
		size_t DFSDepth() const;
		size_t BFSDepth() const;
		size_t Count() const;
		std::string Print() const;
		bool IsEmpty() const;
	};
}