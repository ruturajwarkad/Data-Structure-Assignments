#include <iostream>
#include <string>

using namespace std;


class Employee {

public:
    int ID;
    string Name;
    float Salary;

    void showData() const {
        cout << "ID : " << ID << ", Name : " << Name << ", Salary : " << Salary << endl;
    }
};


void swap(Employee &a, Employee &b) {
    Employee temp = a;
    a = b;
    b = temp;
}


int partition(Employee arr[], int low, int high) {

    int pivot = arr[high].ID; 
    int i = low - 1; 

    for (int j = low; j < high; j++) {
        if (arr[j].ID < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}


void quickSort(Employee arr[], int low, int high) {

    if (low < high) {
        int pi = partition(arr, low, high);

        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void printArray(Employee arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i].showData();
    }
}


int main() {
    const int SIZE = 8;
    Employee employees[SIZE] = {
        {289, "Ruturaj", 72000},
        {274, "Yash", 57000},
        {280, "Vivek", 45000},
        {279, "Vedant", 62000},
        {287, "Varun", 52000},
        {284, "Prathamesh", 47000},
        {285, "Ajay", 42000},
        {269, "Ujjwal", 85600}
    };

    
    quickSort(employees, 0, SIZE - 1);

    
    cout << "\nSorted employee by ID:" << endl;
    printArray(employees, SIZE);

    return 0;
}



