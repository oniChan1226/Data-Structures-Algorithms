#include <iostream>
#include <string>
#include <vector>
#include <sstream> // Include for std::stringstream
using namespace std;

void reverseString(string* ptr);
void concat(string* newStr, const string& a, const string& b, bool isSpaceNeeded = true);
void stringTokenizing(const string& str);
void swap(char& a, char& b);

int main() {
    string str = "Hello World! How's everything?";
    
    cout << "Original String: " << str << endl;
    
    reverseString(&str);
    cout << "Reversed String: " << str << endl;

    string a = "Hello", b = "World!", ab = "";
    concat(&ab, a, b, true);
    cout << "Concatenated String: " << ab << endl;

    stringTokenizing(ab);

    return 0;
}

void reverseString(string* ptr) {
    int length = ptr->length();
    cout << "Length of string: " << length << endl;

    for (int i = 0; i < length / 2; i++) {
        swap((*ptr)[i], (*ptr)[length - 1 - i]); 
    }
}

void swap(char& a, char& b){
    char temp = a;
    a = b;
    b = temp;
}

void concat(string* newStr, const string& a, const string& b, bool isSpaceNeeded) {
    *newStr += a; // Directly use += operator
    if (isSpaceNeeded) *newStr += " ";
    *newStr += b; // Directly append b
}

void stringTokenizing(const string& str) {
    vector<string> tokens;
    stringstream ss(str); // Use stringstream to tokenize
    string intermediate;

    while (getline(ss, intermediate, ' ')) {
        tokens.push_back(intermediate);
    }

    // Print all tokens
    for (const auto& token : tokens) {
        cout << token << endl;
    }
}
