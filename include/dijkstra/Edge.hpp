#pragma once

#include <dijkstra/Node.hpp>

/**
 * Standard Edge component between nodes A and B
 */
class Edge {
  private:
    Node *a, *b;

  public:
    Edge(Node &a, Node &b);

    Node getA();

    Node getB();

    friend std::ostream &operator<<(std::ostream &out, Edge &edge);
};