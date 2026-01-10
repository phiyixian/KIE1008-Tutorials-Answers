#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

// Write the definition of the function moveNthFront that takes as a 
// parameter a positive integer, n. The function moves the nth element 
// of the queue to the front. The order of the remaining elements remains
// unchanged. For example, suppose:
// queue = {5, 11, 34, 67, 43, 55} and n = 3
// After a call to the function moveNthFront:
// queue = {34, 5, 11, 67, 43, 55}

void moveNthFront(queue <int> &q, int n){
    int size = q.size();
    int nthelement = 0;
    
    for(int i = 0; i < size; i++){
        int current = q.front();
        q.pop();
        
        if(i == n - 1){
            nthelement = current;
        } else {
            q.push(current);
        }
    }
    
    queue <int> temp;
    temp.push(nthelement);
    
    while(!q.empty()){
        temp.push(q.front());
        q.pop();
    }
    
    q = temp;
}
int main() {
    double numbers[] = {5, 11, 34, 67, 43, 55};
    int n = 3;
    queue <int> queue;
    queue.push(5);
    queue.push(11);
    queue.push(34);
    queue.push(67);
    queue.push(43);
    queue.push(55);
    
    moveNthFront(queue, n);
    
    while(!queue.empty()){
        cout << queue.front() << " ";
        queue.pop();
    }

    return 0;
}
