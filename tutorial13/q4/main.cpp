#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    
    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

Node *insert(Node *root, int value){
    if(root == nullptr){
        return new Node(value);
    }
    
    if(value < root->data){
        root -> left = insert(root->left, value);
    } else if(value > root->data){
        root -> right = insert(root->right, value);
    }
    
    return root;
}

void print(Node* root){
    if (root == nullptr) return;
    
    queue<Node *> q;
    q.push(root);
    
    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        
        cout << current -> data << " ";
        
        if(current -> left){
            q.push(current->left);
        }
        if(current->right){
            q.push(current->right);
        }
    }
}


int main() {
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    print(root);
    
    return 0;
}
