#include <iostream>
#include <chrono>
#include <iomanip>

// obtain a unique identifier
#define NEWNAME_CONCAT2(x,y) x##y
#define NEWNAME_CONCAT1(x,y) NEWNAME_CONCAT2(x,y)
#define NEWNAME NEWNAME_CONCAT1(bench, __COUNTER__)

// benchmark method
#define BENCHMARK(id, data)                                                                   \
const bool NEWNAME = [](){                                                                    \
	std::string ID = #id ;                                                                    \
	struct Internals data internals;                                                          \
																							  \
	for (int i = 0; i < 5; i++) {                                                             \
		internals.Pre();                                                                      \
		internals.Run();                                                                      \
		internals.Post();                                                                     \
	}                                                                                         \
																							  \
	std::chrono::high_resolution_clock::time_point t1, t2;                                    \
	long double avg = 0;                                                                      \
	for (int i = 0; i < 200; i++) {                                                           \
		internals.Pre();                                                                      \
																							  \
		t1 = std::chrono::high_resolution_clock::now();                                       \
		internals.Run();                                                                      \
		t2 = std::chrono::high_resolution_clock::now();                                       \
		avg += std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();         \
																							  \
		internals.Post();                                                                     \
	}                                                                                         \
																							  \
	std::cout << std::setprecision(40);										  				  \
	std::cout << ID << ": " << avg / 200 << '\n';                                             \
	return 0;                                                                                 \
}();

