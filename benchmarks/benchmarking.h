#include "benchmarking_generators.h"
#include <functional>

#define DATASET_FUNC(f) [](int n) -> benchmarking::Data { return f; }

namespace benchmarking {
	struct Dataset {
		std::string name;
		std::function<Data(int)> generator;
	};
}
