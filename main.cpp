#include <stdio.h>
#include "BinarySearchTree.h"
#include <vector>

int main(){
    std::vector<int> v{61, 29, 42, 11, 59};
    BinarySearchTree bst(v);
    bst.min();
    bst.max();
    bst.find(42);
    bst.find(58);
    bst.remove(11);
    bst.min();
    bst.max();
    bst.find(11);
    bst.remove(29);
    bst.find(29);
    return 0;
}
