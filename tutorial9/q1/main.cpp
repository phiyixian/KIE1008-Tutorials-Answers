// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
    node* prev;
};

void print(node *head){
    node* temp;
    temp = head;
    while(temp != NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
    delete temp;
}

int main() {
    node* first = new node;
    node* second = new node;
    node* third = new node;
    
    node* head;
    
    first->data = 90;
    first->next = second;
    first->prev = NULL;
    head = first;
    
    second->data = 190;
    second->next = third;
    second->prev = first;
    
    third->data = 290;
    third->next = NULL;
    third->prev = second;
    
    print(head);
    
    node* tem;
    tem = head;
    while(tem != NULL && tem->next != NULL){
        if(tem->next->data == 190){
            cout << "Found 190" << endl;
            tem->next = tem->next->next;
            tem->next->prev = tem;
        }
        tem = tem->next;
    }
    
    print(head);

    return 0;
}
