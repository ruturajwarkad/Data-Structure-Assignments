#include <iostream>
using namespace std;


class Student {

public:

    int rollNo;
    string name;
    float SGPA;

    void getData() {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter SGPA: ";
        cin >> SGPA;
    }

    void showData() const {
        cout << "Roll No: " << rollNo << ", Name: " << name << ", SGPA: " << SGPA << endl;
    }
};


void insertionSort(Student arr[], int n) {

    for (int i = 1; i < n; i++) { 
        Student temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].rollNo > temp.rollNo) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}


void printArray(Student arr[], int n) {

    for (int i = 0; i < n; i++) {
        arr[i].showData(); 
    }
}


int main() {
    const int SIZE = 5;
    Student students[SIZE] = {
       {87, "Ruturaj", 9.6},
       {89, "Yash", 9.4},
       {80, "Vivek", 9.0},
       {74, "Parth", 8.0},
       {78, "Varun", 8.7}
    };

   
    insertionSort(students, SIZE);

    
    cout << "\nSorted student data by Roll No:" << endl;
    printArray(students, SIZE);

    return 0;
}



