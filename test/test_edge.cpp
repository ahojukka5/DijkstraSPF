#include <dijkstra/Node.hpp>
#include <dijkstra/Edge.hpp>
#include <iostream>

using namespace std;

int main() {
    Node A = Node("A");
    Node B = Node("B");
    Edge AB = Edge(A, B);
    cout << AB << endl;
    return 0;
}