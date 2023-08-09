cmake_minimum_required(VERSION 3.5)

project(Demo4)

# add a new config header for solving the set up of original file by CMake 
configure_file(
	"${PROJECT_SOURCE_DIR}/config.h.in"
	"${PROJECT_BINARY_DIR}/config.h"
)


# whether using your own MathFunctions library
# `USE_MYMATH` is a new variables whose default value is ON
option (USE_MYMATH
		"Use provided math implementation" ON)

# whether adding into the MathFunctions library
if (USE_MYMATH)
	include_directories ("${PROJECT_SOURCE_DIR}/math")
	add_subdirectory (math)
	set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)

aux_source_directory(./ DIR_SRCS)
add_executable(Demo ${DIR_SRCS})
target_link_libraries (Demo ${EXTRA_LIBS})
