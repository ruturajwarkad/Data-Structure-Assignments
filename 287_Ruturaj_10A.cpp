#include <iostream>
#include <stack>

using namespace std;

class Queue {
	stack<int> instack, outstack;

public:
	void enqueue(int x) {
		instack.push(x);
        	cout << "Enqueued " << x << endl;
    	}

	void dequeue() {
        	if (outstack.empty()) {
            		while (!instack.empty()) {
                		outstack.push(instack.top());
                		instack.pop();
            		}
        	}
        	if (outstack.empty()) {
        		cout << "Queue is empty" << endl;
           		return;
        	}
        	int front = outstack.top();
        	outstack.pop();
        	cout << "Dequeued " << front << endl;
	}

    	void display() {
        	if (instack.empty() && outstack.empty()) {
            		cout << "Queue is empty" << endl;
            		return;
        	}
		stack<int> tempstack;
        

        	while (!instack.empty()) {
            		tempstack.push(instack.top());
            		instack.pop();
        	}

        	cout << "Current Queue: ";
        		while (!tempstack.empty()) {
            			cout << tempstack.top() << " ";
            			instack.push(tempstack.top()); 
            			tempstack.pop();
        		}
        		cout << endl;
	}
};

int main() {
    Queue Q;

    Q.enqueue(10);
    Q.enqueue(20);
    Q.enqueue(30);
    Q.enqueue(40);

    Q.dequeue();

    Q.enqueue(50);

    Q.display();

    return 0;
}

