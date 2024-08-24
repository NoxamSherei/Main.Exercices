#pragma once
#include "iostream"
#include "string"

namespace Templates {
	int doSomething(int x)
	{
		return x + x;
	}
	std::string doSomething(std::string x)
	{
		return x + x;
	}
	double doSomething(double x)
	{
		return x + x;
	}
	template<typename TTypeName, int y = 42>
	TTypeName doSomething3(TTypeName x) {
		if constexpr (std::is_same_v<TTypeName, std::string>) {
			return x + std::to_string(y);
		}
		else {
			return x + y;
		}
	}
	/*int doSomething2(int x)
	{
		return x + x;
	}
	std::string doSomething2(std::string x)
	{
		return x + std::to_string(y);
	}*/
	template<typename TTypeName>
	TTypeName doSomething2(TTypeName x) {
		return x + x;
	}
	/*int doSomething2(int x)
	{
		return x + x;
	}
	std::string doSomething2(std::string x)
	{
		return x + x;
	}*/
	template<typename TData>
	class stack {
		std::vector<TData> dataHolder;
	public:
		void push(TData data) {
			dataHolder.push_back(data);
		}
		void pop(TData data) {
			dataHolder.erase(dataHolder.back());
		}
		TData peek() {
			return dataHolder.back();
		}
	};
	void DoExample() {

		int x = 21;
		Templates::doSomething2<int>(x);
		std::cout << Templates::doSomething3<std::string, 4>("xyz");
		double s = Templates::doSomething2<double>(x);
		Templates::doSomething2<std::string>("XYZ");
	}
}