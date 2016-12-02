#include "campusmanager.hpp"
#include "externalteacher.hpp"
#include "internalteacher.hpp"
#include <tinyxml.h>
#include <memory>


unsigned int CampusManager::addCampus(const Campus &campus)
{
	mVectCampus.push_back( campus );
	return mVectCampus.size();
}

unsigned int CampusManager::rmCampus(unsigned int index)
{
//	mVectCampus.erase( index );
	return mVectCampus.size();
}

void CampusManager::rmAllCampus()
{
	mVectCampus.clear();
}

void CampusManager::testInit()
{
	InternalTeacher tmpA(5 , "lll", "ss"),
			tmpB(44 , "dvveqQQde", "llll");
	ExternalTeacher	tmpC(6 , "dvveqQQde", "llll"),
			tmpD(2 , "qqq", "ffff");

	mVectCampus.push_back( Campus( "aramon", "france", 4 ) );
	mVectCampus[0].addStudent( Student(5 , "dede", "sqsd") );
	mVectCampus[0].addStudent( Student(55 , "ss", "qq") );
	mVectCampus[0].addStudent( Student(0 , "cvbb", "hfghgf") );
	mVectCampus[0].addTeacher( tmpA );
	mVectCampus[0].addTeacher( tmpB );
	//mVectCampus[0].displayStudent();

	/*mVectCampus.push_back( Campus( "dfg", "jhk", 64 ) );
	mVectCampus[1].addStudent( Student(6 , "defghde", "sqwwwsd") );
	mVectCampus[1].addStudent( Student(5 , "dvvede", "sqxcsd") );

	mVectCampus.push_back( Campus( "hj", "n", 15 ) );
	mVectCampus[2].addTeacher( tmpC );
	mVectCampus[2].addTeacher( tmpD );*/



}

void CampusManager::loadStudentsFromXML( const std::__cxx11::string &pathFile )
{

}



const std::vector<Campus> &CampusManager::getAllCampus() const
{
	return mVectCampus;
}
