#include <iostream>
#include "task_from1_to4.h"

using namespace std;

int main() {
    cout << "Task 1-4:" << endl;

    int n;
    cin >> n;

    RedBlackTree tree;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        tree.insert(data);
    }

    tree.printTree();
    cout << endl;

    cout << "Task 5" << endl;


    return 0;
}