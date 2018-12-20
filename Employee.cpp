#include "Employee.h"  // class implemented
#include<string>
using namespace std;

// File scope starts here 

/////////////////////////////// PUBLIC ///////////////////////////////////////

//============================= LIFECYCLE ====================================

// Employee Default + Overloaded constructor
Employee::Employee(const string& aName, const string& aNIC, const Date& aDateOfBirth, const Date& aDateOfHire, const Address& aHomeAddress, double aTaxRate, double aBasicSalary) : mName(aName), mNIC(aNIC), mBirthDate(aDateOfBirth), mHireDate(aDateOfHire), mHomeAddress(aHomeAddress), mTaxRate(aTaxRate), mBasicSalary(aBasicSalary) {
	// initialization using member intializing list 

	Employee::msNoOfEmployees++; // increment no. of employees within constructor 
}
// end Employee constructor 

// Employee Copy constructor
Employee::Employee(const Employee& obj) : mName(obj.GetName()), mNIC(obj.GetNIC()), mBirthDate(obj.GetDOB()), mHireDate(obj.GetDOJ()), mHomeAddress(obj.GetHomeAddress()), mTaxRate(obj.GetTaxRate()), mBasicSalary(obj.GetBasicSalary()) {
	Employee::msNoOfEmployees++; // increment no. of employees within constructor 
}
// end Employee constructor 

// Emplopyee destructor
Employee::~Employee() {
	Employee::msNoOfEmployees--; // decrement no. of employees each time destructor is called 
}
// end ~Employee destructor

//============================= OPERATORS ====================================

// Stream Insertion
ostream & operator <<(ostream& os, const Employee& e) {
	os << "Name: " << e.GetName() << endl;
	os << "NIC: " << e.GetNIC() << endl;
	os << "DOB: " << e.GetDOB() << endl;
	os << "DOJ: " << e.GetDOJ() << endl;
	os << "Address: " << e.GetHomeAddress() << endl;
	os << "Tax Rate: " << e.GetTaxRate() << endl;
	os << "Basic Salary: " << e.GetBasicSalary() << endl;
	return os;
}
// end stream insertion

// Stream Extraction
istream & operator >>(istream & is, Employee & e) {
	string aName, aNIC;
	Address aAddress;
	double aTaxrate, aSalary;
	cout << "Enter name of Employee: ";
	getline(is, aName);
	cout << "Enter NIC of Employee: ";
	getline(is, aNIC);
	is >> aAddress;
	cout << "Enter tax rate: ";
	is >> aTaxrate;
	cout << "Enter basic salary: ";
	is >> aSalary;
	e.SetEmployee(aName, aNIC, aAddress, aTaxrate, aSalary);
	return is;
}
// end Stream Extraction

//============================= OPERATIONS ===================================

// function that prints all the details of the employee.
void Employee::PrintEmployee()const {
	cout << "Name: " << this->GetName() << endl;
	cout << "NIC: " << this->GetNIC() << endl;
	cout << "DOB: " << this->GetDOB() << endl;
	cout << "DOJ: " << this->GetDOJ() << endl;
	cout << "Address: " << this->GetHomeAddress() << endl;
	cout << "Tax Rate: " << this->GetTaxRate() << endl;
	cout << "Basic Salary: " << this->GetBasicSalary() << endl;
}
// end function PrintEmployee

// function that calculates net salary of the employee.
double Employee::CalcSalary() {
	double tax, netSalary;
	tax = this->GetTaxRate() * this->GetBasicSalary();
	netSalary = this->GetBasicSalary() - tax;
	
	return netSalary;
}
// end function CalcSalary

//============================= ACESS      ===================================

// function that sets name of Employee
void Employee::SetName(const string& aName) {
	if (this->IsValidName(aName))
		this->mName = aName;
	else 
		cout << "ERROR: Invalid name entered. Cannot set name." << endl;
}
// end function SetName

// function that sets NIC of Employee
void Employee::SetNIC(const string& aNIC) {
	if (this->IsValidNIC(aNIC))
		this->mNIC = aNIC;
	else
		cout << "ERROR: Invalid NIC entered. Cannot set NIC." << endl;
}
// end function SetNIC

// function that sets Home Address of Employee
void Employee::SetHomeAddress(int aHouseNo, const string& aStreet, const string& aCity, const string& aProvince, int aPostCode) {
	this->mHomeAddress.SetAddress(aHouseNo, aStreet, aCity, aProvince, aPostCode);
}
// end function SetHomeAddress

// overloaded function that sets Home Address of Employee
void Employee::SetHomeAddress(const Address& add) {
	this->mHomeAddress.SetAddress(add);
}
// end function SetHomeAddress

// function that set ZIP Code value of Employee Home Address 
void Employee::SetZIP(int aZIP) {
	this->mHomeAddress.SetPostCode(aZIP);
}
// end function SetZIP

// function that sets Tax Rate of Employee
void Employee::SetTaxRate(double aTaxRate) {
	if (aTaxRate < 0.0)
		cout << "Tax rate cannot be negative.";
	else
		this->mTaxRate = aTaxRate;
}
// end function SetTaxRate

// function that sets Basic Salary of Employee
void Employee::SetBasicSalary(double aBasicSalary) {
	if (aBasicSalary < 0.0)
		cout << "Basic salary cannot be negative.";
	else
		this->mBasicSalary = aBasicSalary;
}
// end function SetBasicSalary

// function that sets the Employee
void Employee::SetEmployee(const string& aName, const string& aNIC, const Address& aAddress, double aTaxRate, double aBasicSalary) {
	this->SetName(aName);
	this->SetNIC(aNIC);
	this->SetHomeAddress(aAddress);
	this->SetTaxRate(aTaxRate);
	this->SetBasicSalary(aBasicSalary);
}
// end function SetEmployee

// overloaded function that sets the Employee
void Employee::SetEmployee(const Employee& obj) {
	this->SetEmployee(obj.GetName(), obj.GetNIC(), obj.GetHomeAddress(), obj.GetTaxRate(), obj.GetBasicSalary());
}
// end function SetEmployee

// function that gets name of the Employee
const string& Employee::GetName()const {
	return this->mName;
}
// end function GetName

// function that gets NIC of the Employee
const string& Employee::GetNIC()const {
	return this->mNIC;
}
// end function GetNIC

// function that gets DOB of the Employee
const Date& Employee::GetDOB()const {
	return this->mBirthDate;
}
// end function GetDOB

// function that gets DOJ of the Employee
const Date& Employee::GetDOJ()const {
	return this->mHireDate;
}
// end function GetDOJ

// function that gets Home Address of the Employee
const Address& Employee::GetHomeAddress()const {
	return this->mHomeAddress;
}
// end function GetHomeAddress

// function that gets ZIP code of Employee's Home Address
int Employee::GetZIP()const {
	return this->mHomeAddress.GetPostCode();
}
// end function GetZIP

// function that gets Tax Rate of the Employee
double Employee::GetTaxRate()const {
	return this->mTaxRate;
}
// end function GetTaxRate

// function that gets Basic Salary of the Employee
double Employee::GetBasicSalary()const {
	return this->mBasicSalary;
}
// end function GetBasicSalary

// function that gets the Employee
const Employee& Employee::GetEmployee()const {
	return *this;
}
// end function GetEmployee

// static function that gets the total no. of Employees
int Employee::sGetTotalEmployee() {
	return Employee::msNoOfEmployees;
}
// end function sGetTotalEmployee

/////////////////////////////// PRIVATE    ///////////////////////////////////

//============================= INQUIRY    ===================================

/** utility function to check name of employee.
* Only checks for alphabetic characters and first cap letter.
*
* @param testName The reference to the name to be tested.
*
* @return true if testName is valid, false otherwise.
*/
bool Employee::IsValidName(const string& testName)const {
	// first letter must be capital
	if (!isupper(testName[0]))
		return false;

	for (int i = 0; i < testName.length(); i++) {
		if (!isalpha(testName[i]) && testName[i] != ' ' && testName[i] != '.')
			return false;
		if (testName[i] == ' ' && islower(testName[i + 1]))
			return false;
		if (testName[i] == '.' && islower(testName[i + 1]))
			return false;
	}
	return true;
}
// end function IsValidName

/** utility function to check validity of NIC
* Only checks for alphanumeric characters and 
* length of NIC (<16 characters). Allows '-' char.
*
* @param testNIC The reference to the NIC to be tested.
*
* @return true if testNIC is valid, false otherwise.
*/
bool Employee::IsValidNIC(const string& testNIC)const {
	if (testNIC.length() > 15)
		return false;
	for (int i = 0; i < testNIC.length(); i++) {
		if (islower(testNIC[i]))
			return false;
		if (!isalnum(testNIC[i]) && testNIC[i] != '-')
			return false;
	}
	return true;
}
// end function IsValidNIC

/*private static member cannot be accessed outside the class except for initialization*/
int Employee::msNoOfEmployees = 0;	// intitalize class variable 
