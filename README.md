# Microbenchmarking Setup in C++

A microbenchmarking setup intended to be quick and easy to use, to quickly and easily create a microbenchmark to compare runtime performance between algorithms.

## How To

1. Create file with the relevant benchmark utilities:

```
// include these
#include "benchmark.h"
#include "benchmark_options.h"

// 
BENCHMARK( Example One, {
	// metadata
	std::string description = "Description for Example One";
	
	// methods
	void Pre(unsigned long long n) {
		// setup before running
	}
	void Run(unsigned long long  n) {
		// thing to benchmark
	}
	void Post(unsigned long long  n) {
		// cleanup after running
	}
});
```

2. Modify `benchmark_options.h` as needed. This controls things like how many iterations to run of a test, or how big the maximum size of `n` is.

3. Compile all source files:

```
g++ -g -O2 -std=gnu++17 -static benchmark.cpp example1.cpp example2.cpp
```

4. Run the compiled program, piping its output to `plot.py`:

```
./a.exe | python plot.py
```

This both saves the plot as an image and showcases it on your screen.
