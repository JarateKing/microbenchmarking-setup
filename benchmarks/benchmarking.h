#include "benchmarking_generators.h"
#include <functional>
#include <iostream>

#define DATASET_FUNC(f) [](int n) -> benchmarking::Data { return f; }

namespace benchmarking {
	struct Dataset {
		std::string name;
		std::function<Data(int)> generator;
	};
	
	struct Options {
		int warmup_runs = 2;
		int measured_runs = 5;
		double target_runtime = 1.0;
		std::vector<unsigned long long> n = {10ull, 100ull, 1000ull};
	};
	
	void run(Options options, std::vector<Dataset> datasets) {
		
		for (auto e : datasets) {
			Data data = e.generator(10);
			
			std::cout << e.name << ": ";
			for (int i = 0; i < 10; i++)
				std::cout << data.arr[i] << ' ';
			std::cout << '\n';
		}
	}
}
