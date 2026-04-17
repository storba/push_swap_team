#!/bin/bash
valgrind --leak-check=full ./push_swap 2>&1 | tee leaks.txt
grep "definitely lost: 0 bytes in 0 blocks" leaks.txt
