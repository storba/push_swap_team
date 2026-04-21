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

PUSHSWAP="./push_swap"
CHECKEr="./CHECKER"

printf "$BLUE Testing memory leaks for ./push_swap \n"
printf "$DEF_COLOR"
printf "$GRAY test 1: ./push_swap with no arguments$DEF_COLOR   "
ARG=$(seq 0 100 | shuf -n 5 | tr '\n' ' ')
valgrind --leak-check=full --error-exitcode=42 $PUSHSWAP 2> leaks.txt >/dev/null
vg=$?
if grep -qF "in use at exit: 0 bytes in 0 blocks" leaks.txt \
  && grep -qF "ERROR SUMMARY: 0 errors from 0 contexts" leaks.txt; then
  printf "$GREEN OK$DEF_COLOR\n"
else
  printf  "$RED KO$DEF_COLOR\n"
fi

printf "$GRAY test 2: ./push_swap with 5 random numbers$DEF_COLOR   "
ARG=$(seq 0 100 | shuf -n 5 | tr '\n' ' ')
valgrind --leak-check=full --error-exitcode=42 $PUSHSWAP $ARG 2> leaks.txt >/dev/null
vg=$?
if  grep -qF "in use at exit: 0 bytes in 0 blocks" leaks.txt \
  && grep -qF "ERROR SUMMARY: 0 errors from 0 contexts" leaks.txt; then
  printf "$GREEN OK$DEF_COLOR\n"
else
  printf  "$RED KO$DEF_COLOR\n"
fi

printf "$GRAY test 2: ./push_swap with dubble arguments$DEF_COLOR   "
ARG="1 2 1 2"
valgrind --leak-check=full --error-exitcode=42 $PUSHSWAP $ARG 2> leaks.txt >/dev/null
vg=$?
if grep -qF "in use at exit: 0 bytes in 0 blocks" leaks.txt \
  && grep -qF "ERROR SUMMARY: 0 errors from 0 contexts" leaks.txt; then
  printf "$GREEN OK$DEF_COLOR\n"
else
  printf  "$RED KO$DEF_COLOR\n"
fi

printf "$GRAY test 3: ./push_swap with incorrect arguments$DEF_COLOR   "
ARG="1 2 aaa 5"
valgrind --leak-check=full --error-exitcode=42 $PUSHSWAP $ARG 2> leaks.txt >/dev/null
vg=$?
if grep -qF "in use at exit: 0 bytes in 0 blocks" leaks.txt \
  && grep -qF "ERROR SUMMARY: 0 errors from 0 contexts" leaks.txt; then
  printf "$GREEN OK$DEF_COLOR\n"
else
  printf  "$RED KO$DEF_COLOR\n"
fi

printf "$GRAY test 4: ./push_swap with sorted arguments$DEF_COLOR   "
ARG="1 2 3 4 5 6 7 8 9 10"
valgrind --leak-check=full --error-exitcode=42 $PUSHSWAP $ARG 2> leaks.txt >/dev/null
vg=$?
if grep -qF "in use at exit: 0 bytes in 0 blocks" leaks.txt \
  && grep -qF "ERROR SUMMARY: 0 errors from 0 contexts" leaks.txt; then
  printf "$GREEN OK$DEF_COLOR\n"
else
  printf  "$RED KO$DEF_COLOR\n"
fi

ARG=$(seq -2000 2000 | shuf -n 100 | tr '\n' ' ')
printf "$GRAY test 5: ./push_swap with 100 args$DEF_COLOR   "
valgrind --leak-check=full --error-exitcode=42 $PUSHSWAP $ARG 2> leaks.txt >/dev/null
vg=$?
if grep -qF "in use at exit: 0 bytes in 0 blocks" leaks.txt \
  && grep -qF "ERROR SUMMARY: 0 errors from 0 contexts" leaks.txt; then
  printf "$GREEN OK$DEF_COLOR\n"
else
  printf  "$RED KO$DEF_COLOR\n"
fi


ARG=$(seq -2000 2000 | shuf -n 500 | tr '\n' ' ')
printf "$GRAY test 5: ./push_swap with 500 args$DEF_COLOR   "
valgrind --leak-check=full --error-exitcode=42 $PUSHSWAP $ARG 2> leaks.txt >/dev/null
vg=$?
if grep -qF "in use at exit: 0 bytes in 0 blocks" leaks.txt \
  && grep -qF "ERROR SUMMARY: 0 errors from 0 contexts" leaks.txt; then
  printf "$GREEN OK$DEF_COLOR\n"
else
  printf  "$RED KO$DEF_COLOR\n"
fi
#2> bench.txt 1> /dev/null