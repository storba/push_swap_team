#!/bin/bash

# Generate 100 random numbers between 0 and 5000 and store them in ARG
#ARG=$(shuf -i -5000-5000 -n 500)
echo "sort 5 elements"
for i in {1..100}; do
#ARG=$(gshuf -i 0-5000 -n 5)
ARG=$(seq -5000 5000 | gshuf -n 5 | tr '\n' ' ')
RES=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ "$RES" = "KO" ]; then 
        echo "KO"
    fi
NUM=$(./push_swap $ARG | wc -l)
if [ "$NUM" -gt 12 ]; then 
        echo "Instructions: $NUM"
        #echo "Array: $ARG"
fi
done

echo "sort 6 elements"
for i in {1..100}; do
RG=$(seq -5000 5000 | gshuf -n 6 | tr '\n' ' ')
RES=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ "$RES" = "KO" ]; then 
        echo "KO"
    fi
NUM=$(./push_swap $ARG | wc -l)
if [ "$NUM" -gt 12 ]; then 
        echo "Instructions: $NUM"
        #echo "Array: $ARG"
fi
done

echo "sort 100 elements"
for i in {1..100}; do
#ARG=$(gshuf -i 0-5000 -n 100)
ARG=$(seq -5000 5000 | gshuf -n 100 | tr '\n' ' ')
RES=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ "$RES" = "KO" ]; then 
        echo "KO"
    fi
NUM=$(./push_swap $ARG | wc -l)
if [ "$NUM" -gt 700 ]; then 
        echo "Instructions: $NUM"
        #echo "Array: $ARG"
    fi
done

echo "sort 500 elements"
for i in {1..150}; do
#ARG=$(gshuf -i 0-1000 -n 500)
ARG=$(seq -5000 5000 | gshuf -n 500 | tr '\n' ' ')
RES=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ "$RES" = "KO" ]; then 
        echo "KO"
    fi
NUM=$(./push_swap $ARG | wc -l)
if [ "$NUM" -gt 5500 ]; then 
        echo "Instructions: $NUM"
       # echo "Array: $ARG"
    fi
done
