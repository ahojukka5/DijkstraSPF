#pragma once

#include <spf/graph.hpp>
#include <spf/abstract_dijkstra.hpp>

#include <vector>

class Dijkstra : public AbstractDijkstra<Graph> {
  private:
    /**
     * Get adjacent nodes of u in graph G.
     */
    std::vector<int> get_adjacent(Graph &G, int u);

    /**
     * Get weight between u and v in graph G.
     */
    int get_weight(Graph &G, int u, int v);
};
