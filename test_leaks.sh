#!/bin/bash
ARG=$(seq 0 100 | shuf -n 5 | tr '\n' ' ')
#valgrind --leak-check=full ./push_swap $ARG 2>&1 | tee leaks.txt
valgrind --leak-check=full ./push_swap $ARG 2> leaks.txt 1> /dev/null
cat leaks.txt | grep "in use at exit: 0 bytes in 0 blocks"
cat leaks.txt | grep "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)" leaks.txt
#2> bench.txt 1> /dev/null