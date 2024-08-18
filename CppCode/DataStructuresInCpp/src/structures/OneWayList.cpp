#pragma once
#include "OneWayList.hpp"
#include <sstream>

void DataStructures::OneWayList::Insert(int input)
{
	InsertBack(input);
}

void DataStructures::OneWayList::InsertFront(int input)
{
	auto newNode = std::make_shared<Nodes::OneWayNode<int>>(input);
	if (!start) {
		start = newNode;
		end = newNode;
		return;
	}
	newNode->next = start;
	start = newNode;
	size++;
}

void DataStructures::OneWayList::InsertBack(int input)
{
	auto newNode = std::make_shared<Nodes::OneWayNode<int>>(input);
	if (!start) {
		start = newNode;
		end = newNode;
		return;
	}
	end->next = newNode;
	end = newNode;
	size++;
}

const bool DataStructures::OneWayList::PopFront()
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

const bool DataStructures::OneWayList::PopBack()
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

const bool DataStructures::OneWayList::Pop(int input)
{
	return PopBack();
}

int DataStructures::OneWayList::Top() const
{
	return start->data;
}

const bool DataStructures::OneWayList::Contain(int input)
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

const size_t DataStructures::OneWayList::Count() const
{
	return size;
}

const bool DataStructures::OneWayList::IsEmpty() const
{
	return Count() == 0;
}

std::string DataStructures::OneWayList::Print() const
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
