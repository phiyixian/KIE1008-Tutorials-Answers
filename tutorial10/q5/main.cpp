#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

// Write a program that uses a stack adapter to print the prime factors of 
// a positive integer in descending order. 

void printPrime(int n){
    stack <int> stack;
    int tool = 2;
    int temp = n;
    
    while (temp > 1){
        if(temp % tool == 0){
            stack.push(tool);
            temp /= tool;
        } else {
            tool++;
        }
    }
    
    while(!stack.empty()){
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
}

int main() {
    printPrime(124);
    printPrime(871);
    printPrime(39);
    
    return 0;
}
