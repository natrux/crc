#!/bin/bash

g++ -Wall -Wextra -I include -I declarations -o gen_tables gen_tables.cpp
mkdir -p tables/include/crc
mkdir -p tables/src
./gen_tables
g++ -Wall -Wextra -I include/ -I tables/include/ -o test test.cpp tables/src/*.cpp

