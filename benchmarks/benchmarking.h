#include "benchmarking_generators.h"
#include <functional>
#include <iostream>

#define DATASET_FUNC(f) [](int n) -> benchmarking::Data { return f; }
#define ALGO_SETUP(f) [](int n, std::vector<int> arr) { f }
#define ALGO_BENCHMARK(f) [](int n, std::vector<int> arr) { f }
#define ALGO_CLEANUP(f) [](int n, std::vector<int> arr) { f }

namespace benchmarking {
	struct Dataset {
		std::string name;
		std::function<Data(int)> generator;
	};
	
	struct Algorithm {
		std::string name;
		std::function<void(int, std::vector<int>)> setup;
		std::function<void(int, std::vector<int>)> benchmark;
		std::function<void(int, std::vector<int>)> cleanup;
	};
	
	struct Options {
		int warmup_runs = 2;
		int measured_runs = 5;
		double target_runtime = 1.0;
		std::vector<unsigned long long> n = {10ull, 100ull, 1000ull};
	};
	
	void run(Options options, std::vector<Dataset> datasets, std::vector<Algorithm> algorithms) {
		for (unsigned long long n : options.n) {
			for (auto e : datasets) {
				Data data = e.generator(n);
				
				std::cout << e.name << ": ";
				for (int i = 0; i < n; i++)
					std::cout << data.arr[i] << ' ';
				std::cout << '\n';
			}
		}
	}
}
