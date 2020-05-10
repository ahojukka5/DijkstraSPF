#include <iostream>
#include <dijkstra/Node.hpp>
#include <dijkstra/Edge.hpp>

using namespace std;

Edge::Edge(Node &a, Node &b) {
    this->a = &a;
    this->b = &b;
}

Node Edge::getA() {
    return *a;
}

Node Edge::getB() {
    return *b;
}

ostream &operator<<(ostream &out, Edge &edge) {
    string lbl1 = edge.getA().getLabel();
    string lbl2 = edge.getB().getLabel();
    out << "Edge from " << lbl1 << " to " << lbl2;
    return out;
}
