#pragma once

#include <iostream>
#include <string>

/**
 * Node class.
 */
class Node {

  private:
    std::string label;

  public:
    /**
     * Constructor for a new node.
     */
    Node(std::string label) {
        this->label = label;
    }

    /**
     * Return the label of the node.
     */
    std::string getLabel() {
        return label;
    }

    /**
     * Set the label of the node.
     */
    void setLabel(std::string label) {
        this->label = label;
    }

    friend std::ostream &operator<<(std::ostream &out, Node &v) {
        out << "Node " << v.getLabel();
        return out;
    }
};
