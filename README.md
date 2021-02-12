# Word-Recognition
# For this assignment, you will write a C++ program called hw1 that will read from standard input, recognize words, and display some statistics of questionable value about the
# input. It will display the words found, the number of words encountered, and the range of word lengths. If no words are encountered, display an error message, and nothing else. 
# The input will be any number of lines, containing words. A word is defined as a series of consecutive non-whitespace characters, separated by whitespace. However, parentheses, 
# (and ), are always separate single-character words, no matter where they appear. Whitespace is defined as any of the six characters " \f\n\r\t\v", or, equivalently, what
# isspace() says it is. 



A make file is provided for this Word Recognition code 

% cat CMakeLists.txt
cmake_minimum_required(VERSION 3.11)
project(hw1)
 
# Are we in the wrong directory?
if(CMAKE_SOURCE_DIR MATCHES "[Hh][Ww]([0-9])$")
   if(PROJECT_NAME MATCHES "[^${CMAKE_MATCH_1}]$")
      message(FATAL_ERROR "Building ${PROJECT_NAME} in ${CMAKE_SOURCE_DIR}")
   endif()
endif()
 
# Using -Wall is required:
add_compile_options(-Wall)
 
# These compile flags are highly recommended, but not required:
add_compile_options(-Wextra -Wpedantic)
 
# Optional super-strict mode:
add_compile_options(-fmessage-length=80 -fno-diagnostics-show-option
    -fstack-protector-all -g -O3 -std=c++17 -Walloc-zero -Walloca
    -Wctor-dtor-privacy -Wduplicated-cond -Wduplicated-branches
    -Werror -Wextra-semi -Wfatal-errors -Winit-self -Wlogical-op
    -Wold-style-cast -Wshadow -Wunused-const-variable=1
    -Wzero-as-null-pointer-constant)
 
# add_compile_options must be BEFORE add_executable.
 
# Create the executable from the source file main.cc:
add_executable(${PROJECT_NAME} main.cc)
 
# Create a tar file every time:
add_custom_target(${PROJECT_NAME}.tar ALL COMMAND
    tar -cf ${PROJECT_NAME}.tar *.cc CMakeLists.txt)
