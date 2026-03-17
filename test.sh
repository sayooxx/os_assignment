#!/bin/bash

gcc sjf.c -o sjf

pass=true

echo "Running visible test cases..."

for i in testcases/input*.txt
do
    num=$(basename $i | grep -o '[0-9]*')
    
    ./sjf < $i > result.txt
    
    diff -w -B result.txt testcases/output$num.txt > /dev/null
    
    if [ $? -eq 0 ]; then
        echo "Test $num Passed ✅"
    else
        echo "Test $num Failed ❌"
        pass=false
    fi
done


if [ "$pass" = true ]; then
    echo "All tests passed 🎉"
    exit 0
else
    echo "Some tests failed ❌"
    exit 1
fi