cmake_minimum_required(VERSION 3.5)

project(Demo5)

configure_file(
	"${PROJECT_SOURCE_DIR}/config.h.in"
	"${PROJECT_BINARY_DIR}/config.h"
)

option (USE_MYMATH
		"Use provided math implementation" ON)

if (USE_MYMATH)
	include_directories ("${PROJECT_SOURCE_DIR}/math")
	add_subdirectory (math)
	set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)

aux_source_directory(./ DIR_SRCS)
add_executable(Demo ${DIR_SRCS})
target_link_libraries (Demo ${EXTRA_LIBS})


# specify the path to install 
install (TARGETS Demo DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/config.h"
			DESTINATION include)


############ using CTest for making tests ############

# enable the tests
enable_testing()

# test whether the program can run
add_test (test_run Demo 5 2)

# test whether the usage message can be displayed
add_test (test_usage Demo)
set_tests_properties (test_usage 
	PROPERTIES PASS_REGULAR_EXPRESSION "Usage: .* base exponent")

# define a macro to simplify the test works
macro (do_test arg1 arg2 result)
	add_test (test_${arg1}_${arg2} Demo ${arg1} ${arg2})
	set_tests_properties (test_${arg1}_${arg2} 
		PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)

# use the macro to make a series of tests
do_test (5 2 "is 25")
do_test (10 5 "is 10000")
do_test (2 10 "is 1024")