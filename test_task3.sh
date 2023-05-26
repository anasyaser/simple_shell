#!/bin/sh

echo "Test 1"
./task1_tst/checker.bash ./hsh ./task3_tst/ls_.bash
echo  "\n"
echo "Test 2"
./task1_tst/checker.bash ./hsh ./task3_tst/ls_in_two_parent_dir_2.bash
echo  "\n"
echo "Test 3"
./task1_tst/checker.bash ./hsh ./task3_tst/ls_1_arg.bash
echo  "\n"
echo "Test 4"
./task1_tst/checker.bash ./hsh ./task3_tst/bin_ls_1_arg_1.bash
echo  "\n"
echo "Test 5"
./task1_tst/checker.bash ./hsh ./task3_tst/ls_in_parent_dir.bash
echo  "\n"
echo "Test 6"
./task1_tst/checker.bash ./hsh ./task3_tst/ls_in_two_parent_dir.bash
echo  "\n"
echo "Test 7"
./task1_tst/checker.bash ./hsh ./task3_tst/ls_in_two_parent_dir_3.bash
echo  "\n"
echo "Test 8"
./task1_tst/checker.bash ./hsh ./task3_tst/bin_ls.bash
echo  "\n"
echo "Test 9"
./task1_tst/checker.bash ./hsh ./task3_tst/ls_path_bin_last.bash
echo  "\n"
echo "Test 10"
./task1_tst/checker.bash ./hsh ./task3_tst/bin_ls_large_input.bash
echo  "\n"
echo "Test 11"
./task1_tst/checker.bash ./hsh ./task3_tst/bin_ls_empty_path.bash
echo  "\n"
echo "Test 12"
./task1_tst/checker.bash ./hsh ./task3_tst/bin_ls_1_arg.bash
echo  "\n"
echo "Test 13"
./task1_tst/checker.bash ./hsh ./task3_tst/mix_ls_bin_ls_spaces.bash
echo  "\n"
echo "Test 14"
./task1_tst/checker.bash ./hsh ./task3_tst/ls_spaces.bash
echo  "\n"
echo "Test 15"
./task1_tst/checker.bash ./hsh ./task3_tst/bin_ls_spaces.bash
echo  "\n"
echo "Test 16"
./task1_tst/checker.bash ./hsh ./task3_tst/ls_in_current_dir.bash
echo  "\n"
echo "Test 17"
./task1_tst/checker.bash ./hsh ./task3_tst/ls_dot_ls.bash
echo  "\n"
echo "Test 18"
./task1_tst/checker.bash ./hsh ./task3_tst/env_ignore_ls.bash
echo  "\n"
echo "Test 19"
./task1_tst/checker.bash ./hsh ./task3_tst/mix_ls_bin_ls_spaces.bash
echo  "\n"
echo "Test 20"
./task1_tst/checker.bash ./hsh ./task3_tst/ls_path_bin_first.bash
echo  "\n"
echo "Test 21"
./task1_tst/checker.bash ./hsh ./task3_tst/env_ignore_bin_ls.bash
echo  "\n"
echo "Test 22"
./task1_tst/checker.bash ./hsh ./task3_tst/bin_ls_3_times.bash
echo  "\n"
echo "Test 23"
./task1_tst/checker.bash ./hsh ./task3_tst/bin_ls_medium_input.bash
echo  "\n"
echo "Test 24"
./task1_tst/checker.bash ./hsh ./task3_tst/mix_ls_bin_ls.bash
echo  "\n"
echo "Test 25"
./task1_tst/checker.bash ./hsh ./task3_tst/ls_path_no_bin.bash
echo  "\n"
echo "Test 26"
./task1_tst/checker.bash ./hsh ./task3_tst/ls_path_bin_middle.bash
echo  "\n"
echo "Test 27"
./task1_tst/checker.bash ./hsh ./task3_tst/empty_path_failing_cmd.bash
echo  "\n"
echo "Test 28"
./task1_tst/checker.bash ./hsh ./task3_tst/path_path1_var.bash
echo  "\n"
echo "Test 29"
./task1_tst/checker.bash ./hsh ./task3_tst/path_current_dir_ls.bash
echo  "\n"
echo "Test 30"
./task1_tst/checker.bash ./hsh ./task3_tst/unknown_command_no_fork.bash
echo  "\n"

