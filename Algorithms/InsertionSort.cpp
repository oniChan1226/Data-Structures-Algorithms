#include<iostream>
#include<vector>
using namespace std;

void insertionSort(int arr[]) {
    for(int i = 1; i < 6; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    cout << endl;
}
void insertionSortRev(int arr[]) {
    for(int i = 1; i < 6; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

bool bruteForceSearch(int arr[], int key) {
    for(int i = 0; i < 6; i++) {
        if(arr[i] == key) {
            return 1;
        }
    }
    return 0;
}

void addBinaryIntegers(int a[], int b[], int n) {
    vector<int> c(n + 1, 0);
    int carry = 0;
    for(int i = 0; i < n; i++) {
        int sum = a[i] + b[i] + carry;
        c[i + 1] = sum % 2;
        // Update carry (1 if sum is 2 or 3, 0 otherwise)
        carry = sum / 2;
    }
    c[0] = carry;
    for(int element: c) {
        cout << element << " ";
    }
    cout << endl;

}

int main(){

    // int arr[] = {5,2,4,6,1,3};

    // insertionSort(arr);
    // for(int element: arr) {
    //     cout << element << " ";
    // }
    // cout << endl;

    // insertionSortRev(arr);
    // for(int element: arr) {
    //     cout << element << " ";
    // }
    // cout << endl;

    // cout << bruteForceSearch(arr, 10);

    int a[] = {1, 0, 1, 1};
    int b[] = {1, 1, 1, 0};
    int n = 4; // no. of bits
    addBinaryIntegers(a, b, n);

    return 0;
}