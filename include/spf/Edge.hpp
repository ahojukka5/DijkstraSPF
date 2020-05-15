#pragma once

#include <dijkstra/Node.hpp>

/**
 * Standard Edge component between nodes A and B
 */
class Edge {
  private:
    Node *a, *b;

  public:
    Edge(Node &a, Node &b) {
        this->a = &a;
        this->b = &b;
    }

    Node getA() {
        return *a;
    }

    Node getB() {
        return *b;
    }

    friend std::ostream &operator<<(std::ostream &out, Edge &edge) {
        std::string lbl1 = edge.getA().getLabel();
        std::string lbl2 = edge.getB().getLabel();
        out << "Edge from " << lbl1 << " to " << lbl2;
        return out;
    }
};
