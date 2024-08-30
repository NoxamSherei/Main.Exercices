#pragma once
#include "mutex"
#include "thread"
#include "atomic"
#include "vector"
#include "iostream"

class Multithreading {
	//dangers: 
	// * dataracing - process same value in same time
	// * deadlock - threads can run futher becouse some part of code/variables are locked and not unlocked
	// * starving - runout from system resources to futher procced with threads
	int unsafe_x = 0;
	int mutex_x = 0;
	int lockguard_x = 0;
	std::atomic<int> atomic_x = 0;
	std::mutex mutex;
	std::mutex lockGuardMutex;
	void add() {
		unsafe_x++;
		mutex.lock();
		mutex_x++;
		mutex.unlock();
		atomic_x++;
		std::lock_guard<std::mutex> lockGuard(lockGuardMutex);
		lockguard_x++;
	}
public:
	void doExample() {
		std::vector<std::thread*> threads;
		for (size_t i = 0; i < 10000; i++)
		{
			std::thread* th = new std::thread([&]() {
				add();});
			threads.push_back(th);
		}
		for (auto& th : threads) {
			th->join();
		}
		std::cout << "unsafe_x:" << unsafe_x << std::endl;
		std::cout << "mutex_x:" << mutex_x << std::endl;
		std::cout << "lockguard_x:" << lockguard_x << std::endl;
		std::cout << "atomic_x:" << atomic_x << std::endl;
	}
};