#pragma once
#include <memory>
#include <iostream>

namespace DataStructures {
	namespace Nodes {
		template<typename TData>
		class OneWayNode {
		public:
			std::shared_ptr<OneWayNode<TData>> next;
			TData data;
			OneWayNode(TData data) :data(data) {}
			~OneWayNode() {}
		};
	}
}