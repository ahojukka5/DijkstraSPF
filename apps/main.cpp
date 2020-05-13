#include <iostream>
#include <map>
#include <random>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

// random_device rd;
// default_random_engine e2(rd());
// uniform_real_distribution<> dist(0.0, 1.0);

/**
 * A simple class to represent graph.
 */
class Graph {

  private:
    map<tuple<int, int>, int> weights;
    map<int, vector<int>> adj;

  public:
    /**
     * Add new edge (u, v) to graph with weight w.
     */
    void add_edge(int u, int v, int w) {
        auto e = make_tuple(u, v);
        weights[e] = w;
        if (!adj.count(u)) {
            adj[u] = vector<int>();
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
        return weights[make_tuple(u, v)];
    }
};

/**
 * Dijsktra's shortest path algorithm.
 */
class Dijkstra {
  private:
    map<int, int> dist, prev;
    set<int> queue, visited;

    /**
     * Return minimum from queue based on dist.
     */
    int min(set<int> queue, map<int, int> dist) {
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
     * Get adjacent nodes of u in graph G.
     */
    auto get_adjacent(Graph G, int u) {
        return G.get_adj(u);
    }

    /**
     * Get weight between u and v in graph G.
     */
    int get_weight(Graph G, int u, int v) {
        return G.get_weight(u, v);
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

  public:
    /**
     * Run Dijkstra's algorithm to graph G starting from vertex s.
     */
    Dijkstra(Graph G, int s) {
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

int main(int argc, char *argv[]) {
    cout << "Welcome to Dijkstra's shortest path solver!" << std::endl;
    enum Nodes { S, T, A, B, C, D, E, F, G };
    Graph graph;
    graph.add_edge(S, A, 4);
    graph.add_edge(S, B, 3);
    graph.add_edge(S, D, 7);
    graph.add_edge(A, C, 1);
    graph.add_edge(B, S, 3);
    graph.add_edge(B, D, 4);
    graph.add_edge(C, E, 1);
    graph.add_edge(C, D, 3);
    graph.add_edge(D, E, 1);
    graph.add_edge(D, T, 3);
    graph.add_edge(D, F, 5);
    graph.add_edge(E, G, 2);
    graph.add_edge(G, E, 2);
    graph.add_edge(G, T, 3);
    graph.add_edge(T, F, 5);
    Dijkstra solution = Dijkstra(graph, S);
    cout << "Shortest path to T = " << solution.get_distance(T) << endl;
    return 0;
}
