#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include "constants.hpp"

class Teacher
{
protected:
	unsigned int mUiId = NO_ID;
	std::string mStrFirstName, mStrLastName, mStrStatus;
public:
	Teacher() = default;

	bool operator==( const Teacher& t )const;
	bool operator!=( const Teacher& t )const;

	unsigned int getId()const;
	const std::string &getFirstName()const;
	const std::string &getLastName()const;
	const std::string &getStatus()const;
	virtual unsigned int getSalary()const = 0;
	virtual void displayTeacher()const;
	virtual void editSalary( unsigned int salary ) = 0;
};

#endif // TEACHER_H
