#include "task_6.h"

using namespace std;

// Main function to demonstrate the binary tree usage
int main() {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    cout << "Inorder traversal of the binary tree:" << endl;
    tree.inorder();

    return 0;
}