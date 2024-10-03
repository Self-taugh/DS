#define _CRT_RAND_S
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "Node.h"
#include "LCA.h"


void treeRandomGenerator(Node* parent, std::vector<Node*> *all) {
    // больше число - больше дерево
    unsigned int x = 0; unsigned int chanse{ 2 };
    rand_s(&x);
    x = x % chanse;
    std::cout << x << "\n";
    if (x == 0) {
        // не генерируем
    }
    else {
        if (x < (chanse-1)/2) {
            Node node = new Node(parent);
            all->push_back(&node);
            parent->left = &node;
            std::cout << "created 1 node: " << node.number << " and his parent is: " << parent->number << "\n";
            treeRandomGenerator(&node, all);
        }
        else {
            Node node1 = new Node(parent);
            parent->left = &node1;
            Node node2 = new Node(parent);
            parent->right = &node2;
            all->push_back(&node1);
            all->push_back(&node2);
            std::cout << "created 2 node: " << node1.number << " and " << node2.number << " and theys parent is: " << parent->number << "\n";
            treeRandomGenerator(&node1, all);
            treeRandomGenerator(&node2, all);
        }
    }
}

int main()
{
    std::vector<Node*> all;
    Node startNode = new Node();
    treeRandomGenerator(&startNode, &all);
    std::cout << "\n";
    std::cout << lca(all[2], all[5]);

}