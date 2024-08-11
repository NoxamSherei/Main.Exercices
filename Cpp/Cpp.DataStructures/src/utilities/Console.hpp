#pragma once
#include <iostream>

namespace Console {
	template<typename TData>
	void Write(TData output) {
		std::cout << output;
	}

	template<typename TData>
	void WriteLine(TData output) {
		std::cout << output << std::endl;
	}

	void EndLine() {
		std::cout << std::endl;
	}
};