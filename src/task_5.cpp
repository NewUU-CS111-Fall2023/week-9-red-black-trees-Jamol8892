#include <iostream>
#include <vector>
#include <map>
#include "task_5.h"

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    BinaryTree tree;
    for (int value : values) {
        tree.root = tree.insert(tree.root, value);
    }

    map<int, int> childrenCount;
    tree.countChildren(tree.root, childrenCount);

    for (const auto& kv : childrenCount) {
        cout << kv.first << " - " << kv.second << endl;
    }

    return 0;
}