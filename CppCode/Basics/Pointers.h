#pragma once
#include "iostream"
#include "string"

using std::string;

namespace Pointers {
	struct MyIntPtrWithUseRaII {
		int* x;
		MyIntPtrWithUseRaII() {
			this->x = new int();
		}
		MyIntPtrWithUseRaII(int&& x) {
			this->x = new int(x);
		}
		~MyIntPtrWithUseRaII() {
			delete x;
		}
	};

	// Diamont problem
	// Wrong Example
	// this pointer never will be deleted becouse there still have counts;
	class DiamontExample {
	public:
		std::shared_ptr<DiamontExample> connection;
		DiamontExample(std::shared_ptr<DiamontExample> other) {
			this->connection = other;
			other->connection = this->connection;
		}
	};

	// Correct Example
	// this pointer will be deleted
	class DiamontExample2 {
	public:
		std::weak_ptr<DiamontExample2> connection;
		DiamontExample2(std::shared_ptr<DiamontExample2> other) {
			this->connection = other;
			other->connection = this->connection;
		}
	};

	struct Note {
		string Name;
		int x;
	};

	void UseUniquePtrViaMove(std::unique_ptr<Note>&& uniqPtr) {

	}

	void UseUniquePtrViaPtr(std::unique_ptr<Note>* uniqPtr) {

	}

	void doExample() {
		{
			MyIntPtrWithUseRaII xyz0;
			MyIntPtrWithUseRaII xyz3(3);
			*xyz0.x = 42;
		}
		Note a;
		//sharedptr
		std::shared_ptr<Note> shrPtr1 = std::make_shared<Note>(a);
		/*std::shared_ptr<string> shrPtr2 = std::make_shared<string>(a.Name);
		std::shared_ptr<string> shrPtr3 = std::make_shared<string>(a.x);*/
		//weakptr
		std::weak_ptr<Note> weakPtr = shrPtr1;
		//uniqueptr
		std::unique_ptr<Note> uniqPtr = std::make_unique<Note>(a);
		UseUniquePtrViaMove(std::move(uniqPtr));
		UseUniquePtrViaPtr(&uniqPtr);
	}
}