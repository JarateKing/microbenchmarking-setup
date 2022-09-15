# Microbenchmarking Setup in C++

A microbenchmarking setup intended to be quick and easy to use, to quickly and easily create a microbenchmark to compare runtime performance between algorithms.

## How To

1. Create file with the relevant benchmark utilities and setup:

```
#include "src/benchmarking.h"

std::vector<benchmarking::Dataset> datasets = {
    {
        "Random",
        DATASET_FUNC( benchmarking::random(n).wrap(0,n-1) ),
    },
    {
        "Sorted", 
        DATASET_FUNC( benchmarking::index(n) ),
    },
};

std::vector<benchmarking::Algorithm> algorithms = {
    {
        "std::sort",
        ALGO_SETUP(),
        ALGO_BENCHMARK( std::sort(arr.begin(), arr.end()); ),
        ALGO_CLEANUP(),
    },
    {
        "std::stable_sort",
        ALGO_SETUP(),
        ALGO_BENCHMARK( std::stable_sort(arr.begin(), arr.end()); ),
        ALGO_CLEANUP(),
    },
};

int main() {
    benchmarking::setup();
    
    benchmarking::Options options;
    options.measured_runs = 25;
    options.target_runtime = 0.1;
    options.n = {10, 100, 1000, 10000, 100000, 1000000, 10000000};
    options.isMutable = true;
    
    benchmarking::run(options, datasets, algorithms);
}
```

2. Compile source file:

```
g++ -g -O2 -std=gnu++17 -static example.cpp
```

3. Run the compiled program, piping its output to `plot.py`:

```
./a.exe | python plot.py
```

This will present you with multiple plots (one for each dataset) which you can either view or save.
