# the requirement of the lowest version of CMake to run on 
cmake_minimum_required (VERSION 2.8)

# the information of project
project (Demo2)

# find out the all the sources in the repository
# and store the names into the `DIR_SRCS` variables

# aux_source_directory(<dir> <variables>)
aux_source_directory(./ DIR_SRCS)

# specify the generated target
add_executable(Demo ${DIR_SRCS})
