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
        void divideMid(linkedList& subList);
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

void linkedList::divideMid(linkedList& subList){
    nodeType* temp;
    temp = head;
    while(temp->data != 27){
        temp = temp->link;
    }
    subList.head = temp->link;
    temp->link = NULL;
}

int main() {
    linkedList myList;
    linkedList subList;
    
    myList.insert(34);
    myList.insert(65);
    myList.insert(27);
    myList.insert(89);
    myList.insert(12);
    myList.print();
    
    myList.divideMid(subList);
    myList.print();
    subList.print();
    return 0;
}
