#include <iostream>
#include <vector>
#include <map>

// Node definition for a Red-Black Tree
enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

// Class definition for the Red-Black Tree
class RBTree {
private:
    Node *root;

    // Helper function to perform a DFS and count nodes in each subtree
    int countSubtreeNodes(Node *node, std::map<Node*, int>& subtreeNodeCount) {
        if (!node) return 0;

        int leftCount = countSubtreeNodes(node->left, subtreeNodeCount);
        int rightCount = countSubtreeNodes(node->right, subtreeNodeCount);
        int totalCount = leftCount + rightCount + 1; // +1 for the current node

        subtreeNodeCount[node] = totalCount;
        return totalCount;
    }

public:
    RBTree() : root(nullptr) {}

    // Function to insert a new node into the tree
    void insert(const int &data) {

    }

    // Function to count nodes in each subtree
    std::map<Node*, int> countSubtreeNodes() {
        std::map<Node*, int> subtreeNodeCount;
        countSubtreeNodes(root, subtreeNodeCount);
        return subtreeNodeCount;
    }

    // Function to print the number of nodes in each subtree
    void printSubtreeNodeCounts() {
        auto subtreeNodeCount = countSubtreeNodes();
        for (const auto &entry : subtreeNodeCount) {
            std::cout << entry.first->data << " - " << entry.second << std::endl;
        }
    }

};