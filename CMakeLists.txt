cmake_minimum_required(VERSION 3.0)

project(spf
        VERSION 0.1.0
        DESCRIPTION "Shortest path finding algorithms"
        LANGUAGES CXX)

include_directories( ./include ./src )

add_executable(spf-dijkstra ./apps/dijkstra.cpp )

install(FILES include/spf/graph.hpp DESTINATION include/spf)
install(FILES include/spf/abstract_dijkstra.hpp DESTINATION include/spf)
install(TARGETS spf-dijkstra DESTINATION bin)
