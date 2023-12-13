#include <iostream>
using namespace std;

enum NodeColor {
    RED,
    BLACK
};

struct Node {
    int data;
    Node *parent;
    Node *left;
    Node *right;
    NodeColor color;
};

class RedBlackTree {
private:
    Node *root;

    // Helper function to find the node with the given value
    Node* searchTreeHelper(Node* node, int key) {
        if (node == nullptr || key == node->data) {
            return node;
        }
        if (key < node->data) {
            return searchTreeHelper(node->left, key);
        }
        return searchTreeHelper(node->right, key);
    }

    // Helper function to calculate the height of a node
    int calculateHeight(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);
        return max(leftHeight, rightHeight) + 1;
    }

public:
    // Constructor
    RedBlackTree() {
        root = nullptr;
    }

    // Function to search for a value in the Red-Black Tree
    void search(int n) {
        Node* node = searchTreeHelper(root, n);
        if (node != nullptr) {
            int height = calculateHeight(node);
            cout << n << " is found, its height is " << height << endl;
        } else {
            cout << n << " is not found" << endl;
        }
    }

    // Other Red-Black Tree methods...
};