#pragma once
#include "interfaces\ISimpleContainer.hpp"
#include <vector>
#include <string>
#include <sstream>

namespace DataStructures {
	template<typename TData>
	class QueueVector :public ISimpleContainer<TData> {
	private:
		std::vector<TData> dataHolder;
	public:
		QueueVector() = default;
		~QueueVector() = default;

		void Insert(TData input) {
			dataHolder.push_back(input);
		}

		TData Top() const {
			if (IsEmpty()) {
				return TData();
			}
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

		const bool Remove() {
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

		std::string ToString() const {
			std::ostringstream output;
			for (const auto& var : dataHolder)
			{
				output << " " << var << ".";
			}
			return output.str();
		}
	};
}