#include <iostream>
#include <vector>
using namespace std;

// 4. Suppose in a class, there are 50 students. In the school registry system, each student’s
// name and his/her father’s name are recorded. State a suitable hash size and implement a
// function hash which calculates the hash value from the combination of those two names.
// The prototype of the hash function is given below.
// int hash (string &name, string &fatherName, int hashSize);

int hashFunction(string &name, string &fatherName, int hashSize){
    int value = 0;
    int name_length = name.length();
    int fatherName_length = fatherName.length();
    int length = name_length + fatherName_length;
    
    for(int i = 0; i < length; i ++){
        value += name[i];
        value += fatherName[i];
    }
    
    return value % hashSize;
}
int main() {
    string son = "John";
    string father = "Jordan";
    cout << hashFunction(son, father, 5) << endl;
    
    son = "Mobby";
    father = "Derrence";
    cout << hashFunction(son, father, 5) << endl;
    
    return 0;
}
