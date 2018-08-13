#pragma once
#include <string>

using namespace std;
class  Employee {

private:
	string name;
	string socialSecurityNumber;

public:

	Employee(string name, string socialSecurityNumber):
		name(name), socialSecurityNumber(socialSecurityNumber) {}
	

	string getName() {
		return name;
	}
	
	string getSocialSecurityNumber() {
		return socialSecurityNumber;
	}

	virtual const double getEarnings() { return 0; }

	virtual string const toString() {
		return 0;
		
	}

	string names() {
		return "Name: " + getName() + "\nSocial Security Number: " + getSocialSecurityNumber();
	}
};
