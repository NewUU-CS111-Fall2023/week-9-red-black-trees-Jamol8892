#include <iostream>
using namespace std;

// Define the structure for a binary tree node
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Define the binary tree class
class BinaryTree {
private:
    TreeNode* root;

    // Helper method to insert a value into the binary tree
    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        if (value < node->value) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    // Helper method for inorder traversal
    void inorderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            cout << node->value << " ";
            inorderTraversal(node->right);
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    // Public method to insert a value
    void insert(int value) {
        root = insert(root, value);
    }

    // Public method to perform inorder traversal
    void inorder() {
        inorderTraversal(root);
        cout << endl;
    }
};