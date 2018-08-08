#include "Employee.cpp"

using namespace std;
class HourlyEmployee: public Employee{
private:

	double wage;   //wage per hour
	double hours;

	//constants
	 const int MIN_HOURS = 0, MAX_HOURS = 168, OVERTIME_HOURS = 40;
	 const double OVERTIME_PAY_FACTOR = 1.5;

public:

	HourlyEmployee(string name, string socialSecurityNumber,
		double wage, double hours)
		:Employee(name, socialSecurityNumber){
		validateWage(wage);
		validateHours(hours);
	}

 void validateWage(double wage) {
	if (wage >0)
		this->wage = wage;
	else
		throw new exception("Wage per hour MUST be > 0");
}

 void validateHours(double hours) {
	 if (hours >= MIN_HOURS && hours <= MAX_HOURS)
		 this->hours = hours;
	 else
		 throw new exception("Hours worked MUST be between 0 and 168");
 }
 
 double getWage() {
	 return wage;
 }

  void setWage(double wage) {
	 validateWage(wage);

 }

  double getHours() {
	 return hours;
 }

  void setHours(double hours) {
	 validateHours(hours);

 }

  
	const double getEarnings() override
  {
	  if ((getHours() <= OVERTIME_HOURS))
		  return getWage() * getHours();
	  else
		  return OVERTIME_HOURS * getWage() + (getHours() - OVERTIME_HOURS) * getWage() * OVERTIME_PAY_FACTOR;
  }

	string const toString() override {
		/*return "Name: " + getName() + "\nSocial Security Number: " + getSocialSecurityNumber() 
			+"\nWage: $"+to_string(getWage())+"\nHours: "+ to_string(getHours());*/
		return Employee::toString() + "\nWage: $" + to_string(getWage()) + "\nHours: " + to_string(getHours());
	}
};