#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
    int empID;
    string empName;
    float empSalary;

    void showData() const {
        cout << "EMP-ID: " << empID << ", EMP-Name: " << empName << ", EMP-Salary: " << empSalary << endl;
    }
};

void merge(Employee arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Employee* L = new Employee[n1];
    Employee* R = new Employee[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i].empName <= R[j].empName) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(Employee arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
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

    mergeSort(employees, 0, SIZE - 1);

    cout << "\nSorted employee data by Name:" << endl;
    printArray(employees, SIZE);

    return 0;
}



