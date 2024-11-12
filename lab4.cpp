#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string firstName;
    string lastName;
    int age;
};

void inputEmployeeData(Employee& employee) {
    cout << "Enter first name: ";
    cin >> employee.firstName;
    cout << "Enter last name: ";
    cin >> employee.lastName;
    cout << "Enter age: ";
    cin >> employee.age;
}

void printEmployeesOver28(const Employee employees[], int numberOfEmployees) {
    cout << "Employees older than 28 years:\n";
    for (int i = 0; i < numberOfEmployees; ++i) {
        if (employees[i].age > 28) {
            cout << employees[i].firstName << " " << employees[i].lastName << "\n";
        }
    }
}

int main() {
    const int employeeNumber = 5;
    Employee employees[employeeNumber];

    for (int i = 0; i < employeeNumber; ++i) {
        cout << "Enter data for employee " << i + 1 << ":\n";
        inputEmployeeData(employees[i]);
    }

    printEmployeesOver28(employees, employeeNumber);

    return 0;
}
