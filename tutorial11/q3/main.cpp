#include <iostream>
#include <vector>
using namespace std;

// 3. Suppose that the size of a hash table is 101, and that certain keys 
// with the indices 15, 101, 116, 210, 0, 98, 21 and 217 are to be inserted 
// in this order into an initially empty hash table. Using modular arithmetic,
// find the indices in the hash table if linear probing is used.
// Repeat if quadratic probing is used instead.

int main() {
    int tablesize = 101;
    vector <int> table(tablesize, 0);
    vector <int> table1(tablesize, 0);
    
    int numbers[] = {15, 101, 116, 210, 0, 98, 21, 217};
    int size = sizeof(numbers) / 4;
    
    int linear_count = 0;
    int quadratic_count = 0;
    
    cout << "Linear Probing" << endl;
    for(int i = 0; i < size; i++){
        int index = numbers[i] % tablesize;
        while(table[index] != 0){
            index = (index + 1) % tablesize;
            linear_count++;
        }
        
        cout << "Index: " << index << endl;
        cout << "Value: " << numbers[i] << endl;
        cout << endl;
        table[index] = numbers[i];
    }
    
    cout << "Quadratic Probing" << endl;
    for(int i = 0; i < size; i++){
        int index = numbers[i] % tablesize;
        int j = 1;
        while(table[index] != 0){
            index = (index + j * j) % tablesize;
            j++;
            quadratic_count++;
        }
        
        cout << "Index: " << index << endl;
        cout << "Value: " << numbers[i] << endl;
        cout << endl;
        table[index] = numbers[i];
    }
    
    cout << "Linear count: " << linear_count << endl;
    cout << "Quadratic count: " << quadratic_count << endl;
    
    return 0;
}
