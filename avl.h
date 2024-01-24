#ifndef AVL_H
#define AVL_H

#include <iostream>
#include <queue>
#include <stack>
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

        int height(Node* node){
            if(!node)
                return -1;
            else
                return node->height;
        }

        void update_height(Node* node){
            node->height = max(height(node->left), height(node->right)) + 1;
        }

        void l_rotation(Node* node){
            Node* temp = node->left;
            node->left = temp->right;
            temp->right = node;
            update_height(node);
            temp->height = max(height(temp->left), node->height) + 1;
            node = temp;
        }

        void r_rotation(Node* node){
            Node* temp = node->right;
            node->right = temp->left;
            temp->left = node;
            update_height(node);
            temp->height = max(height(temp->right), node->height) + 1;
            node = temp;
        }

        void lr_rotation(Node* node){
            l_rotation(node);
            r_rotation(node);
        }

        void rl_rotation(Node* node){
            r_rotation(node);
            l_rotation(node);
        }

        int balance_factor(Node* node){
            return height(node->left) - height(node->right);
        }

        void balance(Node* node){
            if(!node)
                return;
            
            if(balance_factor(node) > 1)
                if(balance_factor(node->left) >= 0)
                    l_rotation(node);
                else
                    rl_rotation(node);
            else
                if(balance_factor(node) < -1)
                    if(balance_factor(node->right) >= 0)
                        r_rotation(node);
                    else
                        lr_rotation(node);
            
            update_height(node);
        }

        Node* findMin(Node* node){
            while(node->left)
                node = node->left;
            
            return node;
        }

        void insert(Node* current, T _data){
            if(!current)
                current = new Node(_data);
            else if(_data < current->data)
                insert(current->left, _data);
            else if(_data > current->data)
                insert(current->right, _data);

            balance(current);
        }

        Node* erase(Node* current, T item){
            if(!current)
                return nullptr;
            
            if(item < current->data)
                current->left = erase(current->left, item);
            else if(item > current->data)
                current->right = erase(current->right, item);
            else{
                if(!current->left && !current->right){
                    delete current;
                    return nullptr;
                }
                else if(!current->left){
                    Node* temp = current->right;
                    delete current;
                    return temp;
                }
                else if(!current->right){
                    Node* temp = current->left;
                    delete current;
                    return temp;
                }
                else{
                    Node* successor = findMin(current->right);
                    current->data = successor->data;
                    current->right = erase(current->right, successor->data);
                }
            }

            update_height(current);
            balance(current);
            return current;
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
                search(current->left, begin, end, v);
            if(current->data >= begin && current->data <= end)
                v.push_back(current->data);
            if(current->data < end)
                search(current->right, begin, end, v);
        }

        void pre_order(Node* current){
            if(current){
                cout << current->data << " ";
                pre_order(current->left);
                pre_order(current->right);
            }
        }

        void in_order(Node* current){
            if(current){
                in_order(current->left);
                cout << current->data << " ";
                in_order(current->right);
            }
        }

        void post_order(Node* current){
            if(current){
                post_order(current->left);
                post_order(current->right);
                cout << current->data << " ";
            }
        }

        void breadth_first_search(Node* current){
            queue<Node*> q;
            q.push(root);
            while(!q.empty()){
                Node* temp = q.front();
                q.pop();
                cout << temp->data << " ";
                if(temp->left)
                    q.push(node->left);
                if(temp->righ)
                    q.push(node->righ);
            }
        }

        void depth_first_search(Node* current){
            stack<Node*> s;
            s.push(root);
            while(!s.empty){
                Node* temp = s.front();
                s.pop();
                cout << temp->data << " ";
                if(temp->left)
                    s.push(temp->left)
                if(temp->righ)
                    s.push(temp->righ);
            }
        }

    public:
        AVL(): root(nullptr){};

        void insert(T _data){
            insert(root, _data);
        }

        void erase(T item){
            erase(root, item);
        }

        bool search(T item){
            return search(root, item);
        }

        vector<T> range_search(T begin, T end){
            vector<T> result;
            search(root, begin, end, result);
            return result;
        }

        void print(string traversal = "inorder"){
            if(tolower(traversal) == "preorder")
                pre_order(root);
            else if(tolower(traversal) == "inorder")
                in_order(root);
            else if(tolower(traversal) == "postorder")
                post_order(root);
            else if(tolower(traversal) == "BFS")
                breadth_first_search(root);
            else if(tolower(traversal) == "DFS")
                depth_first_search(root);
            else{
                cout << "Invalid input. Defaulting to inorder" << "\n";
                in_order(root);
            }

            cout << "\n"
        }

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