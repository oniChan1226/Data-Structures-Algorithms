#include<iostream>
using namespace std;

int main(){

    int* arr = NULL;
    int size;

    cin >> size;

    arr = new int[5]{};

    for (size_t i = 0; i < size; i++)
    {
        // arr[i] = i;
        cout << arr[i] << " ";
    }
    

    delete[] arr;


    return 0;
}