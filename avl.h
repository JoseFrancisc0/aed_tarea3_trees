#ifndef AVL_H
#define AVL_H

#include <string>
#include <vector>
using namespace std;

template<typename TK, typename TV>
class AVL{
    private:
        struct Node{
            TK key;
            TV value;
            int height = 0;
            Node* left = nullptr;
            Node* right = nullptr;

            Node(TK _key, TV _value) : key(_key), value(_value){};

            void kill_self(){
                if(left)
                    left->kill_self();
                if(right)
                    right->kill_self();
                delete this;
            }
        };

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