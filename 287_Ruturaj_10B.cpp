#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

class MyQueue {
private:
    node* front;
    node* rear;

public:
    MyQueue() {
        front = rear = NULL;
    }

    bool isempty() {
        return front == NULL;
    }

    void enqueue(int k) {
        node* nn = new node;
        nn->data = k;
        nn->next = NULL;
        if (isempty()) {
            front = rear = nn;
        } 
        else {
            rear->next = nn;
            rear = nn;
        }
    }

    int dequeue() {
        if (isempty()) {
            return -1;
        }
        node* temp = front;
        int data = front->data;
        front = front->next;
        delete temp;

        if (isempty()) {
            rear = NULL;
        }

        return data;
    }

    int peekFront() const {
        if (front != NULL) {
            return front->data;
        }
        return -1; // Or any other error indication
    }
};

class Stackusingqueues {
private:
    MyQueue Q1, Q2;

public:
    void push(int k) {
        Q1.enqueue(k);
    }

    int pop() {
        if (Q1.isempty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        // Move all elements except the last one from Q1 to Q2
        while (Q1.isempty() == false && Q1.peekFront() != Q1.dequeue()) {
            Q2.enqueue(Q1.dequeue());
        }

        // Last element in Q1 is the top of the stack
        int topElement = Q1.dequeue();

        // Move elements back to Q1
        while (!Q2.isempty()) {
            Q1.enqueue(Q2.dequeue());
        }

        return topElement;
    }

    bool isempty() {
        return Q1.isempty();
    }
};

int main() {
    Stackusingqueues s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << endl; // Should output 30
    cout << s.pop() << endl; // Should output 20
    cout << s.pop() << endl; // Should output 10

    return 0;
}