#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

// Write a C++ code that processes the following input as follows: 
// If the number is nonnegative, it pushes the square root of the number 
// onto the stack; otherwise it pushes the square of the number onto the stack/ 
// After processing these numbers write a C++ code that outputs the elements of
// the stack. The input is
// 25 64 -3 6.25 36 -4.5 86 14 -12 9

int main() {
    stack <int> stack;
    double numbers[] = {25, 64, -3, 6.25, 36, -4.5, 86, 14, -12, 9};
    for(double num: numbers){
        if(num < 0){
            stack.push(pow(num, 2));
        } else {
            stack.push(sqrt(num));
        }
    }
    while(!stack.empty()){
        cout << stack.top() << ' ';
        stack.pop();
    }

    return 0;
}
