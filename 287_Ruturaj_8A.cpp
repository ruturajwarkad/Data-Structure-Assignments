#include <iostream>
using namespace std;

class Stack {
    int top;
    int arr[100];  

public:
    Stack() { top = -1; }

    void push(int value) {
        if (top >= 99) {
            cout << "Stack Overflow\n";
        } else {
            arr[++top] = value;
        }
    }

    int pop() {
        if (top < 0) {
            cout << "Stack Underflow\n";
            return -1;
        } else {
            return arr[top--];
        }
    }

    int peek() {
        if (top < 0) {
            cout << "Stack is empty\n";
            return -1;
        } else {
            return arr[top];
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};

int evaluatePostfix(string expression) {
    Stack s;
    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];

        if (ch >= '0' && ch <= '9') {
            s.push(ch - '0');
        } else {
            int val2 = s.pop();
            int val1 = s.pop();
            
            switch (ch) {
                case '+':
                    s.push(val1 + val2);
                    break;
                case '-':
                    s.push(val1 - val2);
                    break;
                case '*':
                    s.push(val1 * val2);
                    break;
                case '/':
                    s.push(val1 / val2);
                    break;
            }
        }
    }
    return s.peek();
}

int main() {
    string expression = "53+2*";
    cout << "Postfix Evaluation of " << expression << " is: "
         << evaluatePostfix(expression) << endl;
    return 0;
}
