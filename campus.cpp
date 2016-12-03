#include "campus.hpp"
#include "externalteacher.hpp"
#include "internalteacher.hpp"
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
	std::cout << "Begin Campus=================================\n";
	std::cout << "mStrTown :" << mStrTown << "\n" << "mStrRegion :" << mStrRegion << "\n" <<
				 "mUiCapacity :" << mUiCapacity << "\n" << "mUiEffective :" <<
				 mUiEffective << "\n";
	std::cout << "Begin display students=====\n";
	for( Student s : mMultiSetStudents )
	{
		s.displayStudent();
	}
	std::cout << "End display students=====\n";

	std::cout << "Begin display teachers=====\n";
	for( const std::unique_ptr< Teacher > &t : mVectTeachers )
	{
		t -> displayTeacher();
	}
	std::cout << "End display teachers=====\n";
	std::cout << "End Campus=================================\n";

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

bool Campus::addStudent( const Student &s )
{
	for( const Student vectStud : mMultiSetStudents )
	{
		if( s == vectStud )
		{
			return false;
		}
	}
	if( mMultiSetStudents.size() >= mUiCapacity )
	{
		throw FullCampusException( "Campus is full\n" );
	}
	mMultiSetStudents.insert( s );
	mUiEffective++;
	return true;
}

bool Campus::removeStudent(const Student &s)
{

	for( const Student vectStud : mMultiSetStudents )
	{
		std::cerr << vectStud.getId() << "   " << s.getId() <<"\n";

		if( vectStud == s )
		{
			mMultiSetStudents.erase( s );
			mUiEffective--;
			return true;
		}
	}
	return false;
}

const std::multiset< Student, Compare > &Campus::getStudents() const
{
	return mMultiSetStudents;
}

unsigned int Campus::getStudentsEffective() const
{
	return mUiEffective;
}

unsigned int Campus::addTeacher(std::unique_ptr<Teacher> &t )
{
	mVectTeachers.push_back( std::move( t ) ) ;
	return mVectTeachers.size();
}

bool Campus::removeTeacher(std::unique_ptr<Teacher> &t )
{
	for( auto it =  mVectTeachers.begin() ; it != mVectTeachers.end() ; ++it )
	{
		if( *it.base() -> get() == *t.get() )
		{
			mVectTeachers.erase( it );
			return true;
		}
	}
	return false;
}

const std::vector<std::unique_ptr< Teacher > > &Campus::getTeachers() const
{
	return mVectTeachers;
}

void Campus::rmAllStudents()
{
	mMultiSetStudents.clear();
	mUiEffective = 0;
}
