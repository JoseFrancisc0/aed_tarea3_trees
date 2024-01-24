#include <iostream>
#include "avl.h"
#include "bst.h"
using namespace std;

void test_bst(){
    BST<int> tree;

    // Testing insert
    tree.insert(16);
    tree.insert(25);
    tree.insert(36);
    tree.insert(49);
    tree.insert(1);
    tree.insert(4);
    tree.insert(9);
    tree.print();

    // Testing search and erase
    cout << boolalpha << tree.search(25) << '\n';
    tree.erase(25);
    cout << boolalpha << tree.search(25) << "\n";
    for(auto i : tree.range_search(15, 50))
        cout << i << " ";
    cout << "\n";

    // Testing all traversal
    tree.print("preorder");
    tree.print("inorder");
    tree.print("postorder");
    tree.print("BFS");
    tree.print("DFS");

    // Testing clear
    tree.clear();
    tree.print();
}

void test_avl(){
    AVL<int> tree;

    // Testing insert
    tree.insert(16);
    tree.insert(25);
    tree.insert(36);
    tree.insert(49);
    tree.insert(1);
    tree.insert(4);
    tree.insert(9);
    tree.print();

    // Testing search and erase
    cout << boolalpha << tree.search(25) << '\n';
    tree.erase(25);
    cout << boolalpha << tree.search(25) << "\n";
    for(auto i : tree.range_search(15, 50))
        cout << i << " ";
    cout << "\n";

    // Testing all traversal
    tree.print("preorder");
    tree.print("inorder");
    tree.print("postorder");
    tree.print("BFS");
    tree.print("DFS");

    // Testing clear
    tree.clear();
    tree.print();
}

int main(){
    //test_avl();
    //test_bst();
}
