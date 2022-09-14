#include "benchmarking.h"
#include <iostream>

std::vector<benchmarking::Dataset> datasets = {
	{"random", DATASET_FUNC(benchmarking::random(n).wrap(0,9))},
	{"sorted", DATASET_FUNC(benchmarking::index(n))},
};

int main() {
	benchmarking::setup();
	
	benchmarking::run(datasets);
}
