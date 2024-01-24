#ifndef AVL_H
#define AVL_H

#include <string>
#include <vector>
using namespace std;

template<typename T>
class AVL{
    private:
        struct Node{
            T data;
            int height = 0;
            Node* left = nullptr;
            Node* right = nullptr;

            Node(T _data) : data(_data){};

            void kill_self(){
                if(left)
                    left->kill_self();
                if(right)
                    right->kill_self();
                delete this;
            }
        };

        Node* root;

        void balance(Node* nodo);

        void insert(Node* current, T _data){
            if(!current)
                current = new Node(_data);
            else if(_data < current->data)
                insert(current->left, _data);
            else if(_data > current->data)
                insert(current->right, _data);

            balance(current);
        }

        void erase(Node* current, T key);

        void range_search(Node* current, T begin, T end, vector<T>& v){
            if(!current)
                return;
            
            if(current->data > begin)
                search(current->left, begin, end, v);
            if(current->data >= begin && current->data <= end)
                v.push_back(current->data);
            if(current->data < end)
                search(current->right, begin, end, v);
        }

    public:
        AVL(): root(nullptr){};

        void insert(T _data){
            insert(root, _data);
        }

        void erase(T key){
            erase(root, key);
        }

        vector<T> range_search(T begin, T end){
            vector<T> result;
            search(root, begin, end, result);
            return result;
        }

        void print(string traversal = "inorder");

        void clear(){
            if(root){
                root->kill_self();
                root = nullptr;
            }
        }

        ~AVL(){
            clear();
        }
};

#endif //AVL_H