#include "datas.hpp"
#include "campusmanager.hpp"
#include "campus.hpp"
#include "student.hpp"
#include "internalteacher.hpp"
#include "externalteacher.hpp"
#include <memory>
#include <vector>
#include <exception>
#include <functional>
#include <cassert>


void Datas::saveDatasFromXML( const CampusManager &campusManager, const std::string &pathFile )
{
	std::unique_ptr< TiXmlDocument > ptrTinyXMLDoc = std::make_unique< TiXmlDocument >( pathFile );


	TiXmlElement campusNode( "Campus" ), rootNode( "Root" ), listStudentsNode( "ListStudents" ),
		listTeachersNode( "ListTeachers" );

	ptrTinyXMLDoc -> LoadFile();
	ptrTinyXMLDoc -> Clear();
	ptrTinyXMLDoc -> LinkEndChild( &rootNode );

	for( const std::unique_ptr< Campus > &campus : campusManager.getAllCampus() )
	{
		listStudentsNode.Clear();
		listTeachersNode.Clear();
		campusNode.SetAttribute( "mStrTown"  , campus -> getTown() );
		campusNode.SetAttribute( "mStrRegion"  , campus -> getRegion() );
		campusNode.SetAttribute( "mUiCapacity", campus -> getCapacity() );
		campusNode.SetAttribute( "mUiEffective", campus -> getEffective() );

		saveStudentsDatasFromXML( campus, listStudentsNode );
		saveTeachersDatasFromXML( campus, listTeachersNode );

		campusNode.LinkEndChild( &listStudentsNode );
		campusNode.LinkEndChild( &listTeachersNode );

		rootNode.InsertEndChild( campusNode );
	}

	//send datas to xml file
	if( !ptrTinyXMLDoc -> SaveFile( pathFile ) )
	{
		std::cerr << "error while writing to xml file\n";
	}

}

void Datas::saveStudentsDatasFromXML( const std::unique_ptr< Campus > &campus,
									  TiXmlElement &listStudentsNode )
{
	TiXmlElement elementStudent( "Student" );

	for( const Student &s : campus -> getStudents() )
	{
		elementStudent.SetAttribute( "mUiId"  , s.getId() );
		elementStudent.SetAttribute( "mStrFirstName"  , s.getFirstName() );
		elementStudent.SetAttribute( "mStrLastName", s.getLastName() );

		listStudentsNode.InsertEndChild( elementStudent );
	}
}

void Datas::saveTeachersDatasFromXML(const std::unique_ptr< Campus > &campus,
									 TiXmlElement &listTeachersNode )
{
	TiXmlElement elementTeacher( "Teacher" );
	for( const std::unique_ptr< Teacher > &t : campus -> getTeachers() )
	{
		elementTeacher.SetAttribute( "mUiId"  , t -> getId() );
		elementTeacher.SetAttribute( "mStrFirstName"  , t -> getFirstName() );
		elementTeacher.SetAttribute( "mStrLastName", t -> getLastName() );
		elementTeacher.SetAttribute( "mStrStatus", t -> getStatus() );
		elementTeacher.SetAttribute( "mUiSalary"  , t -> getSalary() );

		listTeachersNode.InsertEndChild( elementTeacher );
	}
}



void Datas::loadDatasFromXML( CampusManager &campusManager, const std::string &pathFile )
{
	std::unique_ptr< TiXmlDocument > ptrTinyXMLDoc = std::make_unique< TiXmlDocument >( pathFile );
	TiXmlHandle XmlHandle( ptrTinyXMLDoc.get() );
	std::string strTown, strRegion;


	if( !ptrTinyXMLDoc -> LoadFile() )
	{
		std::cerr << "error #" << ptrTinyXMLDoc -> ErrorId() << " : " <<
					 ptrTinyXMLDoc -> ErrorDesc() << "\n";
		return;
	}

	TiXmlElement *campusNode = XmlHandle.FirstChildElement().FirstChildElement().Element();

	//root/campus
	if( !campusNode )
	{
		std::cerr << "inexistent node\n";
		return;
	}
	//loop Campus
	while ( campusNode )
	{
		int memEffectiveCampus = 0, memCapacityCampus = 0;

		//earn elements from xml file for each objects
		campusNode -> QueryIntAttribute( "mUiCapacity", &memEffectiveCampus );

		campusNode -> QueryIntAttribute( "mUiEffective", &memCapacityCampus );

		strTown = campusNode -> Attribute("mStrTown");
		strRegion = campusNode -> Attribute("mStrRegion");

		//check if the arguments are corrects
		std::unique_ptr< Campus > campus = std::make_unique< Campus >(
					strTown, strRegion, ( unsigned int )memCapacityCampus );
		loadStudentsDatasFromXML( campus, *campusNode );
		loadTeachersDatasFromXML( campus, *campusNode );

		campusManager.addCampus( campus );
		campusNode = campusNode -> NextSiblingElement(); // iteration
	}
}

void Datas::loadStudentsDatasFromXML( std::unique_ptr< Campus > &campus, TiXmlElement &campusNode)
{

	int memIdStudent = 0;
	std::string strFirstName, strLastName;
	TiXmlElement *studentNode = campusNode.FirstChildElement("ListStudents")->FirstChildElement();
	while ( studentNode )
	{
		//earn elements from xml file for each objects
		studentNode -> QueryIntAttribute( "mUiId", &memIdStudent );
		strFirstName = studentNode -> Attribute("mStrFirstName");

		strLastName = studentNode -> Attribute("mStrLastName");

		campus -> addStudent( Student( (unsigned int)memIdStudent, strFirstName, strLastName ) );

		studentNode = studentNode -> NextSiblingElement(); // iteration
	}

}

void Datas::loadTeachersDatasFromXML(std::unique_ptr< Campus > &campus, TiXmlElement &campusNode)
{
	int memIdTeacher = 0, memSalary = 0;
	std::unique_ptr< Teacher > teacher;
	std::string strFirstName, strLastName, strStatus;
	TiXmlElement *teacherNode = campusNode.FirstChildElement("ListTeachers") -> FirstChildElement();
	while ( teacherNode )
	{

		//earn elements from xml file for each objects
		teacherNode -> QueryIntAttribute( "mUiId", &memIdTeacher );
		teacherNode -> QueryIntAttribute( "mUiSalary", &memSalary );
		strFirstName = teacherNode -> Attribute("mStrFirstName");
		strLastName = teacherNode -> Attribute("mStrLastName");
		strStatus = teacherNode -> Attribute("mStrStatus");

		if( strStatus == "internal" )
		{
			teacher = std::make_unique< InternalTeacher >(
						( unsigned int )memIdTeacher, strFirstName, strLastName );
			teacher -> editSalary( ( unsigned int )memSalary );
			campus -> addTeacher( teacher );
		}
		else if( strStatus == "external" )
		{
			teacher = std::make_unique< ExternalTeacher >(
						( unsigned int )memIdTeacher, strFirstName, strLastName );
			teacher -> editSalary( ( unsigned int ) memSalary );

			campus -> addTeacher( teacher );
		}
		teacherNode = teacherNode -> NextSiblingElement(); // iteration
	}
}

