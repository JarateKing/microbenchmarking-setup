#include "benchmarking.h"
#include <iostream>

int main() {
	benchmarking::Dataset dataset = benchmarking::index(10);
	
	for (int i = 0; i < 10; i++)
		std::cout << dataset.arr[i] << ' ';
}