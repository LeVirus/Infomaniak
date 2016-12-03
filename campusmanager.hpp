#ifndef CAMPUSMANAGER_H
#define CAMPUSMANAGER_H

#include "campus.hpp"
#include <vector>
#include <memory>

class CampusManager
{
private:
	std::vector< std::unique_ptr < Campus > > mVectCampus;
public:
	CampusManager() = default;
	unsigned int addCampus(std::unique_ptr<Campus> &campus );
	unsigned int getNumberCampus()const ;
	bool alreadyExists(const std::unique_ptr<Campus> &campus )const;
	bool rmCampus(std::unique_ptr<Campus> &campus );
	void rmAllCampus();
	void testInit();
	void saveStudentsFromXML( const std::string &pathFile );
	void loadStudentsFromXML( const std::string &pathFile );
	void displayAllCampus()const;
	const std::vector<std::unique_ptr<Campus> > &getAllCampus()const;
	bool addStudentToCampus( const Student &s, unsigned int numCampus );
	bool addTeacherToCampus( std::unique_ptr<Teacher> &t, unsigned int numCampus );
	bool removeTeacherToCampus( std::unique_ptr<Teacher> &t, unsigned int numCampus );
	bool removeStudentToCampus(const Student &t, unsigned int numCampus );
};

#endif
