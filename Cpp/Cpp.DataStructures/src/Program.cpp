#pragma once
#include "iostream"
#include "string"
#include <sstream>

#include "structures/StackVector.hpp"
#include "structures/QueueVector.hpp"
#include "structures/BinaryTree.hpp"
#include "structures/ChainedHashTable.h"
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
		tree.Push(tab[i]);
	}
	Console::WriteLine("Top " + tree.Top());
	Console::WriteLine(tree.Print());
	Console::WriteLine(tree.DFSDepth());
	Console::WriteLine(tree.BFSDepth());
	DataStructures::ChainedHashTable table;
	std::string tekst = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.";
	std::vector<std::string> slowa;
	std::stringstream ss(tekst);
	std::string slowo;

	while (ss >> slowo) {
		slowa.push_back(slowo);
	}

	// Wyœwietlanie wyników
	for (const auto& s : slowa) {
		table.Push(s);
	}
	Console::WriteLine(table.Print());

	return 0;
}