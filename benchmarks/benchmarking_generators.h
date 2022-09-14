#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

namespace benchmarking {
	std::mt19937 rng;
	
	struct Data {
		std::vector<int> arr;
		
		Data reverse() {
			for (int i = 0; i < arr.size() / 2; i++) {
				std::swap(arr[i], arr[arr.size() - 1 - i]);
			}
			return *this;
		}
		Data reverse_region(int start, int end) {
			for (int i = 0; i < (end - start) / 2; i++) {
				std::swap(arr[start + i], arr[end - 1 - i]);
			}
			return *this;
		}
		Data sort() {
			std::sort(arr.begin(), arr.end());
			return *this;
		}
		Data sort_region(int start, int end) {
			std::sort(arr.begin() + start, arr.begin() + end);
			return *this;
		}
		Data add(int a) {
			for (int i = 0; i < arr.size(); i++) {
				arr[i] += a;
			}
			return *this;
		}
		Data multiply(int a) {
			for (int i = 0; i < arr.size(); i++) {
				arr[i] *= a;
			}
			return *this;
		}
		Data replace(int find, int use) {
			for (int i = 0; i < arr.size(); i++) {
				if (arr[i] == find) {
					arr[i] = use;
				}
			}
			return *this;
		}
		Data clamp(int min, int max) {
			for (int i = 0; i < arr.size(); i++) {
				if (arr[i] < min)
					arr[i] = min;
				if (arr[i] > max)
					arr[i] = max;
			}
			return *this;
		}
		Data wrap(int min, int max) {
			max++; // max is inclusive range
			int range = max - min;
			for (int i = 0; i < arr.size(); i++) {
				int v = arr[i];
				arr[i] = (((v - min) % range) + range) % range + min;
			}
			return *this;
		}
		Data modulo(int mod) {
			for (int i = 0; i < arr.size(); i++) {
				arr[i] = arr[i] % mod;
			}
			return *this;
		}
	};
	
	void setup() {
		rng.seed((uint32_t)std::chrono::steady_clock::now().time_since_epoch().count());
	}
	
	Data _getBaseData(int n) {
		Data toret;
		toret.arr.resize(n);
		return toret;
	}
	
	Data index(int n, int increment = 1, int base = 0) {
		Data toret = _getBaseData(n);
		
		for (int i = 0; i < n; i++)
			toret.arr[i] = base + (i * increment);
		
		return toret;
	}
	
	Data random(int n) {
		Data toret = _getBaseData(n);
		
		for (int i = 0; i < n; i++)
			toret.arr[i] = rng();
		
		return toret;
	}
}
