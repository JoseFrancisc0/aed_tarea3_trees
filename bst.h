#ifndef BST_H
#define BST_H

#include <string>
#include <vector>
using namespace std;

template<typename T>
class BST{
    private:
        struct Node{
            T data;
            Node* left = nullptr;
            Node* right = nullptr;

            Node(T _data): data(_data){};

            void kill_self(){
                if(left)
                    left->kill_self();
                if(right)
                    right->kill_self();
                delete this;
            }
        };

        Node* root;

        void insert(Node*& current, T _data);

        void erase(Node*& current, T _data);

        bool search(Node* current, T item);

        void range_search(Node* current, T item, vector<T>& v);

    public:
        BST(): root(nullptr){};

        void insert(T _data){
            insert(root, _data);
        }

        void erase(T item){
            erase(root, item)
        }

        bool search(T item){
            return search(root, item);
        }

        vector<T> range_search(T begin, T end){
            vector<T> result;
            range_search(root, begin, end, result);
            return result;
        }

        void print(string traversal = "inorder");

        void clear(){
            if(root){
                root->kill_self();
                root = nullptr;
            }
        }

        ~BST(){
            clear();
        }
};

#endif //BST_H