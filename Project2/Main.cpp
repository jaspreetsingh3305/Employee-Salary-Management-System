#include "HourlyEmployee.cpp"
#include "SalariedEmployee.cpp"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main() {

		cout <<"\nHello, Please choose which employee you want to create\n"<< endl;
		
		int choice,n=0;
		string name;
		string socialSecurityNumber;
		double wage, hours, weeklySalary;

		vector<Employee*> employees;

		while (n < 1) {
			cout << "Enter 1 to create an Hourlynemployee\n" << endl;
			cout << "Enter  2 to create a Salaried employee\n" << endl;
			cin >> choice;
			switch (choice)
			{

			case 1: {
				cout << "Please enter employee name: " << endl;
				cin >> name;
				cout << "\nPlease enter Social Security Number: " << endl;
				cin >> socialSecurityNumber;
				cout << "Enter wage/hour: " << endl;
				cin >> wage;
				cout << "Enter hours/week: " << endl;
				cin >> hours;
				HourlyEmployee he = HourlyEmployee(name, socialSecurityNumber, wage, hours);
				employees.push_back(&he);
				n++;
				break;
			}

			case 2: {
				cout << "Please enter employee name: " << endl;
				cin >> name;
				cout << "\nPlease enter Social Security Number: " << endl;
				cin >> socialSecurityNumber;
				cout << "Enter weekly salary: " << endl;
				cin >> weeklySalary;
				SalariedEmployee se = SalariedEmployee(name, socialSecurityNumber, weeklySalary);
				n++;
				break;
			}
			}

		}
		cout << "Here" << endl;
		for (Employee* e: employees)
			{
				cout << e->toString() << endl;
			}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
}
