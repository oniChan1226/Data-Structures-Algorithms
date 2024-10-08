#include<iostream>
using namespace std;

class Queue {
    int *arr;
    int front;
    int rear;
    int capacity;
    int currentSize;
public:
    Queue(int size){
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        currentSize = 0;
    }
    ~Queue() {
        delete[] arr;
    }
    void push_back(int data) {
        if(currentSize >= capacity) return;
        rear = (rear + 1) % capacity; // Circular increment of front depending upion capacity
        arr[rear] = data;
        currentSize++;
    }
    int pop_front() {
        if(currentSize == 0) return -1;
        int data = arr[front];
        front = (front + 1) % capacity;
        currentSize--;
        return data;
    }
    int get_front() {
        if(currentSize == 0) return -1;
        return arr[front];
    }
    int get_rear(){
        if(currentSize == 0) return -1;
        return arr[rear];
    }
    int size() {
        return currentSize;
    }
};

int main(){

    Queue dq(5); // Create a queue of capacity 5

    dq.push_back(10); // Insert at the back
    dq.push_back(20); // Insert at the back
    dq.push_back(30); // Insert at the back
    dq.push_back(40); // Insert at the back
    dq.push_back(50); // Insert at the back
    dq.push_back(60); // Try to insert in a full queue

    cout << "Front: " << dq.get_front() << endl; // 10
    cout << "Back: " << dq.get_rear() << endl;   // 50

    cout << "Popped from front: " << dq.pop_front() << endl; // 10
    cout << "Popped from front: " << dq.pop_front() << endl; // 20
    cout << "Current size: " << dq.size() << endl; // 3

    dq.pop_front(); // Remove from the front
    dq.pop_front(); // Remove from the front
    dq.pop_front(); // Try to remove from empty queue


    return 0;
}