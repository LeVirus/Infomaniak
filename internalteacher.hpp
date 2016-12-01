#ifndef INTERNALTEACHER_H
#define INTERNALTEACHER_H

#include "teacher.hpp"

class InternalTeacher : public Teacher
{
private:
	static unsigned int mUiSalaryInternal;

public:
	InternalTeacher();
	InternalTeacher( unsigned int id, const std::string &firstName, const std::string &lastName );
	virtual unsigned int getSalary()const;

	static void defineGlobalSalaryInternal(unsigned int salaryInternal)
	{ mUiSalaryInternal = salaryInternal;}

	static unsigned int getInternalSalary(){ return mUiSalaryInternal;}


};
//unsigned int InternalTeacher::mUiSalaryInternal = 0;

#endif // INTERNALTEACHER_H
