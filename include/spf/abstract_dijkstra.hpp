#pragma once

#include <map>
#include <set>
#include <tuple>
#include <vector>

/**
 * Dijsktra's shortest path algorithm, abstact class
 */
template <typename Graph> class AbstractDijkstra {
  private:
    std::map<int, int> dist, prev;
    std::set<int> queue, visited;

    /**
     * Return minimum from queue based on dist.
     */
    int min(std::set<int> queue, std::map<int, int> dist) {
        int d = INT32_MAX;
        int u = -1;
        for (int v : queue) {
            if (dist[v] < d) {
                d = dist[v];
                u = v;
            }
        }
        return u;
    }

    /**
     * Return true if node v is already visited.
     */
    bool is_visited(int v) {
        return visited.count(v);
    }

    /**
     * Initialize algorithm to start from node s.
     */
    void initialize(int s) {
        queue.clear();
        dist.clear();
        prev.clear();
        queue.insert(s);
        dist[s] = 0;
        prev[s] = s;
    }

    /**
     * Get adjacent nodes of u in graph G.
     */
    virtual std::vector<int> get_adjacent(Graph &G, int u) = 0;

    /**
     * Get weight between u and v in graph G.
     */
    virtual int get_weight(Graph &G, int u, int v) = 0;

  public:
    /**
     * Run Dijkstra's algorithm to graph G starting from vertex s.
     */
    void run(Graph &G, int s) {
        initialize(s);
        while (!queue.empty()) {
            int u = min(queue, dist);
            for (int v : get_adjacent(G, u)) {
                if (is_visited(v)) {
                    continue;
                }
                int tentative_distance = get_distance(u) + get_weight(G, u, v);
                if (tentative_distance < get_distance(v)) {
                    dist[v] = tentative_distance;
                    prev[v] = u;
                    queue.insert(v);
                }
            }
            queue.erase(u);
            visited.insert(u);
        }
    }

    /**
     * Return shortest path to node v.
     */
    int get_distance(int v) {
        return dist.count(v) ? dist[v] : INT32_MAX;
    }

};
