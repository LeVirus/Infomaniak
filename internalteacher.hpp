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
	virtual void displayTeacher()const;
	virtual void editSalary( unsigned int salary );
	static void defineGlobalSalaryInternal( unsigned int salaryInternal );

};

#endif // INTERNALTEACHER_H
