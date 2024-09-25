#include <iostream>
using namespace std;

int BinarySearchRecursive(int arr[], int, int, int);
int BinarySearchIterative(int arr[], int, int);

int main() {
    // Must be sorted for Binary Search
    int arr[] = { 2, 3, 4, 10, 40 };

    int length = 0;
    for(int element: arr) length++;

    cout << "BinarySearchRecursive: " << BinarySearchRecursive(arr, 0, length - 1, 10) << endl;
    cout << "BinarySearchIterative: " << BinarySearchIterative(arr, 10, length - 1) << endl;

    return 0;
}

int BinarySearchRecursive(int arr[], int start, int end, int key) {

    if(start > end) return -1;

    int mid = (start + end)/2;
    if(arr[mid] == key) return mid;
    else if(arr[mid] > key) return BinarySearchRecursive(arr, start, mid - 1, key);
    else return BinarySearchRecursive(arr, mid + 1, end, key);
}

int BinarySearchIterative(int arr[], int key, int length){
    int start = 0, end = length;
    int mid;

    while(start < end) {
        mid = (start + end)/2;

        if(arr[mid] == key) return mid;
        else if(arr[mid] > key) end = mid - 1;
        else start = mid + 1;
    }

    return -1;
}