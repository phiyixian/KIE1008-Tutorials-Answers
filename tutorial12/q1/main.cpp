#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Suppose list is an array of 1000 elements.
// (a) Use a random number generator to fill list.
// (b) Sort the array using the quick sort algorithm. Use pivot as the middle element of the
// array. However, when the size of any sublist reduces to less than 20, sort the sublist
// using an insertion sort.

void insertSort(int a[], int left, int right){
    for(int i = left + 1; i <= right; i++){
        for(int j = i; j > left && a[j] < a[j - 1]; j--){
            int temp = a[j - 1];
            a[j - 1] = a[j];
            a[j] = temp;
        }
    }
}

void quickSort(int a[], int left, int right){
    if(right - left + 1 <= 20){
        insertSort(a, left, right);
        return;
    }
    
    int pos = (left + right) / 2;
    int pivot = a[pos];
    int x = left;
    int y = right;
    int temp = 0;
    
    while(x <= y){
        while(a[x] < pivot){
            x++;
        }
        while(a[y] > pivot){
            y--;
        }
        if(x <= y){
            temp = a[x];
            a[x] = a[y];
            a[y] = temp;
            x++;
            y--;
        }
    }
    if(left < y){
        quickSort(a, left, y);
    }
    if(x < right){
        quickSort(a, x, right);
    }
}

void print(int a[]){
    for(int i = 0; i < 1000; i++){
        cout << a[i] << ", ";
        if ((i + 1) % 10 == 0){
            cout << endl;
        }
    }
}

int main() {
    srand(time(0));
    
    int numbers[1000];
    for(int i = 0; i < 1000; i++){
        numbers[i] = rand() % 1000 + 1;
    }
    quickSort(numbers, 0, 999);
    print(numbers);

    return 0;
}
