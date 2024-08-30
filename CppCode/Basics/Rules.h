#pragma once
#include "iostream"

namespace Rules {
	class Rule5 {
	public:
		static int i;
		int x;
		int* s;
		Rule5(int* s) :s(s),x(i++) {
			std::cout << "ctor" << *s << std::endl;
		}
		Rule5(const Rule5& copy): x(i++) {
			s = new int;
			*s = *copy.s;
			std::cout << "copy_ctor" << *s << std::endl;
		}
		Rule5(Rule5&& move)noexcept : x(move.x)  {
			s = move.s;
			move.s = nullptr;
			std::cout << "move_ctor" << *s << std::endl;
		}
		~Rule5() {
			std::cout << "dtor"<<x<< std::endl;
			delete s;
		}
		Rule5& operator=(const Rule5& copy) {
			std::cout << "copy_oper" << *s << std::endl;
			x = i++;
			s = new int;
			*s = *copy.s;
			return *this;
		}
		Rule5& operator=(Rule5&& moved) noexcept   {
			std::cout << "move_oper" << *s << std::endl;
			x = moved.x;
			s = moved.s;
			moved.s = nullptr;
			return *this;
		}
	};
	int Rule5::i = 0;
	class RuleFourAndHalf {
	public:
		int* s;
		RuleFourAndHalf(int* s) :s(s) {
			std::cout << "ctor" << *s << std::endl;
		}
		RuleFourAndHalf(const RuleFourAndHalf& copy) {
			s = new int;
			*s = *copy.s;
			std::cout << "copy_ctor" << *s << std::endl;
		}
		RuleFourAndHalf(RuleFourAndHalf&& move) noexcept {
			s = move.s;
			move.s = nullptr;
			std::cout << "move_ctor" << *s << std::endl;
		}
		~RuleFourAndHalf() {
			std::cout << "dtor" << std::endl;
			delete s;
		}
		RuleFourAndHalf& operator=(RuleFourAndHalf copy) {
			std::cout << "copy_oper" << *s << std::endl;
			s = new int;
			*s = *copy.s;
			return *this;
		}
		void swap(RuleFourAndHalf& other) {
			int* temp= other.s;
			other.s = this->s;
			this->s = temp;
		}
	};

	class Rule3 {
	public:
		int* s;
		Rule3(int* s) :s(s) {
			std::cout << "ctor" << *s << std::endl;
		}
		Rule3(const Rule3& copy) {
			s = new int;
			*s = *copy.s;
			std::cout << "copy_ctor" << *s << std::endl;
		}
		Rule3(Rule3&& move) noexcept {
			s = move.s;
			move.s = nullptr;
			std::cout << "move_ctor" << *s << std::endl;
		}
		~Rule3() {
			std::cout << "dtor" << std::endl;
			delete s;
		}
	};

	class Rule0a {
	public:
		std::shared_ptr<int> s;
		Rule0a(int* s) :s(s) {
			std::cout << "ctor" << *s << std::endl;
		}
	};

	class Rule0b {
	public:
		std::shared_ptr<int> s;
		Rule0b(int* s) :s(s) {
			std::cout << "ctor" << *s << std::endl;
		}
		Rule0b(const Rule0b& copy) = default;
		Rule0b(Rule0b&& move) = default;
		~Rule0b() = default;
	};

	static void doExample() {
		{
			Rule5* x1 = new Rule5(new int(1));//standard ctor
			Rule5 x2(new int(2));//standard ctor
			Rule5 x3 = Rule5(new int(2));//copy elision
			Rule5 x4copy = Rule5(x2);//copy ctor
			Rule5 x5move = Rule5(std::move(x2));//move ctor
			Rule5 x10(nullptr);
			Rule5 x20(nullptr);
			x10 = x3;//copy oper
			x20 = std::move(x3);//move oper
			delete x1;
		}
		Rule0a* o1 = new Rule0a(new int(1));
		Rule0a* o2 = new Rule0a(*o1);
		Rule0a o3 = *o2;

		Rule0b* o11 = new Rule0b(new int(1));
		Rule0b* o12 = new Rule0b(*o11);

		Rule5* r1 = new Rule5(new int(1));
		Rule5* r2 = new Rule5(*r1);
	}
};