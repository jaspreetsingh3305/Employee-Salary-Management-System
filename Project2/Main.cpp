#include "HourlyEmployee.cpp"
#include "SalariedEmployee.cpp"
#include "CommisionEmployee.cpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main() {

	cout << "\n\t\t\tHello,Welcome to our Payroll Department."<<endl;
	cout << "\n\t\t\t--------------------------------------" << endl;
	cout<<"\n\t\t\tPlease choose which employee you want to create:\n"<< endl;
		
		string name,choice;
		int add;
		string socialSecurityNumber;
		double wage, hours, weeklySalary,grossSales,commisionRate;

		vector<Employee*> employeeIncome;
		vector<Employee> employees;
		bool createEmployee = true;

		
		while (createEmployee == true) {
			
			cout << "\t\t\tEnter 1 to create an Hourly employee, 2 to create Salaried employee,\n" << endl;
			cout << "\t\t\tor 3 to create a commision employee.\n"<<endl;
			cin >> choice;
			
			if (choice =="1") {

				cout << "\t\t\tPlease enter employee name: " << endl;
				cin >> name;
				cout << "\n\t\t\tPlease enter Social Security Number: " << endl;
				cin >> socialSecurityNumber;
				cout << "\t\t\tEnter wage/hour: " << endl;
			
				try {
					cin >> wage;
					cout << "\t\t\tEnter hours/week: " << endl;
					cin >> hours;
					HourlyEmployee he = HourlyEmployee(name, socialSecurityNumber, wage, hours);
					employeeIncome.push_back(&he);
					employees.push_back(he);
				}
				catch(exception e){
					cerr << e.what() << endl;
				}

				cout << "\t\t\tWould you like to add another employee. Enter '1' for yes and '0' for no.\n" << endl;
				cin >> add;
				if (add == 0) {
					createEmployee = false;
				}

			}

			else if (choice == "2") {
				cout << "\t\t\tPlease enter employee name: " << endl;
				cin >> name;
				cout << "\n\t\t\tPlease enter Social Security Number: " << endl;
				cin >> socialSecurityNumber;
				cout << "\t\t\tEnter weekly salary: " << endl;

				try {
				cin >> weeklySalary;
				SalariedEmployee se = SalariedEmployee(name, socialSecurityNumber, weeklySalary);
				employeeIncome.push_back(&se);
				employees.push_back(se);

			}
			catch (exception e) {
				cerr << e.what() << endl;
			}
				cout << "\t\t\tWould you like to add another employee. Enter '1' for yes and '0' for no.\n" << endl;
				cin >> add;
				if (add==0) {
					createEmployee = false;
				}
			}


			else if(choice=="3") {
				
					cout << "\t\t\tPlease enter employee name: " << endl;
					cin >> name;
					cout << "\n\t\t\tPlease enter Social Security Number: " << endl;
					cin >> socialSecurityNumber;
					cout << "\t\t\tEnter Gross Sales: " << endl;

					try {
						cin >> grossSales;
						cout << "\t\t\tEnter commision rate between 0 and 1: " << endl;
						cin >> commisionRate;
						 CommissionEmployee ce = CommissionEmployee(name, socialSecurityNumber, grossSales,commisionRate);
						 employeeIncome.push_back(&ce);
						 employees.push_back(ce);


					}
					catch (exception e) {
						cerr << e.what() << endl;
					}
					cout << "\t\t\tWould you like to add another employee. Enter '1' for yes and '0' for no.\n" << endl;
					cin >> add;
					if (add == 0) {
						createEmployee = false;
				}
			}
			else {
				cerr << "Please enter a valid option" << endl;
			}
			
		};



		
		
		cout << "\n\t\t\t-----------Employees Information----------\n" << endl;

		for (int i = 0;i<employees.size();i++) {
		
				cout << employees[i].names();
				cout << employeeIncome[i]->toString() <<endl;
				
			}
		
			
		
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
}
