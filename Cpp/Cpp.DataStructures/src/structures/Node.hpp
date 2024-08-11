#pragma once
#include <memory>

namespace DataStructures {
	template<typename TData>
	class Node {
	public:
		std::shared_ptr<Node<TData>> left;
		std::shared_ptr<Node<TData>> right;
		std::weak_ptr<Node<TData>> root;
		TData data;
		Node(std::shared_ptr<Node<TData>> root, TData data) :
			root(root),
			data(data) {
		}
	};
}