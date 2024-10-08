#pragma once
#include "Interfaces/IList.hpp"
#include "sstream"

namespace DataStructures {
	template<typename TData>
	class TwoWayListRawPointer :public IList<TData> {
	private:
		struct Node {
			Node* next = nullptr;
			Node* back = nullptr;
			TData value = TData();
			Node(Node* back, TData value) : back(back), value(value) {
			}
			~Node() {
				delete next;
				back = nullptr;
			}
			bool IsEqual(TData input) {
				return input == value;
			}
		};
		Node* front = nullptr;
		Node* end = nullptr;
		size_t size = 0;
		void InsertFirst(TData input) {
			end = front = new Node(nullptr, input);
			size++;
		}
		void RemoveLast() {
			delete front;
			end = front = nullptr;
			size--;
		}
	public:
		virtual void Insert(TData input) override {
			InsertBack(input);
		}
		virtual void InsertBack(TData input) override {
			if (IsEmpty()) {
				InsertFirst(input);
				return;
			}
			auto newNode = new Node(end, input);
			end->next = newNode;
			end = newNode;
			size++;
		}
		virtual void InsertFront(TData input) override {
			if (IsEmpty()) {
				InsertFirst(input);
				return;
			}
			auto newNode = new Node(nullptr, input);
			front->back = newNode;
			newNode->next = front;
			front = newNode;
			size++;
		}
		virtual const bool Remove() override {
			return RemoveBack();
		}
		virtual const bool RemoveBack() override {
			if (IsEmpty()) {
				return false;
			}
			if (Count() == 1) {
				RemoveLast();
				return true;
			}
			auto node = end;
			end = node->back;
			end->next = nullptr;
			delete node;
			size--;
			return true;
		}
		virtual const bool RemoveFront() override {
			if (IsEmpty()) {
				return false;
			}
			if (Count() == 1) {
				RemoveLast();
				return true;
			}
			auto node = front;
			front = node->next;
			front->back = nullptr;
			node->next = nullptr;
			delete node;
			size--;
			return true;
		}
		virtual const bool Contain(TData input) override {
			if (IsEmpty()) {
				return false;
			}
			if (front->IsEqual(input) || end->IsEqual(input))
			{
				return true;
			}
			auto currentNode = front->next;
			while (currentNode != end) {
				if (currentNode->IsEqual(input))
				{
					return true;
				}
			}
			return false;
		}
		virtual std::string ToString() const override {
			std::ostringstream os;
			os << "List{size:"<<size<<",content:";
			auto currentNode = front;
			while (currentNode != nullptr) {
				os << "[" << currentNode->value << "]";
				currentNode = currentNode->next;
			}
			os << "}";
			return os.str();
		}
		virtual const bool IsEmpty() const override {
			return front == nullptr;
		}
		virtual const size_t Count() const override {
			return size;
		}
	};
}