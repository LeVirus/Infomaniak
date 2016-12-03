#include "internalteacher.hpp"
#include <iostream>

unsigned int InternalTeacher::mUiSalaryInternal = 0;

InternalTeacher::InternalTeacher()
{
	mStrStatus = "internal";
}

InternalTeacher::InternalTeacher( unsigned int id, const std::__cxx11::string &firstName,
								  const std::__cxx11::string &lastName )
{
	mStrStatus = "internal";
	mUiId = id;
	mStrFirstName = firstName;
	mStrLastName = lastName;
}

unsigned int InternalTeacher::getSalary() const
{
	return mUiSalaryInternal;
}

void InternalTeacher::displayTeacher() const
{
	Teacher::displayTeacher();
	std::cout << "mUiSalaryInternal : " << mUiSalaryInternal << "\n";
}

void InternalTeacher::editSalary( unsigned int salary )
{
	defineGlobalSalaryInternal( salary );
}




void InternalTeacher::defineGlobalSalaryInternal(unsigned int salaryInternal)
{
	mUiSalaryInternal = salaryInternal;
}
