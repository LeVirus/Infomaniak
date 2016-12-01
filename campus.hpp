#ifndef CAMPUS_H
#define CAMPUS_H

#include <string>
#include <set>
#include <vector>
#include <functional>
#include "student.hpp"
#include "teacher.hpp"
#include "fullcampusException.hpp"


class StudentsManager;
//define Compare for the compiler
using Compare = bool(*)( const Student&, const Student& );

class Campus
{
private:
	StudentsManager *mPtrStudentsManager = nullptr;

	std::multiset< Student, Compare > mMultiSetStudents;

	std::vector< std::reference_wrapper < Teacher > > mVectTeachers;
	std::string mStrTown, mStrRegion;
	unsigned int mUiCapacity, mUiEffective = 0;
public:
	Campus( std::string town, std::string region, unsigned int capacity );
	void editCapacity( unsigned int capacity );
	void editVille( std::string town );
	void editRegion( std::string region );
	void displayCampus()const;
	bool operator==( const Campus& c );
	bool operator!=( const Campus& c );

	const std::string &getTown()const;
	const std::string &getRegion()const;
	unsigned int getCapacity()const;
	unsigned int getEffective()const;
	const std::vector<std::reference_wrapper<Teacher> > &getTeachers()const;
	const std::multiset< Student, Compare > &getStudents()const;

	unsigned int addStudent( const Student &s );
	unsigned int removeStudent( const Student &s );
	void rmAllStudents();
	unsigned int getStudentsEffective()const;

	unsigned int addTeacher(Teacher &t );
	unsigned int removeTeacher( Teacher &t );
};

#endif // CAMPUS_H
