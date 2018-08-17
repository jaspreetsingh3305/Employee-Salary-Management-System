#include "HourlyEmployee.cpp"
#include "SalariedEmployee.cpp"
#include "CommisionEmployee.cpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

	cout << "\nHello,Welcome to our Payroll Management System."<<endl;
	cout << "\n--------------------------------------" << endl;
	cout<<"\nPlease choose which employee you want to create:\n"<< endl;
		
		string name,choice;
		int add;
		string socialSecurityNumber;
		double wage, hours, weeklySalary,grossSales,commisionRate;

		vector<Employee*> employeeIncome;
		vector<Employee> employees;
		bool createEmployee = true;
				
		while (createEmployee == true) {
			
			cout << "Enter 1 to create an Hourly employee, 2 to create Salaried employee,\n" << endl;
			cout << "or 3 to create a commision employee.\n"<<endl;
			cin >> choice;
			
			if (choice =="1") {

				cout << "Please enter employee name: " << endl;
				cin >> name;
				cout << "\nPlease enter Social Security Number: " << endl;
				cin >> socialSecurityNumber;
				cout << "Enter wage/hour: " << endl;
			
				try {
					cin >> wage;
					cout << "Enter hours/week: " << endl;
					cin >> hours;
					HourlyEmployee he = HourlyEmployee(name, socialSecurityNumber, wage, hours);
					employeeIncome.push_back(&he);
					employees.push_back(he);
				}
				catch(exception e){
					cerr << e.what() << endl;
				}

				cout << "Would you like to add another employee. Enter '1' for yes and '0' for no.\n" << endl;
				cin >> add;
				if (add == 0) {
					createEmployee = false;
				}

			}

			else if (choice == "2") {
				cout << "Please enter employee name: " << endl;
				cin >> name;
				cout << "\nPlease enter Social Security Number: " << endl;
				cin >> socialSecurityNumber;
				cout << "Enter weekly salary: " << endl;

				try {
				cin >> weeklySalary;
				SalariedEmployee se = SalariedEmployee(name, socialSecurityNumber, weeklySalary);
				employeeIncome.push_back(&se);
				employees.push_back(se);

			}
			catch (exception e) {
				cerr << e.what() << endl;
			}
				cout << "Would you like to add another employee. Enter '1' for yes and '0' for no.\n" << endl;
				cin >> add;
				if (add==0) {
					createEmployee = false;
				}
			}


			else if(choice=="3") {
				
					cout << "Please enter employee name: " << endl;
					cin >> name;
					cout << "\nPlease enter Social Security Number: " << endl;
					cin >> socialSecurityNumber;
					cout << "Enter Gross Sales: " << endl;

					try {
						cin >> grossSales;
						cout << "Enter commision rate between 0 and 1: " << endl;
						cin >> commisionRate;
						 CommissionEmployee ce = CommissionEmployee(name, socialSecurityNumber, grossSales,commisionRate);
						 employeeIncome.push_back(&ce);
						 employees.push_back(ce);

					}
					catch (exception e) {
						cerr << e.what() << endl;
					}
					cout << "Would you like to add another employee. Enter '1' for yes and '0' for no.\n" << endl;
					cin >> add;
					if (add == 0) {
						createEmployee = false;
				}
			}
			else {
				cerr << "****Please enter a valid option*****\n" << endl;
			}
			
		};

		cout << "\n-----------Employees Information----------\n" << endl;

		if (employees.size() == 0)
			cout << "\nSorry, no employees created to show.\n" << endl;

		for (int i = 0;i<employees.size();i++) {
			
				cout << "Employee " << i+1<<":\n"<< endl;
				cout << employees[i].basicInfo();
				cout << employeeIncome[i]->toString() <<endl;
				
			}
		cout << "Please press enter to exit" << endl;
		
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
}
