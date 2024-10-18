#include<iostream>
#include<vector>
using namespace std;

void merge(int a[], int low, int mid, int high)  {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> left(n1), right(n2);
    for(int i = 0; i < n1; i++)
        left[i] = a[low + i];
        
    for(int i = 0; i < n2; i++)
        right[i] = a[mid + 1 + i];

    int i = 0, j = 0, k = low;
    while(i < n1 && j < n2) {
        a[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
    }
    while(i < n1) 
        a[k++] = left[i++];
    
    while(j < n2) 
        a[k++] = right[j++];

}

void mergeSort(int a[], int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a,low,mid,high);
    }
}

// void mergeSort(int a[], int b[], int a_size, int b_size, bool isZeroIndexBased = false) {
//     if(!isZeroIndexBased) {
//         a_size--;
//         b_size--;
//     }
//     int i = 0, j = 0;
//     vector<int> arr;
//     while(i <= a_size && j <= b_size) {
//         if(a[i] < b[j]) arr.push_back(a[i++]);
//         else arr.push_back(b[j++]);
//     }
//     for(; i <= a_size; i++) arr.push_back(a[i]);
//     for(; j <= b_size; j++) arr.push_back(a[j]);
//     for(int ele: arr) {
//         cout << ele << " ";
//     }
//     cout << endl;
// }

int main(){

    int a[5] = {1,3,4,8,10};
    int b[2] = {0, 5};

    int arr[8] = {23, 1, 45, 10, 2, 67, 34, 5};

    cout << "Before mergeSort: ";
    for(int i: arr) {
        cout << i << " ";
    }
    cout << endl;

    mergeSort(arr, 0, 7);

    cout << "After mergeSort: ";
    for(int i: arr) {
        cout << i << " ";
    }
    cout << endl;

    // mergeSort(a,b,5,2);


    return 0;
}