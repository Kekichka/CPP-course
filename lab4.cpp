#include <iostream>
#include <vector>
using namespace std;

struct Employee {
    string lastName;
    string firstName;
    int age;
};

int main() {
    int n;
    cout << "Employee count: ";
    cin >> n; 

    vector<Employee> employees(n);

    for (int i = 0; i < n; i++) {
        cout << "First name last name and age " << i + 1 << ": ";
        cin >> employees[i].lastName >> employees[i].firstName >> employees[i].age;
    }

    cout << "empolyee age isnt > 28 :\n";
    for (const auto& emp : employees) {
        if (emp.age > 28) {
            cout << emp.firstName << endl; 
        }
    }

    return 0;
}
