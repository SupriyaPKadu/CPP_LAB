/*Write a C++ program to accpet worker information Worker_Name, No_Of_Hours_Worked,
Pay_Rate and Salary. Write necessary functions to calculate and display the salary of Worker. (Use
Default values for Pay_Rate Rs. 500 per hours)*/

#include<iostream>
using namespace std;
double calculate_salary(  int Hours,  int Rate)
{ 
 double salary;
 salary=Hours*Rate;
 return salary;
	
	
	
}
void display_salary( double sal)
{ 
 
 
 cout<<"Salary of Worker is : RS."<<sal;
 
	
	
	
}
int main()
{
	string Worker_Name;
     int No_Of_Hours_Worked;
     int  Pay_Rate=500;
    double salary;
 
     cout<<"\n Enter Worker_Name";
     cin>>Worker_Name;
     
     cout<<"\n Enter Working hours of Worker";
     cin>>No_Of_Hours_Worked;
     
 
	salary= calculate_salary( No_Of_Hours_Worked, Pay_Rate);
	display_salary(salary);
	return 0;
}

























































































































































