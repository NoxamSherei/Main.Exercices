#pragma once
#include "ChainedHashTable.h"
#include "math.h"
namespace DataStructures {
	void ChainedHashTable::Push(std::string input)
	{
		int id = GetId(GetHash(input));
		dataHolder[id].push_back(input);
		size++;
	}

	bool ChainedHashTable::Contain(std::string input)
	{
		if (IsEmpty()) {
			return false;
		}
		int id = GetId(GetHash(input));
		if (dataHolder[id].empty()) {
			return false;
		}
		for (const auto& elem : dataHolder[id]) {
			if (elem == input) {
				return true;
			}
		}
		return false;
	}

	size_t ChainedHashTable::Depth() const
	{
		if (IsEmpty()) {
			return 0;
		}
		size_t maxDepht = 0;
		for (auto vec : dataHolder) {
			maxDepht = std::max(vec.size(), maxDepht);
		}
		return size_t();
	}

	size_t ChainedHashTable::Count() const
	{
		return size;
	}

	bool ChainedHashTable::IsEmpty() const
	{
		return size == 0;
	}

	std::string ChainedHashTable::Print() const
	{
		std::ostringstream os;
		for (size_t i = 0; i < tableSize; i++)
		{
			os << '[' << i << "]:";
			if (dataHolder[i].empty()) {
				os << "[empty]"<<std::endl;
				continue;
			}
			for (const auto& elem : dataHolder[i]) {
				os << '[' << elem << ']';
			}
			os << std::endl;
		}
		return os.str();
	}

	unsigned int ChainedHashTable::GetHash(std::string input) const
	{
		unsigned int sum = 0;
		for (char ch : input) {
			sum += static_cast<int>(ch);
		}
		unsigned int hash = sum ^ input.size();
		return hash;
	}

	int ChainedHashTable::GetId(unsigned int hash) {
		return hash % tableSize;
	}
}