#include<iostream>
using namespace std;

struct link {
    string word;    
    link* next;     
    link* prev;    
};

//class buffer
class buffer {
public:
    link* head, * tail;  
    
    buffer() {
        head = tail = NULL;
    }

    void append(string word) {
        link* newnode = new link();   
        newnode->word = word;
        newnode->next = NULL;
        newnode->prev = tail;

        if (head == NULL) {
            head = tail = newnode;
            return;
        } 
        else {
            tail->next = newnode;
            tail = newnode;  
        }
    }

    // remove word from list
    void remove(string w) {
        link* curr = head;

        while (curr != NULL) {
            if (curr->word == w) {

                if (curr->prev != NULL) {
                    curr->prev->next = curr->next;
                } else {
                    head = curr->next;  
                }

                if (curr->next != NULL) {
                    curr->next->prev = curr->prev;
                } else {
                    tail = curr->prev;  
                }

                link* remove = curr;
                curr = curr->next;
                delete remove;
            } else {
                curr = curr->next;  
            }
        }
    }

    // print all words in list
    void print() {
        link* temp = head;

        while (temp != NULL) {
            cout << temp->word << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    buffer buf;

    buf.append("This");
    buf.append("is");
    buf.append("PCCoE");
    buf.append("Ruturaj");
    buf.append("Yash");
    buf.append("Vivek");
    buf.append("Prathamesh");

    buf.print();

    buf.remove("Yash");
 
    buf.print();

    return 0;
}
