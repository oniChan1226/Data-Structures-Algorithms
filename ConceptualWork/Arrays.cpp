#include<iostream>
using namespace std;

void funFunction(int*, int);
void funFunction2(int[], int);

int main(){

    int arr[5] = {1,2,3,4,5};
    int length = sizeof(arr)/ sizeof(arr[0]);
    // funFunction(arr, length);
    funFunction2(arr, length);

    for(int element: arr) cout << element << " ";

    return 0;
}
void funFunction(int* ptr, int length = 5) {
    for(int i = 0; i < length; i++) ptr[i] *= 2; 
}
void funFunction2(int ptr[], int length = 5) {
    for(int i = 0; i < length; i++) ptr[i] *= 2; 
}
