/*Write a program create employee class with members variable as EmpId,Name of Employee and
Salary. For 10 Employees
Print list of all employees.
Print list of employee who got heights salary.
*/
#include<iostream>
using namespace std;

class Employee {
private:
    int Emp_Id;
    string Emp_Name;
    float Emp_Salary;

public:    
    void get_data() {
        cout << "\nEnter the Employee Id: ";
        cin >> Emp_Id;  
        cout << "\nEnter the Employee Name: ";
        cin >> Emp_Name;     
        cout << "Enter the Employee Salary: ";
        cin >> Emp_Salary;             
    }
    
    void display() {
        cout << "\nEmployee ID: " << Emp_Id;
        cout << "\nEmployee Name: " << Emp_Name;
        cout << "\nEmployee Salary: " << Emp_Salary;
        cout << "\n";
    }

    float getSalary() { 
        return Emp_Salary;
    }
};

int main() {
    Employee e[10];
    float max = 0;
    
   
    for(int i = 0; i < 10; i++) {
        e[i].get_data(); 
        e[i].display();
        
       
        if (e[i].getSalary() > max) {
            max = e[i].getSalary();
        }
    }

    cout << "\nThe list of employees with the highest salary is below:\n";
    
    
    for(int i = 0; i < 10; i++) {
        if (e[i].getSalary() == max) {
            e[i].display();
        }
    }
    
    return 0;
}

















































































































































































































































