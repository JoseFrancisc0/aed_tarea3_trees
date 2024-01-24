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

        void erase(Node*& current, T item){
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

        void breadth_first_search(){
            queue<Node*> q;
            q.push(root);
            while(!q.empty()){
                Node* temp = q.front();
                q.pop();
                cout << temp->data << " ";
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }

        void depth_first_search(){
            stack<Node*> s;
            Node* temp = root;

            while(temp || !s.empty()){
                while(temp){
                    s.push(temp);
                    temp = temp->left;
                }
                temp = s.top();
                s.pop();
                cout << temp->data << " ";
                temp = temp->right;
            }
        }

    public:
        BST(): root(nullptr){};

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
            range_search(root, begin, end, result);
            return result;
        }

        void print(string traversal = "inorder"){
            if(!root){
                cout << "EMPTY TREE" << endl;
                return;
            }
            
            if(traversal == "preorder"){
                cout << "PRE ORDER: ";
                pre_order(root);
            }
            else if(traversal == "inorder"){
                cout << "IN ORDER: ";
                in_order(root);
            }
            else if(traversal == "postorder"){
                cout << "POST ORDER: ";
                post_order(root);
            }
            else if(traversal == "BFS"){
                cout << "BFS: ";
                breadth_first_search();
            }
            else if(traversal == "DFS"){
                cout << "DFS: ";
                depth_first_search();
            }
            else{
                cout << "Invalid input. Defaulting to inorder" << "\n";
                cout << "IN ORDER: ";
                in_order(root);
            }

            cout << "\n";
        }

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