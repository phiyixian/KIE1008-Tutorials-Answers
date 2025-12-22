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
    cout << endl;
}

void fun(struct node **head_ref)
{
     struct node *temp = NULL;
     struct node *current = *head_ref;
     while (current != NULL)
     {
         temp = current->prev;
         current->prev = current->next;
         current->next = temp;
         current = current->prev;
     }
     if(temp != NULL )
        *head_ref = temp->prev;
}

int main() {
    node* first = new node;
    node* second = new node;
    node* third = new node;
    node* fourth = new node;
    node* fifth = new node;
    
    node* head;
    
    first->data = 1;
    first->next = second;
    first->prev = NULL;
    head = first;
    
    second->data = 2;
    second->next = third;
    second->prev = first;
    
    third->data = 3;
    third->next = fourth;
    third->prev = second;
    
    fourth->data = 4;
    fourth->next = fifth;
    fourth->prev = third;
    
    fifth->data = 5;
    fifth->next = NULL;
    fifth->prev = fourth;
    
    print(head);
    
    fun(&head);
    
    print(head);

    return 0;
}
