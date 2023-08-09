# CMake generated Testfile for 
# Source directory: /home/hale/Desktop/Linux-Learning/cmake-learning/Introduction/Demo8
# Build directory: /home/hale/Desktop/Linux-Learning/cmake-learning/Introduction/Demo8
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_run "Demo" "5" "2")
set_tests_properties(test_run PROPERTIES  _BACKTRACE_TRIPLES "/home/hale/Desktop/Linux-Learning/cmake-learning/Introduction/Demo8/CMakeLists.txt;41;add_test;/home/hale/Desktop/Linux-Learning/cmake-learning/Introduction/Demo8/CMakeLists.txt;0;")
add_test(test_usage "Demo")
set_tests_properties(test_usage PROPERTIES  PASS_REGULAR_EXPRESSION "Usage: .* base exponent" _BACKTRACE_TRIPLES "/home/hale/Desktop/Linux-Learning/cmake-learning/Introduction/Demo8/CMakeLists.txt;43;add_test;/home/hale/Desktop/Linux-Learning/cmake-learning/Introduction/Demo8/CMakeLists.txt;0;")
add_test(test_5_2 "Demo" "5" "2")
set_tests_properties(test_5_2 PROPERTIES  PASS_REGULAR_EXPRESSION "is 25" _BACKTRACE_TRIPLES "/home/hale/Desktop/Linux-Learning/cmake-learning/Introduction/Demo8/CMakeLists.txt;48;add_test;/home/hale/Desktop/Linux-Learning/cmake-learning/Introduction/Demo8/CMakeLists.txt;53;do_test;/home/hale/Desktop/Linux-Learning/cmake-learning/Introduction/Demo8/CMakeLists.txt;0;")
add_test(test_10_5 "Demo" "10" "5")
set_tests_properties(test_10_5 PROPERTIES  PASS_REGULAR_EXPRESSION "is 10000" _BACKTRACE_TRIPLES "/home/hale/Desktop/Linux-Learning/cmake-learning/Introduction/Demo8/CMakeLists.txt;48;add_test;/home/hale/Desktop/Linux-Learning/cmake-learning/Introduction/Demo8/CMakeLists.txt;54;do_test;/home/hale/Desktop/Linux-Learning/cmake-learning/Introduction/Demo8/CMakeLists.txt;0;")
add_test(test_2_10 "Demo" "2" "10")
set_tests_properties(test_2_10 PROPERTIES  PASS_REGULAR_EXPRESSION "is 1024" _BACKTRACE_TRIPLES "/home/hale/Desktop/Linux-Learning/cmake-learning/Introduction/Demo8/CMakeLists.txt;48;add_test;/home/hale/Desktop/Linux-Learning/cmake-learning/Introduction/Demo8/CMakeLists.txt;55;do_test;/home/hale/Desktop/Linux-Learning/cmake-learning/Introduction/Demo8/CMakeLists.txt;0;")
subdirs("math")
