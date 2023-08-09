cmake_minimum_required (VERSION 3.24)

project (Demo3)

aux_source_directory(./ DIR_SRCS)

# add the `math` subdirectory
add_subdirectory(math)

add_executable(Demo ${DIR_SRCS})


# add the link library
target_link_libraries(Demo MathFunctions)