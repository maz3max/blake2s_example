cmake_minimum_required(VERSION 3.1)
project(blake_example)

include_directories("${CMAKE_SOURCE_DIR}/include")
include_directories("${CMAKE_SOURCE_DIR}/BLAKE2/ref")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(main BLAKE2/ref/blake2s-ref.c src/main.c)

target_link_libraries(main)
