#include "internalteacher.hpp"

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

