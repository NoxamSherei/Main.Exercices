#pragma once
#include "interfaces/ITree.hpp"
#include <string>
#include <sstream>
#include <algorithm>

namespace DataStructures {
	class BinaryTree :public ITree<int> {
	private:
		struct TreeNode;
		using TreeNodePtr = std::unique_ptr<TreeNode>;
	
		struct TreeNode {
			TreeNodePtr left;
			TreeNodePtr right;
			int data;
			TreeNode(int data) :
				data(data) {
			}
		};
	
		TreeNodePtr root;
		size_t size = 0;
		void PrintDeeper(std::ostringstream& os, TreeNodePtr* currentNode, int&& deep, bool isleft) const;
	public:
		BinaryTree() = default;
		~BinaryTree() = default;
		const size_t DFSDepth() const;
		const size_t BFSDepth() const;
		// Inherited via ITree
		void Insert(int input);
		int Root() const;
		const bool Contain(int input);
		const size_t Depth() const;
		const size_t Count() const;
		const bool IsEmpty() const;
		std::string Print() const;
	};
}