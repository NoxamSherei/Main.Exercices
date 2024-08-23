#pragma once
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "CtorDtor.h"
#include "Multithreading.h"





class D {
public:
	int* s;
	D(int* s) :s(s) {
		std::cout << "ctor" << *s << std::endl;
	}
	D(const D& copy) {
		s = new int;
		*s = *copy.s;
		std::cout << "copy_ctor" << *s << std::endl;
	}
	D(D&& move) noexcept {
		s = move.s;
		move.s = nullptr;
		std::cout << "move_ctor" << *s << std::endl;
	}
	~D() {
		std::cout << "dtor" << *s << std::endl;
		delete s;
	}
	D& operator=(const D& copy) {
		std::cout << "copy_oper" << *s << std::endl;
		s = new int;
		*s = *copy.s;
		return *this;
	}
	D& operator=(D&& moved) noexcept {
		std::cout << "move_oper" << *s << std::endl;
		s = moved.s;
		moved.s = nullptr;
		return *this;
	}
};



int main()
{
	D* x1 = new D(new int(1));//standard ctor
	D x2(new int(2));//standard ctor
	D x3 = D(new int(2));//copy elision
	D x4copy = D(x2);//copy ctor
	D x5move = D(std::move(x2));//move ctor
	D x10 = x3;//copy oper
	D x20 = std::move(x3);//move oper

	CtorDtor x42;
	x42.doCtorDtor();
	Multithreading multi;
	multi.DoJob();
}