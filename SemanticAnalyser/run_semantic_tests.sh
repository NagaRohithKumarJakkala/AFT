#!/bin/bash

pass=0
fail=0

for i in {1..17}; do
    file="testcases/semantic_checks/semantic_test${i}.af"
    
    echo "Running $file"
    output=$(./aft.sh "$file" 2>&1)
    
    # Extract expected from first comment line: // Expected ... (using grep and sed)
    expected=$(head -3 "$file" | grep "// Expected error" | sed 's;^// Expected:;;g' | xargs)
    
    if echo "$output" | grep -q "\[semantic\] error"; then
        if [[ "$expected" == *"error"* ]]; then
            echo "Test $i PASSED (Expected error)"
            ((pass++))
        else
            echo "Test $i FAILED (Unexpected errors)"
            echo "$output"
            ((fail++))
        fi
    else
        if [[ "$expected" == *"No semantic errors"* ]]; then
            echo "Test $i PASSED (No errors as expected)"
            ((pass++))
        else
            echo "Test $i FAILED (Expected errors but none found)"
            ((fail++))
        fi
    fi
    
    echo ""
done

echo "Summary: $pass passed, $fail failed, total $((pass+fail)) tests."
if [[ "$fail" -eq 0 ]]; then
    exit 0
else
    exit 1
fi
