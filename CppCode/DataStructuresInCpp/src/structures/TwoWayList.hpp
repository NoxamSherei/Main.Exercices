#pragma once
#include "nodes/TwoWayNode.hpp"
#include "interfaces/ITwoWayList.hpp"
#include <string>

namespace DataStructures {
	class TwoWayList : public ITwoWayList<int> {
	private:
		std::shared_ptr<Nodes::TwoWayNode<int>> start;
		std::shared_ptr<Nodes::TwoWayNode<int>> end;
		size_t size=0;
	public:
		TwoWayList() = default;
		~TwoWayList() = default;
		// Inherited via IList
		void Insert(int input) override;
		void InsertFront(int input) override;
		void InsertBack(int input) override;
		bool PopFront() override;
		bool PopBack() override;
		bool Pop(int input) override;
		int Top() const override;
		bool Contain(int input) override;
		size_t Count() const override;
		bool IsEmpty() const override;
		std::string Print() const override;
	};
}