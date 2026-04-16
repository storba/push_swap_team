#!/bin/bash

echo "sort 3 elements"
for i in {1..500}; do
ARG=$(seq -5000 5000 | gshuf -n 3 | tr '\n' ' ')
RES=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ "$RES" = "KO" ]; then 
        echo "KO"
fi
done

echo "sort 4 elements"
for i in {1..500}; do
ARG=$(seq -5000 5000 | gshuf -n 4 | tr '\n' ' ')
RES=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ "$RES" = "KO" ]; then 
        echo "KO"
fi
done

# Generate 100 random numbers between 0 and 5000 and store them in ARG
#ARG=$(shuf -i -5000-5000 -n 500)
echo "sort 5 elements"
for i in {1..500}; do
#ARG=$(gshuf -i 0-5000 -n 5)
ARG=$(seq -5000 5000 | gshuf -n 5 | tr '\n' ' ')
RES=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ "$RES" = "KO" ]; then 
        echo "KO"
    fi
NUM=$(./push_swap $ARG | wc -l)
#echo "Instructions: $NUM"
if [ "$NUM" -gt 12 ]; then 
        echo "Instructions: $NUM"
        #echo "Array: $ARG"
fi
done

echo "sort 6 elements"
for i in {1..500}; do
ARG=$(seq -5000 5000 | gshuf -n 6 | tr '\n' ' ')
RES=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ "$RES" = "KO" ]; then 
        echo "KO"
fi
done

echo "sort 10 elements"
for i in {1..500}; do
ARG=$(seq -5000 5000 | gshuf -n 10 | tr '\n' ' ')
RES=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ "$RES" = "KO" ]; then 
        echo "KO"
fi
done

echo "sort 20 elements"
for i in {1..100}; do
ARG=$(seq -5000 5000 | gshuf -n 20 | tr '\n' ' ')
RES=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ "$RES" = "KO" ]; then 
        echo "KO"
fi
done

echo "sort 50 elements"
for i in {1..100}; do
ARG=$(seq -5000 5000 | gshuf -n 50 | tr '\n' ' ')
RES=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ "$RES" = "KO" ]; then 
        echo "KO"
fi
done

echo "sort 100 elements"
for i in {1..1000}; do
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
echo "Numbers:" > numb.txt
echo $(date)
echo "sort 500 elements"
for i in {1..2000}; do
#ARG=$(gshuf -i 0-1000 -n 500)
ARG=$(seq -2000 2000 | gshuf -n 500 | tr '\n' ' ')
RES=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ "$RES" = "KO" ]; then 
        echo "KO"
    fi
NUM=$(./push_swap $ARG | wc -l)
echo "$NUM" >> numb.txt
if [ "$NUM" -gt 5500 ]; then 
        echo "Too much!!!!: $NUM"
        echo "Array: $ARG"
fi
done
echo $(date)
echo "sort positive 500 elements"
for i in {1..2000}; do
ARG=$(gshuf -i 0-2000 -n 500 | tr '\n' ' ')
RES=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ "$RES" = "KO" ]; then 
        echo "KO"
    fi
NUM=$(./push_swap $ARG | wc -l)
echo "$NUM" >> numb.txt
if [ "$NUM" -gt 5500 ]; then 
        echo "Too much!!!!: $NUM"
        echo "Array: $ARG"
fi
done
echo $(date)
