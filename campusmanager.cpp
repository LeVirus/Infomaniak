#include "campusmanager.hpp"
#include "externalteacher.hpp"
#include "internalteacher.hpp"
#include <tinyxml.h>


unsigned int CampusManager::addCampus( std::unique_ptr < Campus > &campus )
{
	if( campus.get() != nullptr && !alreadyExists ( campus ) )
	{
		mVectCampus.push_back( std::move(campus) );
	}
	return mVectCampus.size();
}

unsigned int CampusManager::getNumberCampus() const
{
	return mVectCampus.size();
}

bool CampusManager::alreadyExists( const std::unique_ptr < Campus > &campus )const
{
	if( campus.get() == nullptr )
	{
		return false;
	}
	for( auto it =  mVectCampus.begin() ; it != mVectCampus.end() ; ++it )
	{
		if( *it.base()->get()  == *campus.get() )
		{
			return true;
		}
	}
	return false;
}

bool CampusManager::rmCampus( std::unique_ptr< Campus > &campus )
{
	for( auto it =  mVectCampus.begin() ; it != mVectCampus.end() ; ++it )
	{
		if( *it.base() -> get() == *campus.get() )
		{
			mVectCampus.erase( it );
			return true;
		}
	}
	return false;
}

void CampusManager::rmAllCampus()
{
	mVectCampus.clear();
}

void CampusManager::testInit()
{
	//initialization of teacher
	std::unique_ptr< Teacher >
			tmpA = std::make_unique< InternalTeacher >( 5 , "Linus", "Torvalds" ),
			tmpB = std::make_unique< InternalTeacher >( 44 , "Denis", "Hooper" ),
			tmpC = std::make_unique< ExternalTeacher >( 6 , "Sandra", "Del" ),
			tmpD = std::make_unique< ExternalTeacher >( 2 , "Adam", "Jensen" );

	std::unique_ptr< Campus >
			tmpCamp = std::make_unique< Campus >( "CERI", "PACA", 4 );

	mVectCampus.push_back( std::move( tmpCamp ) );
	mVectCampus[0] -> addStudent( Student( 5 , "Richard", "Stallman" ) );
	mVectCampus[0] -> addStudent( Student( 55 , "Demago", "sss" ) );
	mVectCampus[0] -> addStudent( Student( 0 , "test", "testttq" ) );
	mVectCampus[0] -> addTeacher( tmpA );
	mVectCampus[0] -> addTeacher( tmpB );

	tmpCamp = std::make_unique< Campus >( "St-Marthe", "PACA", 64 );
	mVectCampus.push_back( std::move( tmpCamp ) );
	mVectCampus[1] -> addStudent( Student( 6 , "ddddddddd", "qqqqqqqq" ) );
	mVectCampus[1] -> addStudent( Student( 5 , "ddddddddd", "ssssss" ) );

	tmpCamp = std::make_unique< Campus >( "Agroparc", "PACA", 15 );
	mVectCampus.push_back( std::move( tmpCamp ) );
	mVectCampus[2] -> addTeacher( tmpC );
	mVectCampus[2] -> addTeacher( tmpD );
	InternalTeacher::defineGlobalSalaryInternal( 800 );
}

void CampusManager::displayAllCampus() const
{
	std::cout << "Display all campus begin ======================= \n";

	for( const std::unique_ptr < Campus > &campus : mVectCampus )
	{
		campus -> displayCampus();
	}

	std::cout << "Display all campus end ======================= \n";
}



const std::vector< std::unique_ptr < Campus > > &CampusManager::getAllCampus() const
{
	return mVectCampus;
}

bool CampusManager::addStudentToCampus(const Student &s, unsigned int numCampus)
{
	if( numCampus >= mVectCampus.size() )
	{
		return false;
	}
	try
	{
		return mVectCampus[ numCampus ]->addStudent( s );

	}catch( FullCampusException fe )
	{
		std::cout << fe.what() <<"\n";
		return false;
	}
}

bool CampusManager::addTeacherToCampus(std::unique_ptr<Teacher> &t, unsigned int numCampus)
{
	if( numCampus >= mVectCampus.size() )
	{
		return false;
	}
	mVectCampus[ numCampus ]->addTeacher( t );
	return true;
}

bool CampusManager::removeTeacherToCampus( std::unique_ptr<Teacher> &t , unsigned int numCampus)
{
	if( numCampus >= mVectCampus.size() )
	{
		return false;
	}
	mVectCampus[ numCampus ]->removeTeacher( t );
	return true;
}

bool CampusManager::removeStudentToCampus(const Student &s, unsigned int numCampus)
{
	if( numCampus >= mVectCampus.size() )
	{
		return false;
	}
	return mVectCampus[ numCampus ]->removeStudent( s );
}
