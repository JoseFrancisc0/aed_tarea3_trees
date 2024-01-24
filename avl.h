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

        void insert(Node* current, TK key, TV value);

        void erase(Node* current, TK key);

        void search(Node* current, TK begin, TK end, vector<TK>& v);

    public:
        AVL(): root(nullptr){};

        void insert(TK key, TV value){
            insert(root, key, value);
        }

        void erase(TK key){
            erase(root, key);
        }

        vector<TV> search(TK begin, TK end){
            vector<TV> result;
            search(root, begin, end, result);
            return result;
        }

        void print(string traversal = "inorder");

        void clear();

        ~AVL(){
            clear();
        }
};

#endif //AVL_H