#pragma once
#include <iostream>
#include <chrono>
using std::chrono::seconds;
using std::chrono::milliseconds;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::system_clock;

#define _MAX 1000000
template<typename Func>
long long TimeFunc(Func f)
{
	auto begin = steady_clock::now();
	f(_MAX);
	auto end = steady_clock::now();

	return duration_cast<milliseconds>(end - begin).count();
}