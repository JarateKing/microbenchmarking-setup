#include <iostream>
#include <chrono>
#include <iomanip>
#include <cfloat>

// obtain a unique identifier
#define NEWNAME_CONCAT2(x,y) x##y
#define NEWNAME_CONCAT1(x,y) NEWNAME_CONCAT2(x,y)
#define NEWNAME NEWNAME_CONCAT1(bench, __COUNTER__)

// benchmark method
#define BENCHMARK(id, data)                                                                         \
const bool NEWNAME = [](){                                                                          \
    std::string ID = #id ;                                                                          \
    struct Internals data internals;                                                                \
    std::cout << ID << '\n';                                                                        \
	std::cout << std::fixed << std::setprecision(0);                                                \
																									\
	for (unsigned long long n = MINN; n <= MAXN; n *= MULTN) {                                      \
		std::cout << n << ' ';                                                                      \
	}                                                                                               \
	std::cout << '\n';                                                                              \
																									\
	for (unsigned long long n = MINN; n <= MAXN; n *= MULTN) {                                      \
		for (int i = 0; i < 2; i++) {                                                               \
			internals.Pre(n);                                                                       \
			internals.Run(n);                                                                       \
			internals.Post(n);                                                                      \
		}                                                                                           \
																									\
		std::chrono::high_resolution_clock::time_point t1, t2;                                      \
		long double time = 0;                                                                       \
		for (int i = 0; i < 99; i++) {                                                              \
			internals.Pre(n);                                                                       \
																									\
			t1 = std::chrono::high_resolution_clock::now();                                         \
			internals.Run(n);                                                                       \
			t2 = std::chrono::high_resolution_clock::now();                                         \
			time = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();           \
																									\
			if (time == 0)                                                                          \
				std::cout << "0.000001 ";                                                           \
			else                                                                                    \
			    std::cout << time << ' ';                                                           \
																									\
			internals.Post(n);                                                                      \
		}                                                                                           \
		std::cout << '\n';                                                                          \
	}                                                                                               \
																									\
    return 0;                                                                                       \
}();

