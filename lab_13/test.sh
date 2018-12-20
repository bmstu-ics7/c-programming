#!/bin/sh

RED='\033[0;31m'
GREEN='\033[0;32m'

make ftest > /dev/null
./ftest.exe > /dev/null

if [[ $(cat result_test.out) == $(cat answer_test.txt) ]]; then
    echo "${GREEN}SUCCESS"
else
    echo "${RED}FAILED"
fi

make clean > /dev/null

