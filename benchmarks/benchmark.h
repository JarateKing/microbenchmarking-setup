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
                                                                                                    \
    for (int i = 0; i < 5; i++) {                                                                   \
        internals.Pre();                                                                            \
        internals.Run();                                                                            \
        internals.Post();                                                                           \
    }                                                                                               \
                                                                                                    \
    std::chrono::high_resolution_clock::time_point t1, t2;                                          \
    long double average = 0, minimum = DBL_MAX, time = 0;                                           \
    for (int i = 0; i < 50; i++) {                                                                  \
        internals.Pre();                                                                            \
                                                                                                    \
        t1 = std::chrono::high_resolution_clock::now();                                             \
        internals.Run();                                                                            \
        t2 = std::chrono::high_resolution_clock::now();                                             \
        time = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();               \
        average += time;                                                                            \
        minimum = (time < minimum) ? time : minimum;                                                \
                                                                                                    \
        internals.Post();                                                                           \
    }                                                                                               \
                                                                                                    \
    average /= 50;                                                                                  \
    long double error = (average-minimum)/average*100;                                              \
    std::cout << std::setprecision(40);                                                             \
    std::cout.unsetf(std::ios_base::fixed);                                                         \
    std::cout << minimum << "ns +/- ";                                                              \
    std::cout << std::setprecision(1) << std::fixed << error << "%\n";                              \
    return 0;                                                                                       \
}();

