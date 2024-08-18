#pragma once
#include "interfaces\ISimpleContainer.hpp"
#include <vector>
#include <string>
#include <sstream>

namespace DataStructures {
	template<typename TData>
	class QueueVector :public ISimpleContainer<char> {
	private:
		std::vector<char> dataHolder;
	public:
		QueueVector() = default;
		~QueueVector() = default;

		void Insert(TData input) {
			dataHolder.push_back(input);
		}

		TData Top() const {
			return dataHolder.front();
		}

		const bool Contain(TData input) {
			for (size_t i = 0; i < Count(); i++)
			{
				if (dataHolder[i] == input) {
					return true;
				}
			}
			return false;
		}

		bool Pop() {
			if (IsEmpty()) {
				return false;
			}
			for (size_t i = 0; i < Count() - 1; i++)
			{
				dataHolder[i] = dataHolder[i + 1];
			}
			dataHolder.pop_back();
			return true;
		}

		const bool IsEmpty() const {
			return dataHolder.empty();
		}

		const size_t Count() const {
			return dataHolder.size();
		}

		std::string Print() const {
			std::ostringstream output;
			for (const auto& var : dataHolder)
			{
				output << " " << var << ".";
			}
			return output.str();
		}
	};
}