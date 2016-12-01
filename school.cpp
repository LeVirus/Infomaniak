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
	mDatas.saveDatasFromXML( "doc.xml", mCampusManager );
}

void School::loadDatas()
{
	//mDatas.loadDatasFromXML( "doc.xml", mCampusManager );
}
