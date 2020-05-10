cmake_minimum_required(VERSION 3.0)

project(dijkstra
        VERSION 0.1.0
        DESCRIPTION "Dijsktra's shortest path algorithm"
        LANGUAGES CXX)

include_directories( ./include ./src )

add_executable(dijkstra ./apps/main.cpp )

# find_package(GTest REQUIRED)
# "Unit tests", TODO: use gtest, https://github.com/bast/gtest-demo
add_executable(test_node ./test/test_node.cpp ./src/Node.cpp)
