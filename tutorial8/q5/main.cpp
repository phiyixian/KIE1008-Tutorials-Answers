#include <iostream>
using namespace std;

struct nodeType{
    int data;
    nodeType* link;
};

class linkedList{
    private:
        nodeType* head;
    public:
        linkedList();
        void insert(int val);
        void print();
        void remove_smallest();
};

linkedList::linkedList(){
    head = NULL;
}

void linkedList::print(){
    nodeType* temp;
    temp = head;
    while(temp != NULL){
        cout << temp->data << endl;
        temp = temp->link;
    }
    cout << endl;
}

void linkedList::insert(int val){
    if(head != NULL){
        nodeType* newNode = new nodeType;
        newNode->data = val;
        newNode->link = NULL;
        
        nodeType* temp;
        temp = head;
        while(temp->link != NULL){
            temp = temp->link;
        }
        temp->link = newNode;
    } else {
        head = new nodeType;
        head->data = val;
        head->link = NULL;
    }

}

void linkedList::remove_smallest(){
    int min = head->data;
    nodeType* node_to_remove;
    nodeType* temp;
    temp = head;
    while(temp != NULL){
        if(temp->data < min){
            min = temp->data;
            node_to_remove = temp;
        }
        temp = temp->link;
    }
    
    temp = head;
    while(temp != NULL){
        if(temp->link == node_to_remove){
            temp->link = node_to_remove->link;
        }
        temp = temp->link;
    }
}

int main() {
    linkedList myList;
    
    myList.insert(34);
    myList.insert(65);
    myList.insert(27);
    myList.insert(89);
    myList.insert(12);
    myList.print();
    
    myList.remove_smallest();
    myList.print();
    return 0;
}
