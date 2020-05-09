#include <iostream>
#include <dijkstra/Node.hpp>

using namespace std;

Node::Node(string label) {
    this->label = label;
}

std::string Node::getLabel() {
    return label;
}

void Node::setLabel(string label) {
    this->label = label;
}

ostream &operator<<(ostream &out, Node &v) {
    out << "Node " << v.getLabel();
    return out;
}
