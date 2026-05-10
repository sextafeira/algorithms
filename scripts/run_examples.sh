#!/usr/bin/env bash
set -euo pipefail

make all

echo "\n== Quick sort =="
printf "8\n9 4 1 7 3 8 2 5\n" | ./bin/sorting/quick_sort

echo "\n== Binary search =="
printf "5\n3 1 8 4 2\n4\n" | ./bin/search/binary_search

echo "\n== Recursive array operations =="
printf "5\n5 10 3 7 15\n5 1 3 7 2\n" | ./bin/arrays/recursive_array_operations

echo "\n== Poodle =="
printf "20 4\n143 10\n42 5\n80 3\n0 0\n" | ./bin/competitive_programming/poodle
