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

FILE=$PWD/push_swap
expected=$(printf 'Error\n')
return_promt=$(printf '\n')
printf "$BLUE Testing input check \n"
printf "$DEF_COLOR"

if [ -f "$FILE" ]; then
	echo -n
else
	printf "${RED}NO EXIST PUSH_SWAP PROGRAM ${DEF_COLOR}\n";
	exit 0
fi

#------test 1------
printf "$GRAY test 1: ./push_swap 1 2 1  - "
err=$(./push_swap 1 2 1 2>&1 >/dev/null)
code=$?
if [ "$err" = "$expected" ] && [ "$code" -eq 1 ]; then 
        printf "$GREEN OK\n"
else
    printf "$RED KO\n"
fi
#------test 2------
printf "$GRAY test 2: ./push_swap 1 2 aa  - "
err=$(./push_swap 1 2 aa 2>&1 >/dev/null)
code=$?
if [ "$err" = "$expected" ] && [ "$code" -eq 1 ]; then 
        printf "$GREEN OK\n"
else
    printf "$RED KO\n"
fi
#------test 3------
printf "$GRAY test 3: ./push_swap --aa 1 2 11 9  -"
err=$(./push_swap --aa 1 2 11 9  2>&1 >/dev/null)
code=$?
if [ "$err" = "$expected" ] && [ "$code" -eq 1 ]; then 
        printf "$GREEN OK\n"
else
    printf "$RED KO\n"
fi
#------test 4------
printf "$GRAY test 4: ./push_swap 1 2 9 7 3 3  - "
err=$( ./push_swap 1 2 9 7 3 3 2>&1 >/dev/null)
code=$?
if [ "$err" = "$expected" ] && [ "$code" -eq 1 ]; then 
        printf "$GREEN OK\n"
else
    printf "$RED KO\n"
fi

#------test 5------
printf "$GRAY test 5: ./push_swap  - "
res=$( ./push_swap  2>&1 >/dev/null)
code=$?
if [ "$res" = "$return_promt" ]; then 
        printf "$GREEN OK\n"
else
    printf "$RED KO\n"
fi
#------test 6------
printf "$GRAY test 6: ./push_swap 1 2 5 9 11 -"
res=$( ./push_swap 1 2 5 9 11 2>&1 >/dev/null)
code=$?
if [ "$res" = "$return_promt" ] && [ "$code" -eq 0 ]; then 
        printf "$GREEN OK\n"
else
    printf "$RED KO\n"
fi

#------test 7 MAXINT+1------
printf "$GRAY test 7 MAXINT+1: ./push_swap 1 2 5 2147483648 9 11 - "
res=$( ./push_swap 1 2 5 2147483648 9 11 2>&1 >/dev/null)
code=$?
if [ "$err" = "$expected" ] && [ "$code" -eq 1 ]; then 
        printf "$GREEN OK\n"
else
    printf "$RED KO\n"
fi

#------test 8------
printf "$GRAY test 8: MINIMUM-1./push_swap 1 2 5 -2147483649 9 11 -"
res=$( ./push_swap 1 2 5 -2147483649 9 11 2>&1 >/dev/null)
code=$?
if [ "$err" = "$expected" ] && [ "$code" -eq 1 ]; then 
        printf "$GREEN OK\n"
else
    printf "$RED KO\n"
fi
printf "$DEF_COLOR"