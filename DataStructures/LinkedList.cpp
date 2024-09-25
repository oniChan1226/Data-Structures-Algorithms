#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;

public: 
    LinkedList():head{NULL} {}
    void insert(int data) {
        Node* newNode = new Node;
        newNode->next = NULL;
        newNode->data = data;
        if(head == NULL) head = newNode;
        else {
            Node* temp = head;
            while(temp->next != NULL) temp = temp->next;
            temp->next = newNode;
        }
    }
    void display(){
        if(head == NULL) return;
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    
};

int main(){

    LinkedList l1;
    l1.insert(10);
    l1.insert(1);
    l1.insert(20);
    l1.insert(320);

    l1.display();


    return 0;
}