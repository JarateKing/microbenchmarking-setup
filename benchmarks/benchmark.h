#include <iostream>

// obtain a unique identifier
#define NEWNAME_CONCAT2(x,y) x##y
#define NEWNAME_CONCAT1(x,y) NEWNAME_CONCAT2(x,y)
#define NEWNAME NEWNAME_CONCAT1(bench, __COUNTER__)

#define BENCHMARK(id, data)                                    \
const bool NEWNAME = [](){                                     \
	std::string ID = #id ;                                     \
	struct Internals data internals;                           \
	std::cout << ID << ": " << internals.description << '\n';  \
	return 0;                                                  \
}();

