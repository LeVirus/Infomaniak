#include "externalteacher.hpp"

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
