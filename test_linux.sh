#!/bin/bash
#valgrind --leak-check=full
# Generate 100 random numbers between 0 and 5000 and store them in ARG
#ARG=$(shuf -i -5000-5000 -n 500)
echo "sort 5 elements"
for i in {1..10}; do
#ARG=$(gshuf -i 0-5000 -n 5)
ARG=$(seq 0 1000 | shuf -n 5 | tr '\n' ' ')
RES=$(./push_swap  --simple $ARG | ./checker_linux $ARG)
if [ "$RES" = "KO" ]; then 
        echo "KO"
    fi
RES=$(./push_swap  --medium $ARG | ./checker_linux $ARG)
if [ "$RES" = "KO" ]; then 
        echo "KO"
    fi
RES=$(./push_swap  --complex $ARG | ./checker_linux $ARG)
if [ "$RES" = "KO" ]; then 
        echo "KO"
    fi

NUM=$(./push_swap --simple $ARG | wc -l)
#if [ "$NUM" -gt 12 ]; then 
        echo "Simple Instructions: $NUM"
        #echo "Array: $ARG"
#fi

NUM=$(./push_swap --complex $ARG | wc -l)
#if [ "$NUM" -gt 12 ]; then 
        echo "Complex Instructions: $NUM"
        #echo "Array: $ARG"
#fi

NUM=$(./push_swap --medium $ARG | wc -l)
#if [ "$NUM" -gt 12 ]; then 
        echo "Medium Instructions: $NUM"

NUM=$(./push_swap --adaptive $ARG | wc -l)
#if [ "$NUM" -gt 12 ]; then 
        echo "Adaptive Instructions: $NUM"
done

echo "sort 6 elements"
for i in {1..10}; do
RG=$(seq -5000 5000 | shuf -n 6 | tr '\n' ' ')
RES=$(./push_swap $ARG | ./checker_linux $ARG)
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
for i in {1..10}; do
#ARG=$(gshuf -i 0-5000 -n 100)
ARG=$(seq -5000 5000 | shuf -n 100 | tr '\n' ' ')
RES=$(./push_swap $ARG | ./checker_linux $ARG)
if [ "$RES" = "KO" ]; then 
        echo "KO"
    fi
NUM=$(./push_swap $ARG | wc -l)
if [ "$NUM" -gt 700 ]; then 
        echo "Instructions: $NUM"
        #echo "Array: $ARG"
    fi
done

echo "sort 200 elements"
for i in {1..10}; do
#ARG=$(gshuf -i 0-1000 -n 500)
ARG=$(seq -2000 2000 | shuf -n 200 | tr '\n' ' ')
RES=$(./push_swap $ARG | ./checker_linux $ARG)
if [ "$RES" = "KO" ]; then 
        echo "KO"
    fi
NUM=$(./push_swap $ARG | wc -l)
echo "Instructions: $NUM"
if [ "$NUM" -gt 5500 ]; then 
        echo "Too much!!!!: $NUM"
       # echo "Array: $ARG"
fi
done
