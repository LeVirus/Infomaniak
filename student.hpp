#ifndef STUDANT_H
#define STUDANT_H

#include <string>
#include "constants.hpp"

class Student
{
private:
	unsigned int mUiId = NO_ID;
	std::string mStrFirstName, mStrLastName;
public:
	Student() = default;
	Student( unsigned int id, const std::string &firstName, const std::string &lastName );
	unsigned int getId()const;

	bool operator==( const Student& s )const;
	bool operator!=( const Student& s )const;

	const std::string &getFirstName()const;
	const std::string &getLastName()const;
	void displayStudent() const;
};

#endif
