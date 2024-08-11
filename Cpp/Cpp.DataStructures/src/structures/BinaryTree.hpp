#pragma once
#include "Node.hpp"
#include "interfaces/ITree.hpp"
#include <string>
#include <sstream>

namespace DataStructures {

	class BinaryTree :public ITree<int> {
	private:
		std::shared_ptr<Node<int>> root;
		size_t size = 0;
		void PrintDeeper(std::ostringstream& os, std::shared_ptr < Node<int>> currentNode, int&& deep, bool isleft) const;
	public:
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