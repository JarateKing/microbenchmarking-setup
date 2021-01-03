#include "benchmark.h"
#include "benchmark_options.h"
#include <vector>
#include <algorithm>

BENCHMARK( Example One, {
	// metadata
	std::string description = "Description for Example One";
	
	// custom data
	std::vector<int> arr;
	
	// methods
	void Pre(unsigned long long n) {
		arr.resize(n);
		for (int i = 0; i < n; i++) {
			arr[i] = rand();
		}
	}
	void Run(unsigned long long  n) {
		std::sort(arr.begin(), arr.end());
	}
	void Post(unsigned long long  n) {
		
	}
});
