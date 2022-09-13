#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

namespace benchmarking {
	std::mt19937 rng;
	
	struct Dataset {
		std::vector<int> arr;
		
		Dataset reverse() {
			for (int i = 0; i < arr.size() / 2; i++) {
				std::swap(arr[i], arr[arr.size() - 1 - i]);
			}
			
			return *this;
		}
	};
	
	void setup() {
		rng.seed((uint32_t)std::chrono::steady_clock::now().time_since_epoch().count());
	}
	
	Dataset _getBaseDataset(int n) {
		Dataset toret;
		toret.arr.resize(n);
		return toret;
	}
	
	Dataset index(int n, int increment = 1, int base = 0) {
		Dataset toret = _getBaseDataset(n);
		
		for (int i = 0; i < n; i++)
			toret.arr[i] = base + (i * increment);
		
		return toret;
	}
	
	Dataset random(int n) {
		Dataset toret = _getBaseDataset(n);
		
		for (int i = 0; i < n; i++)
			toret.arr[i] = rng();
		
		return toret;
	}
}