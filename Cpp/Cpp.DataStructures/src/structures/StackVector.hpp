#pragma once
#include "interfaces\ISimpleContainer.hpp"
#include <vector>
#include <string>
#include <sstream>

namespace DataStructures {
	template<typename TData>
	class StackVector :public ISimpleContainer<TData> {
	private:
		std::vector<TData> dataHolder;
	public:
		StackVector() = default;
		~StackVector() = default;

		void Push(TData input) {
			dataHolder.push_back(input);
		}

		TData Top() const {
			if (IsEmpty()) {
				return TData();
			}
			return dataHolder.back();
		}

		bool Contain(TData input) {
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
			dataHolder.pop_back();
			return true;
		}

		bool IsEmpty() const {
			return dataHolder.empty();
		}

		size_t Count() const {
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