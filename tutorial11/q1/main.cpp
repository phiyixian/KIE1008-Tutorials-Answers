#include <iostream>
using namespace std;
// 1. Consider the following list:
// 2, 20, 38, 41, 49, 56, 62, 70, 88, 95, 100, 135, 145
// (a) Show the steps of searching
// i. 32 ii. 20 iii. 105 iv. 60
// using binary search. Show the values of first, last, and middle after each iteration
// of the loop.
// (b) Compare the average number of comparisons needed for binary search and linear
// search.

void linearSearch(int num, int nums[], int s){
    int linear_count = 0;
    bool found = false;
    for(int i = 0; i < s; i++){
        if(nums[i] == num){
            cout << num << " found after " << linear_count << " times." << endl;
        }
        linear_count++;
    }
    
    if(!found) cout << "Not found." << endl;
}

void binarySearch(int num, int nums[], int s){
    
    int first = 0;
    int last = s - 1;
    bool found = false;
    
    int binary_count = 0;
    
    while(first <= last && !found){
        int mid = (first + last) / 2;
        binary_count++;
        
        cout << "First: " << first << endl;
        cout << "Last: " << last << endl;
        cout << "Mid: " << mid << endl;
        cout << endl;
        
        if(nums[mid] == num){
            found = true;
            cout << num << " found after " << binary_count << " times." << endl;
        } else if (nums[mid] > num){
            last = mid - 1;
        } else {
            first = mid + 1;
        }
    }  
    
    if(!found){
        cout << "Not found." << endl;
    }
}

int main() {
    int numbers[13] = {2, 20, 38, 41, 49, 56, 62, 70, 88, 95, 100, 135, 145};
    int size = sizeof(numbers) / 4;
    cout << size << endl;
    
    binarySearch(32, numbers, size);
    binarySearch(20, numbers, size);
    binarySearch(145, numbers, size);
    binarySearch(60, numbers, size);
    
    linearSearch(32, numbers, size);
    linearSearch(20, numbers, size);
    linearSearch(145, numbers, size);
    linearSearch(60, numbers, size);

    return 0;
}
