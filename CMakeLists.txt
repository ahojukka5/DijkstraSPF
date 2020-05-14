cmake_minimum_required(VERSION 3.0)

project(dijkstra
        VERSION 0.1.0
        DESCRIPTION "Dijsktra's shortest path algorithm"
        LANGUAGES CXX)

include_directories( ./include ./src )

add_executable(main ./apps/main.cpp )