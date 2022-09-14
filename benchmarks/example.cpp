#include "benchmarking.h"
#include <iostream>

std::vector<benchmarking::Dataset> datasets = {
	{
		"random",
		DATASET_FUNC( benchmarking::random(n).wrap(0,n-1) ),
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
	options.measured_runs = 3;
	options.target_runtime = 0.1;
	options.n = {10ull, 15ull};
	options.isMutable = true;
	
	benchmarking::run(options, datasets, algorithms);
}
