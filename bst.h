#ifndef BST_H
#define BST_H

#include <string>
#include <vector>
using namespace std;

template<typename T>
class BST{
    private:
        struct Node{};
        Node* root;
    public:
        BST(): root(nullptr){};
        void insert(T _data);
        void erase(T key);
        vector<TV> search(T begin, T end);
        void print(string traversal = "inorder");
        void clear();
        ~BST(){
            clear();
        }
};

#endif //BST_H