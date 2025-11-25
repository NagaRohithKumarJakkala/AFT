#!/bin/bash

./main "$1" > temps/temp.ll

if [ $? -ne 0 ]; then
    exit 1
fi

clang temps/temp.ll -o a.out
