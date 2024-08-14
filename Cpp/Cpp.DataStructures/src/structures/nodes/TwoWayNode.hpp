#pragma once
#include <memory>

namespace DataStructures {
	namespace Nodes {
		template<typename TData>
		class TwoWayNode {
		public:
			std::shared_ptr<TwoWayNode<TData>> next;
			std::weak_ptr<TwoWayNode<TData>> prev;
			TData data;
			TwoWayNode(std::shared_ptr<TwoWayNode<TData>> prev, TData data) :prev(prev), data(data) {}
			TwoWayNode(TData data) : data(data) {}
		};
	}
}