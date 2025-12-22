// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

struct node
{
     int info;
     node * next;
     node (int D, node *N)
    : info (D),
     next (N)
     { }
} ;

int main() {
    node *r = new node(9, NULL);
    node *s = new node(7, r);
    node *p = new node(3, s);
    cout << p->info + s->info + r->info << endl;
    
    return 0;
}
