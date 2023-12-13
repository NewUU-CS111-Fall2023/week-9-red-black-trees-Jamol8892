//
// Created by Jamol on 13.12.2023.
//

#include "task_10.h"

int main() {
    BinarySearchTree bst;

    // Insert values into the BST
    std::vector<int> values = {34, 62, 1, 46, 11, 0, 32, 3, 1, 2};
    for (int value : values) {
        bst.insert(value);
    }

    // Print the BST in in-order traversal
    std::cout << "In-order traversal:" << std::endl;
    bst.printInOrder();

    // Balance the BST into an AVL tree
    bst.balanceTree();

    // Print the AVL tree in in-order traversal
    std::cout << "In-order traversal after balancing:" << std::endl;
    bst.printInOrder();

    return 0;
}