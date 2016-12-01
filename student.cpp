#include "student.hpp"
#include <iostream>

Student::Student( unsigned int id, const std::__cxx11::string &firstName,
				 const std::__cxx11::string &lastName ):
	mUiId( id ), mStrFirstName( firstName ), mStrLastName( lastName )
{

}

bool Student::operator==( const Student& s )const
{
	return !( ( *this ) != s);
}

bool Student::operator!=( const Student& s )const
{
	unsigned int lId = s.getId();

	const std::string &lFirst = s.getFirstName(), &lLast = s.getLastName();

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

const std::string &Student::getFirstName()const
{
	return mStrFirstName;
}

const std::string &Student::getLastName()const
{
	return mStrLastName;
}

void Student::displayStudent()const
{
	std::cout << "mUiId : " << getId() << " mStrFirstName : " << getFirstName() <<
		" mStrLastName : " << getLastName() << "\n";
}

unsigned int Student::getId()const
{
	return mUiId;
}
