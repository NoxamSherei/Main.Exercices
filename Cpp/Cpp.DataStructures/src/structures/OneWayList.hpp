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
		void Push(int input) override;
		void PushFront(int input) override;
		void PushBack(int input) override;
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