#include <iostream>
#include <string>
using namespace std;

struct Customer {
    string name;
    int items;
    long int phone_no;
};

class CircularQueue {
private:
    int front, rear, size;
    Customer* queue;
    int capacity;

public:
    CircularQueue(int cap) {
        capacity = cap;
        queue = new Customer[capacity];
        front = rear = -1;
        size = 0;
    }

    bool isFull() {
        return (front == (rear + 1) % capacity);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void customerArrival(string name, long int phone, int items) {
        if (isFull()) {
            cout << "Checkout counter is full! No more customers can be added." << endl;
            return;
        }

        Customer newCustomer;
        newCustomer.name = name;
        newCustomer.phone_no = phone;
        newCustomer.items = items;

        if (isEmpty()) {
            front = 0;
        }

        rear = (rear + 1) % capacity;
        queue[rear] = newCustomer;
        size++;
        cout << "Customer " << name << " with " << items << " items has arrived." << endl;
    }

    void customerCheckout() {
        if (isEmpty()) {
            cout << "No customers to checkout." << endl;
            return;
        }

        cout << "Checking out customer: " << queue[front].name << " with " << queue[front].items << " items." << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        size--;
    }

    void closeCheckoutCounter() {
        if (!isEmpty()) {
            cout << "Cannot close the counter! There are still customers in the queue." << endl;
        } else {
            cout << "Checkout counter closed." << endl;
        }
    }

    void viewCustomers() {
        if (isEmpty()) {
            cout << "No customers in the queue." << endl;
            return;
        }

        cout << "Current customers in the queue:" << endl;
        int i = front;
        while (i != rear) {
            cout << "Customer: " << queue[i].name << ", Phone: " << queue[i].phone_no << ", Items: " << queue[i].items << endl;
            i = (i + 1) % capacity;
        }
        cout << "Customer: " << queue[rear].name << ", Phone: " << queue[rear].phone_no << ", Items: " << queue[rear].items << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the checkout counter: ";
    cin >> capacity;

    CircularQueue checkoutSystem(capacity);
    int choice;
    string name;
    long int phoneNo;
    int items;

    do {
        cout << "\nMenu:\n";
        cout << "1. Customer Arrival\n";
        cout << "2. Customer Checkout\n";
        cout << "3. Close Checkout Counter\n";
        cout << "4. View Customers in Queue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter customer name: ";
                cin.ignore(); 
                getline(cin, name);
                cout << "Enter phone number: ";
                cin >> phoneNo;
                cout << "Enter number of items: ";
                cin >> items;
                checkoutSystem.customerArrival(name, phoneNo, items);
                break;
            case 2:
                checkoutSystem.customerCheckout();
                break;
            case 3:
                checkoutSystem.closeCheckoutCounter();
                break;
            case 4:
                checkoutSystem.viewCustomers();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
