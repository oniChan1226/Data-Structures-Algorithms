#include<iostream>
using namespace std;


struct StackNode{
    int data;
    StackNode* next;
    StackNode(int data):data{data}, next{NULL} {}
};

class Stack {
    StackNode* top;

public: 
    Stack():top{NULL} {}
    void push(int data) {
        StackNode* newNode = new StackNode(data);
        newNode->next = top;
        top = newNode;
    }
    int pop() {
        if(!top) return -1;
        StackNode* temp = top;
        int data = temp->data;
        top = top->next;
        delete temp;
        return data;
    }
    int peek() {
        if(!top) return -1;
        return top->data;
    }

    ~Stack() {
        if(!top) return;
        StackNode* temp = top;
        while(top != NULL) {
            temp = top;
            top = top->next;
            delete temp;
        }
    }

};

int main(){

    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << st.peek() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;


    return 0;
}