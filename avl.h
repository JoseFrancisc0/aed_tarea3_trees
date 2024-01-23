#ifndef AVL_H
#define AVL_H

#include <string>
#include <vector>
using namespace std;

template<typename TK, typename TV>
class AVL{
    private:
        struct Node{};
        Node* root;
    public:
        AVL(): root(nullptr){};
        void insert(TK key, TV value);
        void erase(TK key);
        vector<TV> search(TK begin, TK end);
        void print(string traversal = "inorder");
        void clear();
        ~AVL(){
            clear();
        }
};

#endif //AVL_H