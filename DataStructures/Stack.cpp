#include<iostream>
using namespace std;

#define SIZE 100

template <typename T>

class Stack {
    int top;
    T data[SIZE];
public:
    Stack():top{-1} {}
    void push(T value) {
        if(top >= SIZE - 1) return;
        this->data[++top] = value;
    }
    T pop() {
        if(top < 0) return T();
        return data[top--];
    }
    T peek() {
        if(top < 0) return T();
        return data[top];
    }
    T isEmpty(){
        return (top < 0);
    }
    string reverseString(const string& str){
        Stack<char> st;
        int length = str.length();
        int i = 0; 
        while(i < length) {
            st.push(str[i]);
            i++;
        }
        string reversedString = "";
        while(!st.isEmpty()){
            reversedString += st.pop();
        }
        return reversedString;
    }
    bool checkPalindrome(const string& str) {
        string reversedString = reverseString(str);
        return (reversedString == str);
    }
};

int main(){

    Stack<char> st;
    // st.peek();
    // st.push(10);
    // st.push(20);
    // st.push(30);
    // st.peek();
    // cout << st.pop();
    // cout << st.pop();
    // cout << st.pop();
    // cout << st.pop();
    // cout << st.reverseString("Fahad Khan") << endl;
    cout << "Is string palindrome? " << (st.checkPalindrome("ada") ? "Yes" : "No") << endl;
    cout << "Is string palindrome? " << (st.checkPalindrome("hello") ? "Yes" : "No") << endl;



    return 0;
}