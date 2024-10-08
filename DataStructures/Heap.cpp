#include<iostream>
#include<vector>
using namespace std;

class Heap {
    vector<int> array;
    vector<int> sortedArray;
    void heapify(int);

public: 
    Heap() = default;
    void insert(int);
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
    int getMax();
    void printHeap();
    void printSortedHeap();

};

void Heap:: heapify(int i) {
    int largest = i;
    int leftChild = i * 2 + 1;
    int rightChild = i * 2 + 2;
    int size = array.size();

    if(leftChild < size && array[leftChild] > array[largest]) largest = leftChild;
    if(rightChild < size && array[rightChild] > array[largest]) largest = rightChild;
    
    if(largest != i) {
        swap(array[i], array[largest]);
        heapify(largest);
    }

}

void Heap:: insert(int data) {
    array.push_back(data);
    int i = array.size() - 1;
    while(i != 0 && array[(i-1)/2] < array[i]) {
        swap(array[i], array[(i-1)/2]);
        i = (i-1)/2;    // Parent Element
    }
}

void Heap:: printHeap() {
    for(int data : array) {
        cout << data << " ";
    }
    cout << endl;
}

void Heap:: printSortedHeap() {
    for(int data: sortedArray) {
        cout << data << " ";
    }
    cout << endl;
}

int Heap:: getMax() {
    if(array.size() <= 0) return -1;

    int root = array[0];
    int extractedValue = root;
    if(array.size() == 1){
        array.pop_back();
        sortedArray.push_back(extractedValue);
        return root;
    }

    array[0] = array.back();
    array.pop_back();
    heapify(0);
    sortedArray.push_back(extractedValue);
    return root;
}

int main(){

    Heap heap;
    heap.insert(2);
    heap.insert(10);
    heap.insert(1);
    heap.insert(23);

    heap.printHeap();  

    heap.getMax();
    heap.getMax();
    heap.getMax();
    heap.getMax();

    heap.printHeap();
    heap.printSortedHeap();

    return 0;
}