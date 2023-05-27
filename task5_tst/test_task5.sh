#!/bin/sh

echo "Test 1"
./task5_tst/checker.bash --valgrind ./hsh ./task5_tst/env_one_var.bash
echo  "\n"
echo "Test 2"
./task5_tst/checker.bash --valgrind ./hsh ./task5_tst/env.bash
echo  "\n"
echo "Test 3"
./task5_tst/checker.bash --valgrind ./hsh ./task5_tst/env_ignore_env.bash
echo "\n"
