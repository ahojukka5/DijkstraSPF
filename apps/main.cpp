#include <iostream>
#include <map>
#include <random>
#include <set>
#include <tuple>
#include <vector>

#include <dijkstra/AbstractDijkstra.hpp>
#include <dijkstra/Graph.hpp>

using namespace std;

// random_device rd;
// default_random_engine e2(rd());
// uniform_real_distribution<> dist(0.0, 1.0);

class Dijkstra : public AbstractDijkstra<Graph> {
  private:
    /**
     * Get adjacent nodes of u in graph G.
     */
    std::vector<int> get_adjacent(Graph &G, int u) {
        return G.get_adj(u);
    }

    /**
     * Get weight between u and v in graph G.
     */
    int get_weight(Graph &G, int u, int v) {
        G.get_weight(u, v);
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
    Dijkstra solution;
    solution.run(graph, S);
    cout << "Shortest path to T = " << solution.get_distance(T) << endl;
    return 0;
}
