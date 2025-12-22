#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
    node* prev;
};

class linkedList{
    public:
        node* head;
        linkedList();
        void insert(int val);
        void print();
};


linkedList::linkedList(){
    head = NULL;
}

void linkedList::print(){
    node* temp;
    temp = head;
    while(temp != NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
}

void linkedList::insert(int val){
    if(head != NULL){
        node* newNode = new node;
        newNode->data = val;
        newNode->next = NULL;
        
        node* temp;
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    } else {
        head = new node;
        head->data = val;
        head->next = NULL;
        head->prev = NULL;
    }

}

int main() {
    linkedList listA;
    listA.insert(1);
    listA.insert(2);
    listA.insert(3);
    listA.print();
    
    linkedList listB;
    listB.insert(4);
    listB.insert(5);
    listB.insert(6);
    listB.print();
    
    node *temp;
    temp = listA.head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = listB.head;
    listB.head->prev = temp;
    listA.print();
    
    return 0;

}
