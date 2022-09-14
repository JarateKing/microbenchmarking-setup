#include "benchmarking_generators.h"
#include <functional>
#include <iostream>

#define DATASET_FUNC(f) [](int n) -> benchmarking::Data { return f; }

namespace benchmarking {
	struct Dataset {
		std::string name;
		std::function<Data(int)> generator;
	};
	
	void run(std::vector<Dataset> datasets) {
		
		for (auto e : datasets) {
			Data data = e.generator(10);
			
			std::cout << e.name << ": ";
			for (int i = 0; i < 10; i++)
				std::cout << data.arr[i] << ' ';
			std::cout << '\n';
		}
	}
}
