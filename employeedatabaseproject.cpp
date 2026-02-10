// EMPLOYEE DATABASE MANAGEMENT SYSTEM (C++)
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Employee
{
private :
int empId;
string name;
string department;
double salary;
public :
Employee()     // default constructor
{}
Employee ( int id , string n , string dept , double sal )
{
empId = id;
name = n;
department = dept;
salary = sal;
}
void input()       // taking input from the user
{
cout << "enter employee id \n";
cin >> empId ;
cin.ignore();
cout << "enter name \n";
getline( cin , name );
cout << "enter department \n";
getline( cin , department );
cout << "enter salary \n";
cin >> salary;
}
void display()        // displaying employee details
{
cout << empId << "\t " << name << "\t" << department << "\t" << salary << endl;
}
int getId() const
{
    return empId;
}
void writeToFile( ofstream &out )          // writing employee data to a file
{
out << empId << endl;
out << name << endl;
out << department << endl;
out << salary << endl;
}
void readFromFile( ifstream &in)          // reading employee data from the file
{
in >> empId;
in.ignore();
getline( in , name );
getline( in , department );
in >> salary;
in.ignore();
}
};

void addEmployee();           // function declarations
void viewEmployees();
void searchEmployee();
void updateEmployee();
void deleteEmployee();
int main()
{
int ch;
do
{
cout << "MAIN MENU \n";
cout <<" 1. Add Employee \n";
cout <<" 2. View Employees \n";
cout <<" 3. Search Employee \n";
cout <<" 4. Update Employee \n";
cout <<" 5. Delete Employee \n";
cout <<" 6. Exit \n";
cout << " enter your choice \n";
cin >> ch;
switch(ch)
{
case 1 : addEmployee();
break;
case 2 : viewEmployees();
break;
case 3 : searchEmployee();
break;
case 4 : updateEmployee();
break;
case 5 : deleteEmployee();
break;
case 6 : cout << "exiting \n";
break;
default : "invalid choice , please try again ! \n";
}
}while(ch != 6 );
return 0;
}
void addEmployee()
{
ofstream out( " employee.txt " , ios::app ) ;     // opening file in append mode
Employee e;
e.input();
e.writeToFile(out);
out.close();
cout << " employee added successfully \n";
}

void viewEmployees()
{
ifstream in("employee.txt");
if(!in)
{
cout << "no records found \n";
return ;
}
Employee e;
while( in.peek() != EOF )
{
e.readFromFile(in);
e.display();
}
in.close();
}

void searchEmployee()
{
ifstream in(" employee.txt ");
int searchId;
bool found = false;
cout << "enter employee id to search \n";
cin >> searchId;
Employee e;
while (in.peek() != EOF )
{
e.readFromFile(in);
if( e.getId() == searchId )
{
cout << "employee found \n";
e.display();
found = true;
break;
}
}
if( !found )
cout << "employee not found \n";
in.close();
}

void updateEmployee()
{
ifstream in("employee,txt");
ofstream out("temp.txt");
int updateId;
bool found = false;
Employee e;
while( in.peek() != EOF )
{
e.readFromFile(in);
if( e.getId() == updateId )
{
cout << "employee found \n";
e.input();
found = true;
}
e.writeToFile(out);
}
in.close();
out.close();
remove("employee.txt");
rename("temp.txt" , "employee.txt");
if(!found)
cout << "employee not found \n";
}


void deleteEmployee()
{
ifstream in("employee.txt");
ofstream out("temp.txt");
int deleteId;
bool found = false;
Employee e;
cout << "enter employee id to delete \n";
cin >> deleteId;
while( in.peek() != EOF )
{
e.readFromFile(in);
if( e.getId() != deleteId )
{
e.writeToFile(out);
}
else
{
found = true;
}
}
in.close();
out.close();
remove("employee.txt");
rename("temp.txt" , "employee.txt");
if( !found )
cout << "employee not found \n";
}