#include "Employee.cpp"

using namespace std;
class HourlyEmployee: public Employee{
private:

	double wage;   //wage per hour
	double hours;

	//constants
	 const int MIN_HOURS = 1, MAX_HOURS = 180, OVERTIME_HOURS = 44; //Hours per Month
	 const double OVERTIME_PAY_FACTOR = 1.5;

public:

	HourlyEmployee(string name, string socialSecurityNumber,
		double wage, double hours)
		:Employee(name, socialSecurityNumber){
		setWage(wage);
		setHours(hours);
	}

 void validateWage(double wage) {
	 if (wage > 14) {
		 this->wage = wage;
	 }
	 else {
		 throw exception("\nWage per hour MUST be > $14\n");
	 }
}

 void validateHours(double hours) {
	 if (hours >= MIN_HOURS && hours <= MAX_HOURS) {
		 this->hours = hours;
	 }
	 else {
		 throw exception("\nHours worked MUST be between 1 and 180\n");
	 }
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
		  return (OVERTIME_HOURS * getWage()) + ((getHours() - OVERTIME_HOURS) * (getWage() * OVERTIME_PAY_FACTOR));
  }

	string const toString() override {
		return "\nWage: $" + to_string(getWage()) + "\nHours: " +
					to_string(getHours()) + "\nMonthly Income: $"+to_string(getEarnings()) + "\n";
	}
};