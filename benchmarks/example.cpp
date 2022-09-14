#include "benchmarking.h"
#include <iostream>

std::vector<benchmarking::Dataset> datasets = {
	{
		"random",
		DATASET_FUNC( benchmarking::random(n).wrap(0,9) ),
	},
	{
		"sorted", 
		DATASET_FUNC( benchmarking::index(n) ),
	},
};

std::vector<benchmarking::Algorithm> algorithms = {
	{
		"std::sort",
		ALGO_SETUP(),
		ALGO_BENCHMARK( std::sort(arr.begin(), arr.end()); ),
		ALGO_CLEANUP(),
	},
	{
		"std::stable_sort",
		ALGO_SETUP(),
		ALGO_BENCHMARK( std::stable_sort(arr.begin(), arr.end()); ),
		ALGO_CLEANUP(),
	},
};

int main() {
	benchmarking::setup();
	
	benchmarking::Options options;
	options.measured_runs = 10;
	options.target_runtime = 1.0;
	options.n = {10ull, 100ull, 1000ull, 10000ull, 100000ull};
	
	benchmarking::run(options, datasets, algorithms);
}
