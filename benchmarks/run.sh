g++ -g -O2 -std=gnu++17 -static example.cpp
./a.exe > data.out
python plot.py < data.out
