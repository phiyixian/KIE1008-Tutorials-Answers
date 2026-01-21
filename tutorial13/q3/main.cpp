#include <iostream>
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

int depth(Node *root){
    if(root == nullptr) return 0;
    return 1 + max(depth(root->left), depth(root->right));
}

void print(Node* root){
    if (root == nullptr) return;
    
    cout << "Value: " << root->data << endl;
    print(root->left);
    print(root->right);
}


int main() {
    int numbers[] = {70, 60, 92, 50, 63, 82, 94, 40};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    Node *root = nullptr;
    Node *head;
    for(int i = 0; i < size; i++){
        root = insert(root, numbers[i]);
        if(i == 0) head = root;
    } 
    
    print(head);
    int maxDepth = depth(head);
    cout << "Depth is " << maxDepth << endl;
    
    return 0;
}
