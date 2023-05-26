#!/bin/sh

echo "Test 1"
./task4_tst/checker.bash --valgrind ./hsh ./task4_tst/exit_no_arg.bash
echo  "\n"
echo "Test 2"
./task4_tst/checker.bash --valgrind ./hsh ./task4_tst/exit_no_arg_1.bash
echo  "\n"
