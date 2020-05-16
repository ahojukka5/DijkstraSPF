#include <spf/graph.hpp>
#include <spf/dijkstra.hpp>

#include <iostream>

using namespace std;

// random_device rd;
// default_random_engine e2(rd());
// uniform_real_distribution<> dist(0.0, 1.0);

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
