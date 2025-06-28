#include<iostream>
using namespace std;

struct Node {
    int coeff; 
    int exp;   
    Node* next;
};

class Polynomial {
private:
    Node* head;  

public:
    Polynomial() {
        head = nullptr;
    }

    // function for inserting polynomial term 
    void Create(int coeff, int exp) {
        Node* newNode = new Node;
        newNode->coeff = coeff;
        newNode->exp = exp;
        newNode->next = nullptr;

        if (!head || exp > head->exp) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next && temp->next->exp > exp) {
                temp = temp->next;
            }

            if (temp->next && temp->next->exp == exp) {
                temp->next->coeff += coeff;
                delete newNode;  
            } else {
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }

    // function to display polynomial
    void Display() {
        if (!head) {
            cout << "0" << endl;
            return;
        }

        Node* temp = head;
        while (temp) {
            if (temp->coeff != 0) {
                cout << temp->coeff << "x^" << temp->exp;
                if (temp->next && temp->next->coeff > 0)
                    cout << " + ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    // function to add polynomial equations 
    Polynomial Add(Polynomial P2) {
        Polynomial P3;
        Node* p1 = this->head;
        Node* p2 = P2.head;

        while (p1 && p2) {
            if (p1->exp == p2->exp) {
                P3.Create(p1->coeff + p2->coeff, p1->exp);
                p1 = p1->next;
                p2 = p2->next;
            } else if (p1->exp > p2->exp) {
                P3.Create(p1->coeff, p1->exp);
                p1 = p1->next;
            } else {
                P3.Create(p2->coeff, p2->exp);
                p2 = p2->next;
            }
        }

        // if terms left add them to P3
        while (p1) {
            P3.Create(p1->coeff, p1->exp);
            p1 = p1->next;
        }

        while (p2) {
            P3.Create(p2->coeff, p2->exp);
            p2 = p2->next;
        }

        return P3;
    }
};

int main() {
    Polynomial P1, P2, P3;

    // inserting terms in P1
    P1.Create(6, 4);  // 6x^4
    P1.Create(7, 3);  // 7x^3
    P1.Create(9, 2);  // 9x^2
    P1.Create(4, 0);  // 4x^0

    // inserting terms in P2
    P2.Create(4, 3);  // 4x^3
    P2.Create(7, 2);  // 7x^2
    P2.Create(2, 1);  // 2x^1
    P2.Create(1, 0);  // 1x^0

    cout << "P1: ";
    P1.Display();

    cout << "P2: ";
    P2.Display();

    P3 = P1.Add(P2);

    cout << "P3:  ";
    P3.Display();

    return 0;
}
