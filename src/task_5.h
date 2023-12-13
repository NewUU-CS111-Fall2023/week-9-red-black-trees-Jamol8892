#include <map>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() : root(nullptr) {}

    Node* insert(Node* node, int data) {
        if (node == nullptr) {
            return new Node(data);
        }
        if (data < node->data) {
            node->left = insert(node->left, data);
        } else if (data > node->data) {
            node->right = insert(node->right, data);
        }
        return node;
    }

    void countChildren(Node* node, map<int, int>& childrenCount) {
        if (node == nullptr) {
            return;
        }
        int count = 0;
        if (node->left != nullptr) {
            count++;
            countChildren(node->left, childrenCount);
        }
        if (node->right != nullptr) {
            count++;
            countChildren(node->right, childrenCount);
        }
        childrenCount[node->data] = count;
    }
};