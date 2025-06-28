#include <iostream>
using namespace std;
 
struct Employee {
   int id;
   string name;
   Employee* next;
   Employee(int id, string name) : id(id), name(name), next(NULL) {}
};
 
class HashTable {
   int size;
   Employee** table;
 
   int hashFunction(int id) {
       return id % size;
   }
 
public:
   HashTable(int size) : size(size) {
       table = new Employee*[size];
       for (int i = 0; i < size; ++i) table[i] = NULL;
   }
 
   void insert(int id, string name) {
       int index = hashFunction(id);
       Employee* newEmployee = new Employee(id, name);
       newEmployee->next = table[index];
       table[index] = newEmployee;
   }
 
   string search(int id) {
       int index = hashFunction(id);
       Employee* current = table[index];
       while (current) {
           if (current->id == id) return current->name;
           current = current->next;
       }
       return "Employee not found";
   }
 
   void remove(int id) {
       int index = hashFunction(id);
       Employee* current = table[index];
       Employee* prev = NULL;
       while (current && current->id != id) {
           prev = current;
           current = current->next;
       }
       if (!current) return;
       if (!prev) table[index] = current->next;
       else prev->next = current->next;
       delete current;
   }
 
   ~HashTable() {
       for (int i = 0; i < size; ++i) {
           Employee* current = table[i];
           while (current) {
               Employee* temp = current;
               current = current->next;
               delete temp;
           }
       }
       delete[] table;
   }
};
 
int main() {
   HashTable employees(10);
   employees.insert(278, "Varun");
   employees.insert(280, "Vivek");
   employees.insert(289, "Yash");
   employees.insert(287, "Ruturaj");
   cout << employees.search(280) << endl;
   employees.remove(280);
   cout << employees.search(280) << endl;
   return 0;
}