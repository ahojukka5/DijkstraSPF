#include <iostream>
#include <random>
#include <vector>

using namespace std;

/**
 * Generate a random graph with N vertices and edge density d.
 *
 * Density of the graph is given as a real value between 0 ... 1, where 0
 * denotes for an empty graph and 1 is a complete graph, where all nodes are
 * connected with each other.
 *
 * @param N is the number of vertices in generated graph
 * @param d is the density of the graph
 * @return 2d boolean array representation of graph (adjacency matrix)
 */
bool **random_graph(int N, double d) {
    cout << "Generate random graph of size " << N << " and density " << d
         << endl;

    random_device rd;
    default_random_engine e2(rd());
    uniform_real_distribution<> dist(0.0, 1.0);

    bool **graph = new bool *[N];
    for (int i = 0; i < N; i++) {
        graph[i] = new bool[N];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                graph[i][j] = false;
            } else {
                double rval = dist(e2);
                if (rval <= d) {
                    graph[i][j] = true;
                } else {
                    graph[i][j] = false;
                }
            }
        }
    }
    return graph;
}

void print_graph(bool **graph, int N, bool print_zeros) {
    bool *first_row = graph[0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (print_zeros || graph[i][j]) {
                cout << graph[i][j];
            }
            if (j == N - 1) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }
}

void print_graph_dot(bool **graph, int N) {
    cout << "graph {" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (graph[i][j] != false) {
                cout << "    " << i << " -- " << j << ";" << endl;
            }
        }
    }
    cout << "}" << endl;
}

int main(int argc, char *argv[]) {
    cout << "Welcome to Dijkstra's shortest path solver!" << std::endl;
    int N = 10;
    double d = 0.2;
    bool **graph = random_graph(N, d);
    // print_graph(graph, N, true);
    // print_graph_dot(graph, N);
    return 0;
}
