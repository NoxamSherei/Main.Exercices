#pragma once
#include "interfaces/IHashTable.hpp"
#include <list>
#include <array>
#include <string>
#include <sstream>

namespace DataStructures {
	using std::string;
	using std::array;
	using std::list;

	template<typename TData, const int _tableSize = 10, class THasher = std::hash<TData>>
	class ChainedHashTable :public IHashTable<TData> {
	private:
		int _size = 0;
		array<list<TData>, _tableSize> _dataHolder;
	private:
		int GetIdFromHash(unsigned int hash) {
			return hash % _tableSize;
		}
	public:
		ChainedHashTable() = default;
		~ChainedHashTable() = default;
		// Inherited via IHashTable
		void Insert(TData input)
		{
			int id = GetIdFromHash(GetHash(input));
			_dataHolder[id].push_back(input);
			_size++;
		}
		const bool Contain(TData input)
		{
			if (IsEmpty()) {
				return false;
			}
			int id = GetIdFromHash(GetHash(input));
			if (_dataHolder[id].empty()) {
				return false;
			}
			for (const auto& elem : _dataHolder[id]) {
				auto it = std::find(_dataHolder[id].begin(), _dataHolder[id].end(), input);
				if (it != _dataHolder[id].end()) {
					return true;
				}
			}
			return false;
		}
		const bool Remove(TData input)
		{
			if (IsEmpty()) {
				return false;
			}

			int id = GetIdFromHash(GetHash(input));
			if (_dataHolder[id].empty()) {
				return false;
			}

			auto it = std::find(_dataHolder[id].begin(), _dataHolder[id].end(), input);
			if (it != _dataHolder[id].end()) {
				_dataHolder[id].erase(it);
				_size--;
				return true;
			}
			return false;
		}
		const size_t Count() const { return _size; }
		const bool IsEmpty() const { return _size == 0; }
		const size_t Depth() const
		{
			if (IsEmpty()) {
				return 0;
			}
			size_t maxDepht = 0;
			for (auto vec : _dataHolder) {
				maxDepht = std::max(vec.size(), maxDepht);
			}
			return maxDepht;
		}
		unsigned int GetHash(TData input) const
		{
			int hash = THasher{}(input);
			return hash;
		}
		string ToString() const
		{
			std::ostringstream os;
			for (size_t i = 0; i < _tableSize; i++)
			{
				os << '[' << i << "]:";
				if (_dataHolder[i].empty()) {
					os << "[empty]" << std::endl;
					continue;
				}
				for (const auto& elem : _dataHolder[i]) {
					os << '[' << elem << ']';
				}
				os << std::endl;
			}
			return os.str();
		}
	};
}