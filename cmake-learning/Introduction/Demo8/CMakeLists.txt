cmake_minimum_required(VERSION 3.5)

project(Demo8)

# set up the version index of the software
set (Demo_VERSION_MAJOR 1)
set (Demo_VERSION_MINOR 0)

include (${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
check_function_exists (pow HAVE_POW)

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

enable_testing()

add_test (test_run Demo 5 2)

add_test (test_usage Demo)
set_tests_properties (test_usage 
  PROPERTIES PASS_REGULAR_EXPRESSION "Usage: .* base exponent")

macro (do_test arg1 arg2 result)
  add_test (test_${arg1}_${arg2} Demo ${arg1} ${arg2})
  set_tests_properties (test_${arg1}_${arg2} 
    PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)

do_test (5 2 "is 25")
do_test (10 5 "is 10000")
do_test (2 10 "is 1024")


########### using CPack for pack up ##############
# import the InstallRequiredSystemLibraries module
include (InstallRequiredSystemLibraries)
# set up some related variables for CPack
set (CPACK_RESOURCE_FILE_LICENSE
    "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${Demo_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${Demo_VERSION_MINOR}")
# import the CPack module
include (CPack)