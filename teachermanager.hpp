#ifndef TEACHERMANAGER_H
#define TEACHERMANAGER_H


class TeacherManager
{
private:
	unsigned int mUiSalaryInternalTeacher;
public:
	TeacherManager() = default;
	void editSalaryInternalTeacher( unsigned int salary );
};

#endif // TEACHERMANAGER_H
