#include <iostream>

#include "bst.h"

int main() {
    BST<int> tree;
    tree.insert(6);
    tree.insert(4);
    tree.insert(8);
    tree.insert(18);
    tree.remove(6);
    tree.inorder();
    return 0;
}