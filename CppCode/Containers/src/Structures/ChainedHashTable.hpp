#pragma once
#include "interfaces/IHashTable.h"
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
namespace DataStructures {
	class ChainedHashTable :public IHashTable<std::string> {
	private:
		std::unordered_map<int, std::string> m;
		int size = 0;
		int tableSize = 10;
		std::vector<std::string> dataHolder[10];
		int GetIdFromHash(unsigned int hash);
	public:
		ChainedHashTable() = default;
		~ChainedHashTable() = default;
		// Inherited via IHashTable
		void Insert(std::string input);
		const bool Contain(std::string input);
		const size_t Depth() const;
		const size_t Count() const;
		const bool IsEmpty() const;
		std::string Print() const;
		unsigned int GetHash(std::string input) const;
	};
}