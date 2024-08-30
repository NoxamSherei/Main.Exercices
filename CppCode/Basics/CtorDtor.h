#pragma once

#include "iostream"
namespace CtorDtor {
	class A {
	public:
		int x;
		A(int x) :x(x) {
			std::cout << "ctor A" << x << std::endl;
		}
		virtual ~A() { 
			// virtual destructor is neccesary for destroying obj properly
			// add this destructor to vtable
			std::cout << "dtor A" << x << std::endl;
		}
		virtual void print() {
			std::cout << "text A" << x << std::endl;
		}
	};
	class B :public A {
	public:
		B(int x) :A(x) {
			std::cout << "ctor B" << x << std::endl;
		}
		~B() {
			std::cout << "dtor B" << x << std::endl;

		}
		virtual void print() override {
			std::cout << "text B" << x << std::endl;
		}
	};
	class C :public B {
	public:
		C(int x) :B(x) {
			std::cout << "ctor C" << x << std::endl;
		}
		~C() {
			std::cout << "dtor C" << x << std::endl;
		}
		virtual void print() override {
			std::cout << "text C" << x << std::endl;
		}
	};

	void doExample() {
		A* a5 = new C(5);//A->B->C
		C c1(1);
		C c2(2);
		C c3(3);
		B b4(4);
		B* b6 = new C(6);
		a5->x = 5;
		b6->x = 6;
		b4.x = 4;
		c1.x = 1;
		c2.x = 2;
		c3.x = 3;
		a5->print();
		c1.print();
		c2.print();
		c3.print();
		b4.print();
		delete b6;
		delete a5; std::cout << std::endl;//delete a5 C->B->A
	}//delete c3, c2, c1
};