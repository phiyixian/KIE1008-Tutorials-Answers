// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>
using namespace std;

int main() {
    std::stack<int> stack;
    
    int temp;
    
    stack.push(28);
    stack.push(16);
    temp = stack.top(); //16
    
    stack.push(temp - 3); //13
    cout << stack.top() << endl; //13 (Output)
    stack.push(2 * temp); //32
    stack.push(50);
    temp = stack.top() / 3; //16
    stack.pop(); //remove 16
    stack.push(32);
    
    while (!stack.empty())
    {
        cout << stack.top() << " "; //32 50 32 13 16 28 (Output)
        stack.pop();
    }
    cout << endl;
    cout << "temp = " << temp << endl; //16

    return 0;
}
