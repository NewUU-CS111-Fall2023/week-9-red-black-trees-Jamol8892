#include <iostream>
#include <vector>
#include <algorithm>

// Node structure for a Binary Search Tree
struct Node {
    int data;
    Node *left, *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// BinarySearchTree class definition
class BinarySearchTree {
private:
    Node *root;

    // Helper function to insert a new node into the tree
    Node* insert(Node* node, int value) {
        if (!node) return new Node(value);
        if (value < node->data) node->left = insert(node->left, value);
        else if (value > node->data) node->right = insert(node->right, value);
        // Duplicate values are not inserted in the tree
        return node;
    }

    // Helper function for in-order traversal
    void inOrderTraversal(Node* node) {
        if (!node) return;
        inOrderTraversal(node->left);
        std::cout << node->data << " ";
        inOrderTraversal(node->right);
    }

    // Helper function to delete a node
    // (Implementation not shown for brevity)

    // Helper function to calculate the height of the tree
    int height(Node* node) {
        if (!node) return 0;
        return std::max(height(node->left), height(node->right)) + 1;
    }

    // Helper function to perform rotations and balance the tree
    // (Implementation not shown for brevity)

public:
    BinarySearchTree() : root(nullptr) {}

    // Public method to insert a new value into the tree
    void insert(int value) {
        root = insert(root, value);
    }

    // Public method to print the tree in in-order traversal
    void printInOrder() {
        inOrderTraversal(root);
        std::cout << std::endl;
    }

    // Public method to delete a value from the tree
    // (Implementation not shown for brevity)

    // Public method to get the height of the tree
    int getHeight() {
        return height(root);
    }

    // Public method to convert the BST into an AVL tree
    void balanceTree() {
        // Convert the BST into an AVL tree
        // (Implementation not shown for brevity)
    }
};