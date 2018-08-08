#include "Employee.cpp"

using namespace std;
class SalariedEmployee: public Employee
{
private:
	double weeklySalary; 


public:
	SalariedEmployee(string &name, string &socialSecurityNumber,double &weeklySalary)
		:Employee(name,socialSecurityNumber){

		validateWeeklySalary(weeklySalary);
	}

	void validateWeeklySalary(double &weeklySalary) {
		if (weeklySalary > 0)
			this->weeklySalary = weeklySalary;
		else
			throw new exception("Weekly Salary MUST be > 0");

	}
	
	void setWeeklySalary(double weeklySalary) {

		validateWeeklySalary(weeklySalary);

	}

	
	const double getEarnings() override
	{
		return weeklySalary*4;
	}

	
		const string toString() override
	{
		return Employee::toString()+"\nMonthly Salary: $"+to_string(getEarnings());
	}

};