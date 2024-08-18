#pragma once
#include "TwoWayList.hpp"
#include <sstream>

void DataStructures::TwoWayList::Insert(int input)
{
	InsertBack(input);
}

void DataStructures::TwoWayList::InsertFront(int input)
{
	auto newNode = std::make_shared<Nodes::TwoWayNode<int>>(input);
	if (!start) {
		start = newNode;
		end = newNode;
		return;
	}
	newNode->next = start;
	start->prev = newNode;
	start = newNode;
	size++;
}

void DataStructures::TwoWayList::InsertBack(int input)
{
	auto newNode = std::make_shared<Nodes::TwoWayNode<int>>(input);
	if (!start) {
		start = newNode;
		end = newNode;
		return;
	}
	end->next = newNode;
	newNode->prev = end;
	end = newNode;
	size++;
}

bool DataStructures::TwoWayList::PopFront()
{
	if (IsEmpty()) {
		return false;
	}
	if (Count() == 1) {
		start.reset();
		end.reset();
		size--;
		return true;
	}
	start = start->next;
	size--;
	return true;
}

bool DataStructures::TwoWayList::PopBack()
{
	if (IsEmpty()) {
		return false;
	}
	if (Count() == 1) {
		start.reset();
		end.reset();
		size--;
		return true;
	}
	auto current = start;
	while (current->next!=end) {
		current = current->next;
	}
	end=current;
	end->next.reset();
	size--;
	return true;
}

bool DataStructures::TwoWayList::Pop(int input)
{
	return PopBack();
}

int DataStructures::TwoWayList::Top() const
{
	return start->data;
}

bool DataStructures::TwoWayList::Contain(int input)
{
	if (start->data == input) {
		return true;
	}
	if (end->data == input) {
		return true;
	}
	auto current = start->next;
	while (current!=end) {
		if (current->data == input) {
			return true;
		}
	}
	return false;
}

size_t DataStructures::TwoWayList::Count() const
{
	return size;
}

bool DataStructures::TwoWayList::IsEmpty() const
{
	return Count() == 0;
}

std::string DataStructures::TwoWayList::Print() const
{
	std::ostringstream os;
	os << "List: ";
	auto current = start;
	while (current) {
		os <<'['<< current->data << ']';
		current = current->next;
	}
	os << std::endl;
	return os.str();
}
