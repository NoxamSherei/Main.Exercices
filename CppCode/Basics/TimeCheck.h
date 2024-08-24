#pragma once
#include <iostream>
namespace TimeCheck {
#include <chrono>
	using std::chrono::seconds;
	using std::chrono::milliseconds;
	using std::chrono::microseconds;
	using std::chrono::steady_clock;
	using std::chrono::duration_cast;
	using std::chrono::system_clock;

	template<typename Func, typename TOutputTiming= microseconds>
	long long TimeFunc(Func f)
	{
		auto begin = steady_clock::now();
		f();
		auto end = steady_clock::now();

		return duration_cast<TOutputTiming>(end - begin).count();
	}
};