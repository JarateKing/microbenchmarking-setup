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
		Dataset sort() {
			std::sort(arr.begin(), arr.end());
			return *this;
		}
		Dataset add(int a) {
			for (int i = 0; i < arr.size(); i++) {
				arr[i] += a;
			}
			return *this;
		}
		Dataset multiply(int a) {
			for (int i = 0; i < arr.size(); i++) {
				arr[i] *= a;
			}
			return *this;
		}
		Dataset replace(int find, int use) {
			for (int i = 0; i < arr.size(); i++) {
				if (arr[i] == find) {
					arr[i] = use;
				}
			}
			return *this;
		}
		Dataset clamp(int min, int max) {
			for (int i = 0; i < arr.size(); i++) {
				if (arr[i] < min)
					arr[i] = min;
				if (arr[i] > max)
					arr[i] = max;
			}
			return *this;
		}
		Dataset wrap(int min, int max) {
			max++; // max is inclusive range
			int range = max - min;
			for (int i = 0; i < arr.size(); i++) {
				int v = arr[i];
				arr[i] = (((v - min) % range) + range) % range + min;
			}
			return *this;
		}
		Dataset modulo(int mod) {
			for (int i = 0; i < arr.size(); i++) {
				arr[i] = arr[i] % mod;
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