#include "benchmark.h"
#include <vector>
#include <algorithm>

BENCHMARK( Example Two, {
	// metadata
	std::string description = "Description for Example Two";
	
	// custom data
	std::vector<int> arr;
	
	// methods
	void Pre() {
		arr.resize(1000000);
		for (int i = 0; i < 1000000; i++) {
			arr[i] = rand();
		}
	}
	void Run() {
		std::stable_sort(arr.begin(), arr.end());
	}
	void Post() {
		
	}
});
