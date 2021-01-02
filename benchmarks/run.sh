g++ -g -O2 -std=gnu++17 -static benchmark.cpp example1.cpp example2.cpp
./a.exe > data.out
python plot.py < data.out
