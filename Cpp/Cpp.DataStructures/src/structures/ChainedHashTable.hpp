#pragma once
#include "interfaces/IHashTable.h"
#include <vector>
#include <string>
#include <sstream>

namespace DataStructures {
	class ChainedHashTable :public IHashTable<std::string> {
	private:
		int size = 0;
		int tableSize = 10;
		std::vector<std::string> dataHolder[10];
		int GetId(unsigned int hash);
	public:
		ChainedHashTable() = default;
		~ChainedHashTable() = default;
		// Inherited via IHashTable
		void Push(std::string input);
		bool Contain(std::string input);
		size_t Depth() const;
		size_t Count() const;
		bool IsEmpty() const;
		std::string Print() const;
		unsigned int GetHash(std::string input) const;
	};
}