#ifndef CAMPUS_H
#define CAMPUS_H

#include <string>
#include <set>
#include <vector>
#include <memory>
#include <functional>
#include "student.hpp"
#include "teacher.hpp"
#include "fullcampusException.hpp"


//define Compare for the compiler
using Compare = bool(*)( const Student&, const Student& );

class Campus
{
private:
	std::multiset< Student, Compare > mMultiSetStudents;

	std::vector< std::unique_ptr < Teacher > > mVectTeachers;
	std::string mStrTown, mStrRegion;
	unsigned int mUiCapacity, mUiEffective = 0;
public:
	Campus(const std::__cxx11::string &town, const std::__cxx11::string &region,
		   unsigned int capacity );
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
	const std::vector<std::unique_ptr<Teacher> > &getTeachers()const;
	const std::multiset< Student, Compare > &getStudents()const;

	bool addStudent( const Student &s );
	bool removeStudent(const Student &s );
	void rmAllStudents();
	unsigned int getStudentsEffective()const;

	unsigned int addTeacher( std::unique_ptr<Teacher> &t );
	bool removeTeacher( std::unique_ptr<Teacher> &t );
};

#endif // CAMPUS_H
