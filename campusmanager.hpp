#ifndef CAMPUSMANAGER_H
#define CAMPUSMANAGER_H

#include "campus.hpp"
#include <vector>

class CampusManager
{
private:
	std::vector< Campus > mVectCampus;
public:
	CampusManager() = default;
	unsigned int addCampus( const Campus &campus );
	unsigned int rmCampus( unsigned int index );
	void rmAllCampus();
	//const Campus *getCampusByIndex( unsigned int index )const;
	void testInit();
	void saveStudentsFromXML( const std::string &pathFile );
	void loadStudentsFromXML( const std::string &pathFile );

	const std::vector< Campus > &getAllCampus()const;
};

#endif
