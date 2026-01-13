#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Sort the following list in descending order using the merge sort algorithm. Show the list
// after each iteration.
// 50, 36, 78, 40, 4, 28, 90, 62, 2

void merge(int a[], int low, int mid, int high){
    int temp[9];
    int left = low;
    int tempIndex = low;
    int right = mid + 1;
    
    while(left <= mid && right <= high){
        if(a[left] >= a[right]){
            temp[tempIndex++] = a[left++];
        } else {
            temp[tempIndex++] = a[right++];
        }
    }
    
    while(left <= mid){
        temp[tempIndex++] = a[left++];
    }
    while(right <= high){
        temp[tempIndex++] = a[right++];
    }
    
    for(int i = low; i <= high; i++){
        a[i] = temp[i];
    }
}

void mergeSort(int a[], int low, int high){
    if(low < high){
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main() {
    int numbers[] = {50, 36, 78, 40, 4, 28, 90, 62, 2};
    mergeSort(numbers, 0, 8);
    
    for(int i = 0; i < 9; i++){
        cout << numbers[i] << " ";
    } 
    cout << endl;

    return 0;
}
