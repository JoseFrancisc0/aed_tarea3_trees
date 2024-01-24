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

        T findMin(Node* node){
            if(!node)
                return NULL;
            if(!node->left)
                return node->data;
            
            return findMin(node->left);
        }

        void insert(Node*& current, T _data){
            if(!current)
                current = new Node(_data);
            else if(_data < current->data)
                insert(current->left, _data);
            else if(_data > current->data)
                insert(current->right, _data);
        }

        void erase(Node*& current, T _data){
            if(!current)
                return;
            
            if(item < current->data)
                erase(current->left, item);
            else if(item > current->data)
                erase(current->right, item);
            else if(current->left && current->right){
                T min = findMin(current->right);
                current->data = min;
                erase(current->right, min);
            }
            else{
                Node* temp = current;
                if(current->left)
                    current = current->left;
                else
                    current = current->right;
                delete temp;
            }
        }

        bool search(Node* current, T item){
            if(!current)
                return false;
            else if(item < current->data)
                return search(current->left, item);
            else if(item > current->data)
                return search(current->right, item);
            else
                return true;
        }

        void range_search(Node* current, T begin, T end, vector<T>& v){
            if(!current)
                return;
            
            if(current->data > begin)
                range_search(current->left, begin, end, v);
            if(current->data >= begin && current->data <= end)
                v.push_back(current->data);
            if(current->data < end)
                range_search(current->right, begin, end, v);
        }

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