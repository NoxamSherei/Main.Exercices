#pragma once
#include <memory>

namespace DataStructures {
	namespace Nodes {
		template<typename TData>
		class TreeNode {
		public:
			std::shared_ptr<TreeNode<TData>> left;
			std::shared_ptr<TreeNode<TData>> right;
			std::weak_ptr<TreeNode<TData>> root;
			TData data;
			TreeNode(std::shared_ptr<TreeNode<TData>> root, TData data) :
				root(root),
				data(data) {
			}
		};
	}
}