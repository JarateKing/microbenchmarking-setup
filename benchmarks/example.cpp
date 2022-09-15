#include "src/benchmarking.h"
#include <iostream>

std::vector<benchmarking::Dataset> datasets = {
	{
		"Random",
		DATASET_FUNC( benchmarking::random(n).wrap(0,n-1) ),
	},
	{
		"Sorted", 
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
	options.target_runtime = 0.01;
	options.n = {10, 100, 1000, 10000, 100000};
	options.isMutable = true;
	
	benchmarking::run(options, datasets, algorithms);
}
