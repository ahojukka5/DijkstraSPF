cmake_minimum_required(VERSION 3.0)

project(spf
        VERSION 0.1.0
        DESCRIPTION "Shortest path finding algorithms"
        LANGUAGES CXX)

include_directories( ./include ./src )

add_library(spf-static STATIC ./src/spf.cpp)
add_library(spf SHARED ./src/spf.cpp)
add_executable(spf-dijkstra ./apps/dijkstra.cpp )
target_link_libraries(spf-dijkstra spf)

install(FILES include/spf/graph.hpp DESTINATION include/spf)
install(FILES include/spf/abstract_dijkstra.hpp DESTINATION include/spf)
install(FILES include/spf/spf.hpp DESTINATION include/spf)
install(TARGETS spf-dijkstra DESTINATION bin)
install(TARGETS spf DESTINATION lib)
