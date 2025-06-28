#include <iostream>
using namespace std;

struct node {
    string name;
    int num;
    long int phone_no;
    node* next;
};

class WaitlistQueue { 
private:
    node* front;
    node* rear;

public:
    WaitlistQueue() {
        front = NULL;  
        rear = NULL;  
    }

    bool isempty() {
        return front == NULL;  
    }

    void enqueue(string n, long int ph, int p) {
        node* nn = new node;
        if (!nn) {
            return;
        }

        nn->name = n;
        nn->phone_no = ph;
        nn->num = p;
        nn->next = NULL;

        if (isempty()) {
            front = rear = nn;
        } else {
            rear->next = nn;
            rear = nn;
        }

        cout << "You are added to the waitlist: " << n << endl;
    }

    void dequeue() {
        if (isempty()) {
            cout << "Waitlist is empty." << endl;
            return;
        }

        node* temp = front;
        cout << "Seating Customer: " << front->name << " (Phone: " << front->phone_no
             << ", People: " << front->num << ")" << endl;

        front = front->next;
        delete temp;

        if (isempty()) {
            rear = NULL;
        }
    }

    void display() {
        if (isempty()) {
            cout << "Waitlist is empty." << endl;
            return;
        }

        node* temp = front;
        cout << "Current waitlist:" << endl;
        while (temp != NULL) {
            cout << "Name: " << temp->name << ", Phone: " << temp->phone_no
                 << ", People: " << temp->num << endl;
            temp = temp->next;
        }
    }
};

int main() {
    WaitlistQueue waitlist; 
    int choice;

    do {
        cout << "\n1. Add Customer to waitlist\n2. Seat customer\n3. Display waitlist\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            long int phoneNo;
            int numPeople;
            cout << "Enter Customer name: ";
            cin >> name;
            cout << "Enter Phone number: ";
            cin >> phoneNo;
            cout << "Enter number of people: ";
            cin >> numPeople;

            waitlist.enqueue(name, phoneNo, numPeople);
        } else if (choice == 2) {
            waitlist.dequeue();
        } else if (choice == 3) {
            waitlist.display();
        }

    } while (choice != 4);

    return 0;
}
