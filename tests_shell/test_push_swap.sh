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
printf "$MAGENTA Testing input check \n"
./tests_shell/test_check_input.sh
./tests_shell/test_leaks.sh
printf "$DEF_COLOR"
if [ "$(uname -s)" = "Darwin" ]; then
  name="Mac"
else
  name="linux"
fi
./tests_shell/test_${name}.sh