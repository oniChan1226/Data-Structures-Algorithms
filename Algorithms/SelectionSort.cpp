#include<iostream>
using namespace std;

void selectionSort(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        int min = arr[i];
        for(int j = i + 1; j < size; j++) {
            if(arr[j] < min) {
                int temp = min;
                min = arr[j];
                arr[j] = temp;
            }
        }
        arr[i] = min;
    }
}

int main(){

    int arr[5] = {5,1,3,4,2};
    selectionSort(arr, 5);
    for(int ele: arr) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}