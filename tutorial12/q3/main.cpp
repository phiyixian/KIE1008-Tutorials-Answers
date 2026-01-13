#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int merge_compare = 0;
int merge_assign = 0;

int insert_compare = 0;
int insert_assign = 0;

int quick_compare = 0;
int quick_assign = 0;
// 3. Write a program that creates three identical arrays, list1, list2, and list3, of 5000
// elements. The program then sorts list1 using quick sort, list2 using insertion sort, and
// list3 using merge sort and outputs the number of comparisons and item assignments
// made by each sorting algorithm.

void insertSort(int a[], int size){
    for(int i = 1; i < size; i++){
        for(int j = i; j > 0 && a[j] < a[j - 1]; j--){
            insert_compare++;
            int temp = a[j];
            a[j] = a[j - 1];
            insert_assign+=2;
            a[j - 1] = temp;
        }
    }
}

void quickSort(int a[], int left, int right){
    int x = left;
    int y = right;
    
    int pos = (x + y) / 2;
    int pivot = a[pos];
    
    while(x <= y){
        while(a[x] < pivot){
            quick_compare++;
            x++;
        }
        while(a[y] > pivot){
            quick_compare++;
            y--;
        }
        if(x <= y){
            int temp = a[x];
            quick_assign+=2;
            a[x] = a[y];
            a[y] = temp;
            x++;
            y--;
        }
    }
    
    if(left < y){
        quickSort(a, left, y);
    } 
    if(right > x){
        quickSort(a, x, right);
    }
}

void merge(int a[], int low, int mid, int high){
    int left = low;
    int tempIndex = low;
    int right = mid + 1;
    int temp[5000];
    
    while(left <= mid && right <= high){
        if(a[left] >= a[right]){
            merge_compare++;
            merge_assign++;
            temp[tempIndex++] = a[left++];
        } else {
            merge_assign++;
            temp[tempIndex++] = a[right++];
        }
    }
    
    while(left <= mid){
        merge_assign++;
        temp[tempIndex++] = a[left++];
    }
    while(right <= high){
        merge_assign++;
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

void print(int a[]){
    for(int i = 0; i < 5000; i++){
        cout << a[i] << ", ";
        if(i % 10 == 0){
            cout << endl;
        }
    }
    cout << endl;
}

int main() {
    srand(time(0));
    int list1[5000];
    int list2[5000];
    int list3[5000];
    for(int i = 0; i < 5000; i++){
        int value = rand() % 5000 + 1;
        list1[i] = value;
        list2[i] = value;
        list3[i] = value;
    }
    quickSort(list1, 0, 4999);
    print(list1);
    
    insertSort(list2, 5000);
    print(list2);
    
    mergeSort(list3, 0, 4999);
    print(list3);
    
    cout << "Insert compare: " << insert_compare << endl;
    cout << "Insert assign: " << insert_assign << endl;
    cout << endl;
    
    cout << "Quick compare: " << quick_compare << endl;
    cout << "Quick assign: " << quick_assign << endl;
    cout << endl;
    
    cout << "Merge compare: " << merge_compare << endl;
    cout << "Merge assign: " << merge_assign << endl;
    cout << endl;
    

    return 0;
}
