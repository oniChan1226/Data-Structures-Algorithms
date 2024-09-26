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
        cout << endl;
    }
    // Reverse a linkedList
    void reverseListIterative() {
        if(head == NULL || head->next == NULL) return;
        Node* curr = head, *prev = NULL, *next;
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        head = prev;
    }
    void reverseListRecursive() {
        head = reverseRecursive(head);
    }
    Node* reverseRecursive(Node* head) {
        if(head == NULL || head->next == NULL) return head;
        Node* newHead = reverseRecursive(head->next);
        // 1 -> next => 2 => 2->next = head => 2->next = 1;
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    // Search element
    int search(int data) {
        if(head == NULL) return -1;
        int count = 0;
        Node* temp = head;
        while(temp != NULL) {
            if(temp->data == data){
                return count;
            }
            temp = temp->next;
            count++;
        }
    }
    // Middle element of linkedList
    int getMiddle() {
        if(head == NULL) return -1;
        else if(head->next == NULL) return head->data;
        // Floyd's Hare & Tortoise
        else {
            Node* fast = head, *slow = head;
            while(fast != NULL && fast->next != NULL) {
                fast = fast->next->next;
                slow = slow->next;
            }
            return slow->data;
        }
    }

    ~LinkedList(){
        if(head == NULL) return;
        Node* temp = head, *prev;
        while(temp != NULL) {
            prev = temp;
            temp = temp->next;
            delete prev;
        }
    }
    
};

int main(){

    LinkedList l1;
    l1.insert(10);
    l1.insert(20);
    l1.insert(9);
    l1.insert(12);
    l1.insert(41);
    l1.insert(23);
    l1.insert(12);
    // l1.reverseListIterative();
    // l1.reverseListRecursive();
    // cout << l1.search(12) << endl;
    // cout << l1.getMiddle() << endl;


    return 0;
}