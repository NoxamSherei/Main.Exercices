#pragma once
#include "iostream"
#include "string"
#include <sstream>

#include "structures/StackVector.hpp"
#include "structures/QueueVector.hpp"
#include "structures/BinaryTree.hpp"
#include "utilities/Console.hpp"



int main() {
	DataStructures::StackVector<char> stack;
	DataStructures::QueueVector<char> queue;
	std::string str = "HelloWorld";
	for (size_t i = 0; i < str.size(); i++)
	{
		stack.Push(str[i]);
		queue.Push(str[i]);
	}
	Console::WriteLine(stack.Print());
	Console::WriteLine(queue.Print());
	Console::Write("clearing Stack:");
	for (size_t i = 0; i < str.size(); i++)
	{
		std::cout << stack.Top() << ',';
		stack.Pop();
	}
	Console::EndLine();
	Console::Write("clearing Queue:");
	for (size_t i = 0; i < str.size(); i++)
	{
		std::cout << queue.Pop()<<',';
		queue.Pop();
	}
	Console::EndLine();
	DataStructures::BinaryTree tree;
	int tab[10] = { 5,3,7,6,8,4,2,1,10,9 };
	for (size_t i = 0; i < 10; i++)
	{
		tree.Push(i);
	}
	Console::WriteLine("Top " + tree.Top());
	Console::WriteLine(tree.Print());

	return 0;
}