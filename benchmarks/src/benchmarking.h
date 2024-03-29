#include "benchmarking_generators.h"
#include <functional>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <cfloat>
#include <random>
#include <sstream>

#define DATASET_FUNC(f) [](unsigned long long n, std::mt19937 rng) -> benchmarking::Data { return f; }
#define ALGO_SETUP(f) [](unsigned long long n, std::vector<int>* arr, std::mt19937 rng) { f }
#define ALGO_BENCHMARK(f) [](unsigned long long n, std::vector<int>* arr, std::mt19937 rng) { f }
#define ALGO_CLEANUP(f) [](unsigned long long n, std::vector<int>* arr, std::mt19937 rng) { f }

namespace benchmarking {
	struct Dataset {
		std::string name;
		std::function<Data(int, std::mt19937)> generator;
	};
	
	struct Algorithm {
		std::string name;
		std::function<void(unsigned long long, std::vector<int>*, std::mt19937)> setup;
		std::function<void(unsigned long long, std::vector<int>*, std::mt19937)> benchmark;
		std::function<void(unsigned long long, std::vector<int>*, std::mt19937)> cleanup;
	};
	
	struct Options {
		int warmup_runs = 2;
		int measured_runs = 5;
		long double target_runtime = 1.0;
		std::vector<unsigned long long> n = {10ull, 100ull, 1000ull};
		bool isMutable = true;
	};
	
	void run(Options options, std::vector<Dataset> datasets, std::vector<Algorithm> algorithms) {
		std::cout << datasets.size() << ' ' << algorithms.size() << '\n';
		
		for (Algorithm algo : algorithms) {
			std::cout << algo.name << '\n';
		}
		
		for (unsigned long long n : options.n) {
			std::cout << n << ' ';
		}
		std::cout << '\n';
		
		for (Dataset dataset : datasets) {
			std::cout << dataset.name << '\n';
			
			std::vector<std::stringstream> output(algorithms.size());
			for (int i = 0; i < algorithms.size(); i++) {
				output[i] << std::fixed << std::setprecision(10);
			}
			
			for (unsigned long long n : options.n) {
				std::vector<int> data;
				if (!options.isMutable)
					data = dataset.generator(n, rng).arr;
				
				for (int i = 0; i < algorithms.size(); i++) {
					Algorithm algo = algorithms[i];
					
					for (int j = 0; j < options.warmup_runs; j++) {
						if (options.isMutable)
							data = dataset.generator(n, rng).arr;
						
						algo.setup(n, &data, rng);
						algo.benchmark(n, &data, rng);
						algo.cleanup(n, &data, rng);
					}
					
					std::chrono::high_resolution_clock::time_point t1, t2;
					
					for (int j = 0; j < options.measured_runs; j++) {
						long double time = 0;
						double count = 0;
						
						while (time < options.target_runtime * 1000000000.0) {
							if (options.isMutable)
								data = dataset.generator(n, rng).arr;
							
							algo.setup(n, &data, rng);
							
							t1 = std::chrono::high_resolution_clock::now();
							algo.benchmark(n, &data, rng);
							t2 = std::chrono::high_resolution_clock::now();
							time += std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
							count++;
							
							algo.cleanup(n, &data, rng);
						}
						
						output[i] << (count * (1000000000.0 / time)) << ' ';
					}
					output[i] << '\n';
				}
			}
			
			for (int i = 0; i < algorithms.size(); i++) {
				std::cout << output[i].str();
			}
		}
	}
}
