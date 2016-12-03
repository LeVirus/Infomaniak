#ifndef SCHOOL_H
#define SCHOOL_H

#include "campusmanager.hpp"
#include "datas.hpp"

class School
{
private:
	CampusManager mCampusManager;
	Datas mDatas;
	void addStudentToCampus();
	void addTeacherToCampus();
	void addCampus();
	void removeCampus();
	void removeTeacherFromCampus();
	void removeStudentFromCampus();
public:
	School() = default;
	void runTest();
	void saveDatas();
	void loadDatas();
	void testInteract();
	void displayMenu()const;
};

#endif
