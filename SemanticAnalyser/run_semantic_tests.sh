#!/bin/bash

pass=0
fail=0

for file in testcases/semantic_checks/*.af; do
    filename=$(basename "$file")

    # Grab expected errors anywhere in the file, strip prefixes/spaces
    mapfile -t expected_errors < <(grep -E "^// ?Expected error:" "$file" | sed -e 's;// ?Expected error:;;' -e 's/^[[:space:]]*//' -e 's/[[:space:]]*$//')

    # Recognize "No semantic errors" comments anywhere
    mapfile -t expected_no_errors < <(grep -Ei "^// ?Expected(:| error:)[ ]*No semantic errors" "$file")

    # All actual semantic errors from compiler output, stripped
    output=$(./aft.sh "$file" 2>&1)
    mapfile -t actual_errors < <(echo "$output" | grep "\[semantic\] error" | sed 's/^[^:]*error: //')

    test_status="PASSED"

    if [[ ${#expected_no_errors[@]} -gt 0 ]]; then
        if [[ ${#actual_errors[@]} -eq 0 ]]; then
            test_status="PASSED"
        else
            test_status="FAILED"
        fi
    elif [[ ${#expected_errors[@]} -gt 0 ]]; then
        # Match number and text in order, strip whitespace for both
        if [[ ${#expected_errors[@]} -ne ${#actual_errors[@]} ]]; then
            test_status="FAILED"
        else
            for i in "${!expected_errors[@]}"; do
                exp="${expected_errors[$i]}"
                act="$(echo "${actual_errors[$i]}" | sed 's/^[[:space:]]*//;s/[[:space:]]*$//')"
                expnocomment="$(echo "$exp" | sed 's;^// *Expected error: *;;' )"
                if [[ "$act" != "$expnocomment" ]]; then
                    test_status="FAILED"
                    break
                fi
            done
        fi
    else
        # No expectation, generic
        if [[ ${#actual_errors[@]} -gt 0 ]]; then
            test_status="PASSED"
        else
            test_status="FAILED"
        fi
    fi

    if [[ $test_status == "PASSED" ]]; then
        echo "$filename PASSED"
        ((pass++))
    else
        echo "$filename FAILED"
        ((fail++))
    fi
done

echo "========================================"
echo "Summary: $pass passed, $fail failed, total $((pass+fail)) tests."
echo "========================================"

if [[ $fail -eq 0 ]]; then
    exit 0
else
    exit 1
fi
