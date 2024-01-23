#ifndef BST_H
#define BST_H

#include <string>
#include <vector>
using namespace std;

template<typename TK, typename TV>
class BST{
    private:
        struct Node{};
        Node* root;
    public:
        BST(): root(nullptr){};
        void insert(TK key, TV value);
        void erase(TK key);
        vector<TV> search(TK begin, TK end);
        void print(string traversal = "inorder");
        void clear();
        ~BST(){
            clear();
        }
};

#endif //BST_H