#include <vector>

namespace benchmarking {
	struct Dataset {
		std::vector<int> arr;
	};
	
	Dataset index(int n, int increment = 1, int base = 0) {
		Dataset toret;
		toret.arr.resize(n);
		for (int i = 0; i < n; i++)
			toret.arr[i] = base + (i * increment);
		return toret;
	}
}