#pragma once

#include <vector>
#include <tuple>
#include <map>

/**
 * A simple class to represent graph.
 */
class Graph {

  private:
    std::map<std::tuple<int, int>, int> weights;
    std::map<int, std::vector<int>> adj;

  public:
    /**
     * Add new edge (u, v) to graph with weight w.
     */
    void add_edge(int u, int v, int w) {
        auto e = std::make_tuple(u, v);
        weights[e] = w;
        if (!adj.count(u)) {
            adj[u] = std::vector<int>();
        }
        adj[u].push_back(v);
    }

    /**
     * Return adjacency list for vertex u.
     */
    auto get_adj(int u) {
        return adj[u];
    }

    /**
     * Return weight for edge e.
     */
    auto get_weight(int u, int v) {
        return weights[std::make_tuple(u, v)];
    }
};