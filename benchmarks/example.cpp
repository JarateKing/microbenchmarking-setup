#include "benchmarking.h"
#include <iostream>

std::vector<benchmarking::Dataset> datasets = {
	{"random", DATASET_FUNC(benchmarking::random(n).wrap(0,9))},
	{"sorted", DATASET_FUNC(benchmarking::index(n))},
};

int main() {
	benchmarking::setup();
	
	for (auto e : datasets) {
		benchmarking::Data data = e.generator(10);
		
		std::cout << e.name << ": ";
		for (int i = 0; i < 10; i++)
			std::cout << data.arr[i] << ' ';
		std::cout << '\n';
	}
}
