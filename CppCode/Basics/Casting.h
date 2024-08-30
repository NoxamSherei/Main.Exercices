#pragma once
#include "iostream"
#include "iomanip"
namespace Casting {
	struct A {
		virtual void print() { std::cout << "A\n"; }
	};
	struct B :public A {
		void print() override { std::cout << "B\n"; }
	};
	void doExample() {
		int i1 = 42;
		//implicit cast
		double implicitCastDouble = i1;
		//explicit cast
		//casting C
		//(type) value
		int explicitCastCType = (int)implicitCastDouble;
		double d2 = (double)i1;
		char c1 = (char)i1;
		int xxx = (int)'a';
		//casting Cpp
		//static_cast<type>
		double d3 = static_cast<double>(i1);
		//dynamic_cast<type> 
		B b;
		A* a1 = dynamic_cast<A*>(&b);
		a1->print();
		B b11;
		B* a11 = dynamic_cast<B*>(&b11);
		a11->print();
		B* b2 = new B();
		A* a2 = dynamic_cast<A*>(b2);
		b2->print();
		A* b3 = new B();
		B* a3 = dynamic_cast<B*>(b3);
		a3->print();
		//reinterpet_cast<type>
		//itself might be unspecified behaviour, attempting to access the parameters once you've done the cast is undefined behaviour.
		B* b1 = reinterpret_cast<B*>(a1);
		b1->print();
		char* chars =new char[4]{ 'a','b','c','d' };
		int32_t* X1 = reinterpret_cast<int32_t*>(chars);
		char* C11 = reinterpret_cast<char*>(X1);
		printf("0x|%x|%x|%x|%x|\n", *C11, *C11 + 1, *C11 + 2, *C11 + 3);
		printf("0x|%x|\n", *X1);
		std::cout << *C11 << "C" << (int)(*C11) << '|';
		C11++;
		std::cout << *C11 << "C" << (int)(*C11) << '|';
		C11++;
		std::cout << *C11 << "C" << (int)(*C11) << '|';
		C11++;
		std::cout << *C11 << "C" << (int)(*C11) << '|';
		//const_cast<type>
		const int val = 10;
		const int* ptr = &val;
		int* ptr1 = const_cast<int*>(ptr);
		std::cout << *ptr1;
	}
}