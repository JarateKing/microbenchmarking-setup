#include <vector>

namespace benchmarking {
	struct Dataset {
		std::vector<int> arr;
	};
	
	Dataset index(int n) {
		Dataset toret;
		toret.arr.resize(n);
		for (int i = 0; i < n; i++)
			toret.arr[i] = i;
		return toret;
	}
}