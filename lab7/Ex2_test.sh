test_cases=100;
passed_cases=0;
failed_cases=0;

for ((i = 1; i <= test_cases; i++)); do
	./Exercise2 > Ex2_output.txt
	if cmp -s "Ex2_control.txt" "Ex2_output.txt"; then
		((passed_cases++))
	else
		((failed_cases++))
	fi
done

printf "%d cases were tested\n" "$test_cases"
printf "Tests passed: %d\n" "$passed_cases"
printf "Tests failed: %d\n" "$failed_cases"
