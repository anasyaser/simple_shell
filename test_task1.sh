#!/bin/sh

echo "Test 1"
./task1_tst/checker.bash ./hsh ./task1_tst/bin_ls.bash

echo "Test 2"
./task1_tst/checker.bash ./hsh ./task1_tst/bin_ls_3_times.bash

echo "Test 3"
./task1_tst/checker.bash ./hsh ./task1_tst/bin_ls_spaces.bash

echo "Test 4"
./task1_tst/checker.bash ./hsh ./task1_tst/ls_in_current_dir.bash

echo "Test 5"
./task1_tst/checker.bash ./hsh ./task1_tst/empty_input_small.bash

echo "Test 6"
./task1_tst/checker.bash ./hsh ./task1_tst/empty_input_medium.bash

echo "Test 7"
./task1_tst/checker.bash ./hsh ./task1_tst/empty_input_large.bash

