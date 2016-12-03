#include "externalteacher.hpp"
#include <iostream>

ExternalTeacher::ExternalTeacher()
{
	mStrStatus = "external";
}

ExternalTeacher::ExternalTeacher( unsigned int id, const std::__cxx11::string &firstName,
								  const std::__cxx11::string &lastName )
{
	mStrStatus = "external";
	mUiId = id;
	mStrFirstName = firstName;
	mStrLastName = lastName;
}

unsigned int ExternalTeacher::getSalary() const
{
	return mUiSalaryExternal;
}

void ExternalTeacher::displayTeacher() const
{
	Teacher::displayTeacher();
	std::cout << "mUiSalaryExternal : " << mUiSalaryExternal << "\n";
}

void ExternalTeacher::editSalaryExternal( unsigned int salary )
{
	mUiSalaryExternal = salary;
}

void ExternalTeacher::editSalary(unsigned int salary)
{
	editSalaryExternal( salary );
}
