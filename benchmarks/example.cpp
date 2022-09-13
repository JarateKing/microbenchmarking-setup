#include "benchmarking.h"
#include <iostream>

int main() {
	benchmarking::setup();
	
	benchmarking::Dataset dataset = benchmarking::index(10).replace(0, 1);
	
	for (int i = 0; i < 10; i++)
		std::cout << dataset.arr[i] << ' ';
}