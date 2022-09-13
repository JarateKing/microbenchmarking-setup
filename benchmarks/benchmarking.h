#include "benchmarking_generators.h"
#include <functional>

namespace benchmarking {
	struct Dataset {
		std::string name;
		std::function<Data(int)> generator;
	};
}
