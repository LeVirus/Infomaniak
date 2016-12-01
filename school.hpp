#ifndef SCHOOL_H
#define SCHOOL_H

#include "campusmanager.hpp"
#include "studentsmanager.hpp"
#include "datas.hpp"

class School
{
private:
	CampusManager mCampusManager;
	//StudentsManager mStudentsManager;
	Datas mDatas;
public:
	School() = default;
	void runTest();
	void saveDatas();
	void loadDatas();
};

#endif
