#include "benchmarking.h"
#include <iostream>

std::vector<benchmarking::Dataset> datasets = {
	{"random", DATASET_FUNC(benchmarking::random(n).wrap(0,9))},
	{"sorted", DATASET_FUNC(benchmarking::index(n))},
};

int main() {
	benchmarking::setup();
	
	benchmarking::Options options;
	options.measured_runs = 10;
	options.target_runtime = 1.0;
	options.n = {10ull, 100ull, 1000ull, 10000ull, 100000ull};
	
	benchmarking::run(options, datasets);
}
