#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue <int> queue;
    
    int temp = 20;
    queue.push(15); //15
    queue.push(8); //15 8
    queue.push(temp); //15 8 20
    queue.push(42); //15 8 20 42
    temp = queue.front(); //15
    
    queue.pop();//8 20 42
    queue.push(temp - 10); //8 20 42 5
    queue.push(16); //8 20 42 5 16
    queue.push(2 * temp); //8 20 42 5 16 30
    queue.pop(); //20 42 5 16 30
    cout << "Queue elements: ";
    
    while (!queue.empty())
    {
        cout << queue.front() << " ";
        queue.pop();
    }
    
    cout << endl;
    cout << "temp = " << temp << endl; //15

    return 0;
}
