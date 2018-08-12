#include "Employee.cpp"

using namespace std;
class CommissionEmployee :public Employee {

private:
	double grossSales;
	double commissionRate;

public:
	CommissionEmployee(string name, string socialSecurityNumber,
		double grossSales, double commissionRate) :Employee(name, socialSecurityNumber)
	{
		setGrossSales(grossSales);
		setCommissionRate(commissionRate);
	}

	double getGrossSales() {
		return grossSales;
	}
	
	void validateGrossSales(double grossSales) {
		if (grossSales < 0)
			throw exception("\nGross should be greater than zero\n");
		this->grossSales = grossSales;
	}

	void setGrossSales(double grossSales) {
		validateGrossSales(grossSales);
	}

	double getCommissionRate() {
		return commissionRate * 100;
	}


	void setCommissionRate(double commissionRate) {
		ValidateCommissionRate(commissionRate);

	}
	void ValidateCommissionRate(double commissionRate) {
		if (commissionRate <= 0 || commissionRate > 1)

			throw exception("Commissin rate should be betwen 0 and 1");

		this->commissionRate = commissionRate;
	}


	const double getEarnings() override {
		return getGrossSales() * getCommissionRate();//Some portion of total sales =employee's income
	}

	const string toString() override {
		return Employee::toString() + "\nGross Sales: "+to_string(getGrossSales())+
						"\nCommissin Rate: "+ to_string(getCommissionRate())+
				"\nTotal Earnings: $"+to_string(getEarnings());
	}

};