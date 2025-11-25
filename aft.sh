./main $1 > temps/temp.ll

clang temps/temp.ll -o a.out
