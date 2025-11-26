./main "$1" > temps/temp.ll
if [ $? -ne 0 ]; then exit 1; fi

llc -filetype=obj -relocation-model=pic temps/temp.ll -o temps/temp.o

clang++ temps/temp.o run_time/builtins.o external_functions/vector_runtime.o `llvm-config --ldflags --system-libs --libs core` -frtti -o a.out