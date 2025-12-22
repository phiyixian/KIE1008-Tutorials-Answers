#include <iostream>
using namespace std;

struct nodeType{
    int data;
    nodeType* link;
};


bool checkIfExist(nodeType* node, int val){
    while(node != NULL){
        if(node->data == val){
            return true;
        }
        node = node->link;
    }
    return false;
}

void insert_begin(nodeType* &head, int val){
    if(!checkIfExist(head, val)){
        nodeType *newNode = new nodeType;
        newNode->data = val;
        newNode->link = head;
        head = newNode;
    }else {
        cout << "Value already exists." << endl;
    }
}

void insert_last(nodeType* &last, int val){
    if(!checkIfExist(last, val)){
        nodeType *newNode = new nodeType;
        newNode->link = NULL;
        newNode->data = val;
        last->link = newNode;
        last = newNode;
    }else {
        cout << "Value already exists." << endl;
    }
}

void insert_pos(nodeType* &head, int pos, int val){
    if(!checkIfExist(head, val)){
        nodeType *newNode = new nodeType;
        nodeType *temp;
        
        newNode->data = val;
        temp = head;
        for(int i = 1; i < pos - 1; i ++){
            temp = temp->link;
        }
        
        newNode->link = temp->link;
        temp->link = newNode;
    }else {
        cout << "Value already exists." << endl;
    }
}

void print_all(nodeType *node){
    do {
        cout << node->data << endl;
        node = node->link;
    } while(node != NULL);
    cout << endl;
}

int main() {
    nodeType *head;
    nodeType *last = new nodeType;
    nodeType *first = new nodeType;
    nodeType *second = new nodeType;
    nodeType *third = new nodeType;
    
    first->data = 1;
    first->link = second;
    
    second->data = 2;
    second->link = third;
    
    third->data = 3;
    third->link = NULL;
    
    head = first;
    last = third;
    
    insert_begin(head, 5);
    print_all(head);
    
    insert_last(last, 7);
    print_all(head);
    
    insert_pos(head, 2, 10);
    print_all(head);
    
    insert_pos(head, 3, 3);
    
    return 0;
}
