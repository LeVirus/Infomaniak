#include "campus.hpp"
#include <iostream>
#include <algorithm>

Campus::Campus( const std::string &town, const std::string &region, unsigned int capacity ):
	mStrTown( town ), mStrRegion( region ), mUiCapacity( capacity ),
	mMultiSetStudents( [] ( const Student& lhs, const Student& rhs )
	{ return lhs.getId() < rhs.getId(); } )
  //call constructor of multiset with Compare as Argument
{
}

void Campus::editCapacity( unsigned int capacity )
{
	mUiCapacity = capacity;
}

void Campus::editVille( std::__cxx11::string town )
{
	mStrTown = town;
}

void Campus::editRegion( std::__cxx11::string region )
{
	mStrRegion = region;
}

void Campus::displayCampus() const
{
	std::cout << "Begin display students\n";
	for( Student s : mMultiSetStudents )
	{
		s.displayStudent();
	}
	std::cout << "End display students\n";

	std::cout << "Begin display teachers\n";
	for( Teacher &t : mVectTeachers )
	{
		t.displayTeacher();
	}
	std::cerr << "End display teachers\n";
}

bool Campus::operator==( const Campus& c )
{
	return !( ( *this ) != c);
}

bool Campus::operator!=( const Campus& c )
{
	const std::string &lTown = c.getTown(), &rTown = getTown(),
			&lRegion = c.getRegion(), &rRegion = getRegion();
	return ( lTown != rTown ) || ( lRegion != rRegion );
}

const std::string &Campus::getTown()const
{
	return mStrTown;
}

const std::string &Campus::getRegion()const
{
	return mStrRegion;
}

unsigned int Campus::getCapacity() const
{
	return mUiCapacity;
}

unsigned int Campus::getEffective() const
{
	return mUiEffective;
}

unsigned int Campus::addStudent( const Student &s )
{
	if( mMultiSetStudents.size() >= mUiCapacity )
	{
		throw FullCampusException( "Campus is full\n" );
	}
	mMultiSetStudents.insert( s );
	mUiEffective++;
	return mUiEffective;
}

unsigned int Campus::removeStudent(const Student &s)
{
	if( mMultiSetStudents.erase( s ) )
	{
		mUiEffective--;
	}
	return mUiEffective;
}

const std::multiset< Student, Compare > &Campus::getStudents() const
{
	return mMultiSetStudents;
}

unsigned int Campus::getStudentsEffective() const
{
	return mUiEffective;
}

unsigned int Campus::addTeacher( Teacher &t )
{
	mVectTeachers.push_back( t );
	return mVectTeachers.size();
}

unsigned int Campus::removeTeacher( Teacher &t )
{
	for( auto it =  mVectTeachers.begin() ; it != mVectTeachers.end() ; ++it )
	{
		if( it.base() -> get() == t )
		{
			mVectTeachers.erase( it );
		}
	}
	return mVectTeachers.size();
}

const std::vector<std::reference_wrapper< Teacher > > &Campus::getTeachers() const
{
	return mVectTeachers;
}

void Campus::rmAllStudents()
{
	mMultiSetStudents.clear();
	mUiEffective = 0;
}
