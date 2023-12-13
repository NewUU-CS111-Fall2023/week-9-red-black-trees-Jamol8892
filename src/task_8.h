#include <iostream>
using namespace std;

template <typename T>
class RedBlackTree {
    struct Node {
        T data;
        Node *left, *right;
        bool isRed;
        // Other properties and methods
    };

    Node* root;

    // Utility function to count the nodes in the tree
    int countNodes(Node* node) {
        int count = 0;
        Node* current = node, *pre;

        while (current != nullptr) {
            if (current->left == nullptr) {
                count++;
                current = current->right;
            } else {
                pre = current->left;
                while (pre->right != nullptr && pre->right != current) {
                    pre = pre->right;
                }

                if (pre->right == nullptr) {
                    pre->right = current;
                    current = current->left;
                } else {
                    pre->right = nullptr;
                    count++;
                    current = current->right;
                }
            }
        }

        return count;
    }

public:
    // Constructor and other methods

    // Method to find the median
    void median() {
        if (root == nullptr) return;

        int totalCount = countNodes(root);
        int currentCount = 0;
        Node* current = root, *pre, *prev = nullptr;

        while (current != nullptr) {
            if (current->left == nullptr) {
                currentCount++;
                // Check if current node is the median
                if (totalCount % 2 != 0 && currentCount == (totalCount + 1) / 2) {
                    cout << current->data << " is median" << endl;
                    return;
                } else if (totalCount % 2 == 0 && (currentCount == totalCount / 2 || currentCount == (totalCount / 2) + 1)) {
                    if (prev) {
                        cout << (prev->data + current->data) / 2.0 << " is median" << endl;
                    } else {
                        prev = current;
                    }
                    if (currentCount > totalCount / 2) return;
                }
                prev = current;
                current = current->right;
            } else {
                pre = current->left;
                while (pre->right != nullptr && pre->right != current) {
                    pre = pre->right;
                }

                if (pre->right == nullptr) {
                    pre->right = current;
                    current = current->left;
                } else {
                    pre->right = nullptr;
                    currentCount++;
                    // Check if current node is the median
                    if (totalCount % 2 != 0 && currentCount == (totalCount + 1) / 2) {
                        cout << current->data << " is median" << endl;
                        return;
                    } else if (totalCount % 2 == 0 && (currentCount == totalCount / 2 || currentCount == (totalCount / 2) + 1)) {
                        if (prev) {
                            cout << (prev->data + current->data) / 2.0 << " is median" << endl;
                        } else {
                            prev = current;
                        }
                        if (currentCount > totalCount / 2) return;
                    }
                    prev = current;
                    current = current->right;
                }
            }
        }
    }
};