#include <iostream>
#include <string>

using namespace std;

class Stack {
    char stack[100];
    static int top;
public:
    void push(char c) {
        top++;
        stack[top] = c;
    }

    void pop() {
        if (top > -1) {
            top--;
        }
    }

    char getTop() {
        if (top > -1) {
            return stack[top];
        }
        return '\0';
    }

    bool empty() {
        return top == -1;
    }

    string reverseExp(string a, int n){
        Stack s;

        for(int i = 0; i < n; i++){
            s.push(a[i]);
        }

        string reverse = "";

        while(!s.empty()){
            if(s.getTop() == '('){
                reverse += ')';
                s.pop();
            }
            else if(s.getTop() == ')' ){
                reverse += '(';
                s.pop();
            }
            else{
                reverse += s.getTop();
                s.pop();
            }
        }

        return reverse;
    }

    string reverse(string a, int n){
        Stack s;

        
        for(int i = 0; i < n; i++){
            s.push(a[i]);
        }

        string reverse = "";

        while(!s.empty()){
            reverse += s.getTop();
            s.pop();
        }

        return reverse;
    }
};

int Stack::top = -1;

int priority(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string infixToPostfix(string infix, int n) {
    Stack s;
    string postfix = "";

    for(int i = 0; i < n; i++) {
        char c = infix[i];

        if(c == '(') {
            s.push(c);
        }
        else if(c == ')') {
            while(!s.empty() && s.getTop() != '(') {
                postfix += s.getTop();
                s.pop();
            }
            s.pop();
        }
        else if(isOperator(c)) {
            while(!s.empty() && priority(s.getTop()) >= priority(c)) {
                postfix += s.getTop();
                s.pop();
            }
            s.push(c);
        }
        else {
            postfix += c;
        }
    }

    while (!s.empty()) {
        postfix += s.getTop();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "\nEnter an infix expression: ";
    cin >> infix;

    Stack s;

    int n = infix.length();

    string reverseInfix = s.reverseExp(infix,n);
    string postfix = infixToPostfix(reverseInfix,n);
    string prefix = s.reverse(postfix,postfix.length());

    cout << "\nPrefix expression: " << prefix << endl;

    return 0;
}