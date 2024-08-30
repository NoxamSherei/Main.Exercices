#pragma once
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "CtorDtor.h"
#include "Multithreading.h"
#include "Rules.h"
#include "Template.h"
#include "Casting.h"
#include "Paterns\RunPaternExample.h"
#include "Pointers.h"
#include "Exceptions.h"

using std::string;

int dochar(char* arr, char check, int size) {
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << '|';
	}
	std::cout << std::endl;
	return 0;
}
int dochar(char* arr, char check) {
	for (size_t i = 0; arr[i] != '\0'; i++)
	{
		std::cout << arr[i] << '|';
	}
	std::cout << std::endl;
	return 0;
}
int main()
{
	Exceptions::doExample();
	Pattern::doExample();
	Pointers::doExample();
	Casting::doExample();
	string str = "xdsrgss";
	std::cout << std::endl;
	dochar((char*)str.c_str(), 'x', str.size());
	dochar((char*)str.c_str(), 'x');
	char* arr = new char[200] {'x', 'y', 'z', 'o','f'};
	dochar(arr, 'x');
	Rules::doExample();
	CtorDtor::doExample();
	Multithreading mt;
	mt.doExample();
	Templates::doExample();
}