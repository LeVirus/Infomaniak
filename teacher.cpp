#include "teacher.hpp"
#include <iostream>


bool Teacher::operator==(const Teacher &t)const
{
	return !( ( *this ) != t);
}

bool Teacher::operator!=(const Teacher &t)const
{
	unsigned int lId = t.getId();

	const std::string &lFirst = t.getFirstName(), &lLast = t.getLastName();

	//if nobody got an ID
	if( lId == NO_ID && mUiId == NO_ID )
	{
		//check first and last names
		return ( lFirst != mStrFirstName ) || ( lLast != mStrLastName );
	}
	//else check ID : case if at least one has an ID, or if both have an ID
	else
	{
		return lId != mUiId;
	}
}

unsigned int Teacher::getId() const
{
	return mUiId;
}

const std::__cxx11::string &Teacher::getFirstName() const
{
	return mStrFirstName;
}

const std::__cxx11::string &Teacher::getLastName() const
{
	return mStrLastName;
}

const std::__cxx11::string &Teacher::getStatus() const
{
	return mStrStatus;
}

void Teacher::displayTeacher() const
{
	std::cout << "mUiId : " << mUiId << " \nmStrFirstName : " << mStrFirstName <<
		" \nmStrLastName : " << mStrLastName << "\n";
}
