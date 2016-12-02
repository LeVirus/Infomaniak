#include "school.hpp"

void School::runTest()
{
	//test save
	mCampusManager.testInit();
	saveDatas();
	//mStudentsManager.saveStudentsFromXML("doc.xml");

	//test load
	//mStudentsManager.loadStudentsFromXML("doc.xml");
	//mStudentsManager.displayStudents();

}

void School::saveDatas()
{
	mDatas.saveDatasFromXML( mCampusManager );
}

void School::loadDatas()
{
	mDatas.loadDatasFromXML( mCampusManager );
}
