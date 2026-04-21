#!/bin/bash
#-----CLRS -------#
DEF_COLOR='\033[0;39m'
BLACK='\033[0;30m'
RED='\033[1;91m'
GREEN='\033[1;92m'
YELLOW='\033[0;93m'
BLUE='\033[0;94m'
MAGENTA='\033[0;95m'
CYAN='\033[0;96m'
GRAY='\033[0;90m'
WHITE='\033[0;97m'

printf "$MAGENTA sort 5 elements 5 4 3 2 1\n"
printf "=====================================\n"
ARG="5 4 3 2 1"
printf $DEF_COLOR" $ARG \n"

RES=$(./push_swap  --simple $ARG | ./checker_linux $ARG)
printf $DEF_COLOR"simple "
if [ "$RES" = "KO" ]; then 
        printf $RED"KO\n"
else
        printf $GREEN"OK\n"
fi


RES=$(./push_swap  --medium $ARG | ./checker_linux $ARG)
printf $DEF_COLOR"medium "
if [ "$RES" = "KO" ]; then 
        printf $RED"KO\n"
else
        printf $GREEN"OK\n"
fi

RES=$(./push_swap  --complex $ARG | ./checker_linux $ARG)
printf $DEF_COLOR"complex "
if [ "$RES" = "KO" ]; then 
        printf $RED"KO\n"
else
        printf $GREEN"OK\n"
fi
RES=$(./push_swap  --adaptive $ARG | ./checker_linux $ARG)
printf $DEF_COLOR"adaptive"
if [ "$RES" = "KO" ]; then 
        printf $RED"KO\n"
else
        printf $GREEN"OK\n"
fi

printf $DEF_COLOR"without flag"
./push_swap --bench $ARG 2> bench.txt 1> /dev/null
cat bench.txt |grep "Adaptive"


printf "$MAGENTA sort 5 elements \n"
printf "=====================================\n"
for i in {1..10}; do
ARG=$(seq 0 100 | shuf -n 5 | tr '\n' ' ')
printf $DEF_COLOR"$i ) $ARG \n"

RES=$(./push_swap  --simple $ARG | ./checker_linux $ARG)
printf $DEF_COLOR"simple "
if [ "$RES" = "KO" ]; then 
        printf $RED"KO\n"
else
        printf $GREEN"OK\n"
fi


RES=$(./push_swap  --medium $ARG | ./checker_linux $ARG)
printf $DEF_COLOR"medium "
if [ "$RES" = "KO" ]; then 
        printf $RED"KO\n"
else
        printf $GREEN"OK\n"
fi

RES=$(./push_swap  --complex $ARG | ./checker_linux $ARG)
printf $DEF_COLOR"complex "
if [ "$RES" = "KO" ]; then 
        printf $RED"KO\n"
else
        printf $GREEN"OK\n"
fi
RES=$(./push_swap  --adaptive $ARG | ./checker_linux $ARG)
printf $DEF_COLOR"adaptive"
if [ "$RES" = "KO" ]; then 
        printf $RED"KO\n"
else
        printf $GREEN"OK\n"
fi
done

for i in {1..10}; do
ARG=$(seq 0 100 | shuf -n 5 | tr '\n' ' ')
printf $DEF_COLOR"$i ) $ARG \n"
printf $CYAN
./push_swap --simple --bench $ARG 2> bench.txt 1> /dev/null
cat bench.txt | grep "disorder"
printf $DEF_COLOR
NUM=$(./push_swap --simple $ARG | wc -l)
        echo "Simple: $NUM"

NUM=$(./push_swap --medium $ARG | wc -l)
        echo "Medium: $NUM"

NUM=$(./push_swap --complex $ARG | wc -l)
        echo "Complex: $NUM"


NUM=$(./push_swap --adaptive $ARG | wc -l) 
        echo "Adaptive: $NUM"

done

printf "$MAGENTA sort 6 elements\n"
printf "=====================================\n"
for i in {1..10}; do
ARG=$(seq 0 1000 | shuf -n 6 | tr '\n' ' ')
printf "$DEF_COLOR $i ) $ARG \n"

RES=$(./push_swap  --simple $ARG | ./checker_linux $ARG)
printf $DEF_COLOR"simple "
if [ "$RES" = "KO" ]; then 
        printf $RED"KO\n"
else
        printf $GREEN"OK\n"
fi


RES=$(./push_swap  --medium $ARG | ./checker_linux $ARG)
printf $DEF_COLOR"medium "
if [ "$RES" = "KO" ]; then 
        printf $RED"KO\n"
else
        printf $GREEN"OK\n"
fi

RES=$(./push_swap  --complex $ARG | ./checker_linux $ARG)
printf $DEF_COLOR"complex "
if [ "$RES" = "KO" ]; then 
        printf $RED"KO\n"
else
        printf $GREEN"OK\n"
fi
RES=$(./push_swap  --adaptive $ARG | ./checker_linux $ARG)
printf $DEF_COLOR"adaptive"
if [ "$RES" = "KO" ]; then 
        printf $RED"KO\n"
else
        printf $GREEN"OK\n"
fi
done

for i in {1..10}; do
ARG=$(seq 0 1000| shuf -n 6 | tr '\n' ' ')
printf "$DEF_COLOR$i ) $ARG \n"
printf $CYAN
./push_swap --simple --bench $ARG 2> bench.txt 1> /dev/null
cat bench.txt | grep "disorder"
printf $DEF_COLOR
NUM=$(./push_swap --simple $ARG | wc -l)
        echo "Simple: $NUM"

NUM=$(./push_swap --medium $ARG | wc -l)
        echo "Medium: $NUM"

NUM=$(./push_swap --complex $ARG | wc -l)
        echo "Complex: $NUM"


NUM=$(./push_swap --adaptive $ARG | wc -l) 
        echo "Adaptive: $NUM"

done

printf "$MAGENTA sort 100 elements\n"
printf "=====================================\n"
for i in {1..10}; do
ARG=$(seq -5000 5000 | shuf -n 100 | tr '\n' ' ')
printf "$DEF_COLOR $i ) \n"

RES=$(./push_swap  --simple $ARG | ./checker_linux $ARG)
printf $DEF_COLOR"simple "
if [ "$RES" = "KO" ]; then 
        printf $RED"KO\n"
else
        printf $GREEN"OK\n"
fi


RES=$(./push_swap  --medium $ARG | ./checker_linux $ARG)
printf $DEF_COLOR"medium "
if [ "$RES" = "KO" ]; then 
        printf $RED"KO\n"
else
        printf $GREEN"OK\n"
fi

RES=$(./push_swap  --complex $ARG | ./checker_linux $ARG)
printf $DEF_COLOR"complex "
if [ "$RES" = "KO" ]; then 
        printf $RED"KO\n"
else
        printf $GREEN"OK\n"
fi
RES=$(./push_swap  --adaptive $ARG | ./checker_linux $ARG)
printf $DEF_COLOR"adaptive"
if [ "$RES" = "KO" ]; then 
        printf $RED"KO\n"
else
        printf $GREEN"OK\n"
fi
done

for i in {1..10}; do
ARG=$(seq -2000 2000 | shuf -n 100 | tr '\n' ' ')
printf "$DEF_COLOR$i )  \n"
printf $CYAN
./push_swap --simple --bench $ARG 2> bench.txt 1> /dev/null
cat bench.txt | grep "disorder"
printf $DEF_COLOR
NUM=$(./push_swap --simple $ARG | wc -l)
        echo "Simple: $NUM"

NUM=$(./push_swap --medium $ARG | wc -l)
        echo "Medium: $NUM"

NUM=$(./push_swap --complex $ARG | wc -l)
        echo "Complex: $NUM"


NUM=$(./push_swap --adaptive $ARG | wc -l) 
        echo "Adaptive: $NUM"

done

printf "$MAGENTA sort 500 elements \n"
printf "=====================================\n"

or i in {1..10}; do
ARG=$(seq -5000 5000 | shuf -n 500 | tr '\n' ' ')
printf "$DEF_COLOR $i ) \n"

RES=$(./push_swap  --simple $ARG | ./checker_linux $ARG)
printf $DEF_COLOR"simple "
if [ "$RES" = "KO" ]; then 
        printf $RED"KO\n"
else
        printf $GREEN"OK\n"
fi


RES=$(./push_swap  --medium $ARG | ./checker_linux $ARG)
printf $DEF_COLOR"medium "
if [ "$RES" = "KO" ]; then 
        printf $RED"KO\n"
else
        printf $GREEN"OK\n"
fi

RES=$(./push_swap  --complex $ARG | ./checker_linux $ARG)
printf $DEF_COLOR"complex "
if [ "$RES" = "KO" ]; then 
        printf $RED"KO\n"
else
        printf $GREEN"OK\n"
fi
RES=$(./push_swap  --adaptive $ARG | ./checker_linux $ARG)
printf $DEF_COLOR"adaptive"
if [ "$RES" = "KO" ]; then 
        printf $RED"KO\n"
else
        printf $GREEN"OK\n"
fi
done

for i in {1..10}; do
ARG=$(seq -2000 2000 | shuf -n 500 | tr '\n' ' ')
printf "$DEF_COLOR$i )  \n"
printf $CYAN
./push_swap --simple --bench $ARG 2> bench.txt 1> /dev/null
cat bench.txt | grep "disorder"
printf $DEF_COLOR
NUM=$(./push_swap --simple $ARG | wc -l)
        echo "Simple: $NUM"

NUM=$(./push_swap --medium $ARG | wc -l)
        echo "Medium: $NUM"

NUM=$(./push_swap --complex $ARG | wc -l)
        echo "Complex: $NUM"


NUM=$(./push_swap --adaptive $ARG | wc -l) 
        echo "Adaptive: $NUM"

done


: << 'END'
echo "-------------------"
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
END