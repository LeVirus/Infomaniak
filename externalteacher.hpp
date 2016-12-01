#ifndef EXTERNALTEACHER_H
#define EXTERNALTEACHER_H

#include "teacher.hpp"

class ExternalTeacher : public Teacher
{
private:
	unsigned int mUiSalaryExternal;
public:
	ExternalTeacher();
	ExternalTeacher( unsigned int id, const std::string &firstName, const std::string &lastName );
	virtual unsigned int getSalary()const;
};

#endif // EXTERNALTEACHER_H
