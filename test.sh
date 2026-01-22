#!/bin/bash

# This test was created by sde-koni 42 student (Stijn De Koning)

# ./push_swap $(shuf -i 0-4000000 -n 10 | awk '{print $1 - 2000000}')
ITERATIONS=1000

MAX_OPS=0
echo "Running all 3 number combinations"
for a in {0..2}; do
	for b in {0..2}; do
		if [ "$a" -ne "$b" ]; then
			for c in {0..2}; do
				if [ "$a" -ne "$c" ] && [ "$b" -ne "$c" ]; then
					ARG="$a $b $c"
					OPS=$(./push_swap $ARG)
					COUNT=$(echo "$OPS" | wc -l)
					if [ "$ARG" = "0 1 2" ]; then
						CHECK=$(echo -n "$OPS" | ./checker_linux $ARG)
					else
						CHECK=$(echo "$OPS" | ./checker_linux $ARG)
					fi
					if [ "$CHECK" = "OK" ] || [ -z "$CHECK" ]; then
						if [ "$COUNT" -gt "$MAX_OPS" ]; then
							MAX_OPS=$COUNT
							MAX_ARG="$ARG"
						fi
					else
						echo "Failed! with $ARG"
					fi
				fi
			done
		fi
	done
done
echo "Max 3 number operation = $MAX_OPS with $MAX_ARG"

MAX_OPS=0
echo "Running all 5 number combinations"
for a in {0..4}; do
	for b in {0..4}; do
		if [ "$a" -ne "$b" ]; then
			for c in {0..4}; do
				if [ "$a" -ne "$c" ] && [ "$b" -ne "$c" ]; then
					for d in {0..4}; do
						if [ "$a" -ne "$d" ] && [ "$b" -ne "$d" ] && [ "$c" -ne "$d" ]; then
							for e in {0..4}; do
								if [ "$a" -ne "$e" ] && [ "$b" -ne "$e" ] && [ "$c" -ne "$e" ] && [ "$d" -ne "$e" ]; then
									ARG="$a $b $c $d $e"
									OPS=$(./push_swap $ARG)
									COUNT=$(echo "$OPS" | wc -l)
									if [ "$ARG" = "0 1 2 3 4" ]; then
										CHECK=$(echo -n "$OPS" | ./checker_linux $ARG)
									else
										CHECK=$(echo "$OPS" | ./checker_linux $ARG)
									fi
									if [ "$CHECK" = "OK" ] || [ -z "$CHECK" ]; then
										if [ "$COUNT" -gt "$MAX_OPS" ]; then
											MAX_OPS=$COUNT
											MAX_ARG="$ARG"
										fi
									else
										echo "Failed! with "$ARG
									fi
								fi
							done
						fi
					done
				fi
			done
		fi
	done
done
echo "Max 5 number operation = $MAX_OPS with: $MAX_ARG"

MAX_OPS=0
echo "Running $ITERATIONS 100 number combinations"
for ((i=0; i<ITERATIONS; i++)) do
	ARG=$(shuf -i 0-4000000 -n 100 | awk '{print $1 - 2000000}' | tr '\n' ' ')
	OPS=$(./push_swap $ARG)
	COUNT=$(echo "$OPS" | wc -l)
	CHECK=$(echo "$OPS" | ./checker_linux $ARG)
	if [ "$CHECK" = "OK" ] || [ -z "$CHECK" ]; then
		if [ "$COUNT" -gt "$MAX_OPS" ]; then
			MAX_OPS=$COUNT
			MAX_ARG="$ARG"
		fi
	else
		echo "Failed! with "$ARG
	fi
done
echo "Max 100 number operation = $MAX_OPS with: "$MAX_ARG

MAX_OPS=0
echo "Running $ITERATIONS 500 number combinations"
for ((i=0; i<ITERATIONS; i++)) do
	ARG=$(shuf -i 0-4000000 -n 500 | awk '{print $1 - 2000000}' | tr '\n' ' ')
	OPS=$(./push_swap $ARG)
	COUNT=$(echo "$OPS" | wc -l)
	CHECK=$(echo "$OPS" | ./checker_linux $ARG)
	if [ "$CHECK" = "OK" ] || [ -z "$CHECK" ]; then
		if [ "$COUNT" -gt "$MAX_OPS" ]; then
			MAX_OPS=$COUNT
			MAX_ARG="$ARG"
		fi
	else
		echo "Failed! with "$ARG
	fi
done
echo "Max 500 number operation = $MAX_OPS with:" $MAX_ARG
