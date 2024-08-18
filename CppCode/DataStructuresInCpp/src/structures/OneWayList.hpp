#pragma once
#include "nodes/OneWayNode.hpp"
#include "interfaces/IOneWayList.hpp"
#include <string>

namespace DataStructures {
	class OneWayList : public IOneWayList<int> {
	private:
		std::shared_ptr<Nodes::OneWayNode<int>> start;
		std::shared_ptr<Nodes::OneWayNode<int>> end;
		size_t size=0;
	public:
		OneWayList() = default;
		~OneWayList() = default;
		// Inherited via IList
		void Insert(int input) override;
		void InsertFront(int input) override;
		void InsertBack(int input) override;
		const bool PopFront() override;
		const bool PopBack() override;
		const bool Pop(int input) override;
		int Top() const override;
		const bool Contain(int input) override;
		const size_t Count() const override;
		const bool IsEmpty() const override;
		std::string Print() const override;
	};
}