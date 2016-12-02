#include "datas.hpp"
#include "campusmanager.hpp"
#include "campus.hpp"
#include "student.hpp"
#include "internalteacher.hpp"
#include "externalteacher.hpp"
#include <memory>
#include <vector>
#include <functional>


void Datas::saveDatasFromXML(const CampusManager &campusManager, const std::string &pathFile )
{
	std::unique_ptr< TiXmlDocument > ptrTinyXMLDoc = std::make_unique< TiXmlDocument >( pathFile );


	TiXmlElement campusNode( "Campus" ), rootNode( "Root" ), listStudentsNode( "ListStudents" ),
		listTeachersNode( "ListTeachers" );

	ptrTinyXMLDoc -> LoadFile();
	ptrTinyXMLDoc -> Clear();
	ptrTinyXMLDoc -> LinkEndChild( &rootNode );

	for( const Campus &campus : campusManager.getAllCampus() )
	{
		//campus.displayCampus();
		std::cout << pathFile << "iteration campus\n" << campus.getEffective() <<"\n";

		campusNode.Clear();
		listStudentsNode.Clear();
		listTeachersNode.Clear();

		campusNode.SetAttribute( "mStrTown"  , campus.getTown() );
		campusNode.SetAttribute( "mStrRegion"  , campus.getRegion() );
		campusNode.SetAttribute( "mUiCapacity", campus.getCapacity() );
		campusNode.SetAttribute( "mUiEffective", campus.getEffective() );

		std::cout << "sss campus\n";

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

void Datas::saveStudentsDatasFromXML( const Campus &campus, TiXmlElement &listStudentsNode )
{
	TiXmlElement elementStudent( "Student" );

	for( const Student &s : campus.getStudents() )
	{
		elementStudent.SetAttribute( "mUiId"  , s.getId() );
		elementStudent.SetAttribute( "mStrFirstName"  , s.getFirstName() );
		elementStudent.SetAttribute( "mStrLastName", s.getLastName() );

		listStudentsNode.InsertEndChild( elementStudent );
	}
}

void Datas::saveTeachersDatasFromXML(const Campus &campus, TiXmlElement &listTeachersNode )
{
	std::cout <<"proffffffffffffffff \n";
	TiXmlElement elementTeacher( "Teacher" );
	for( const Teacher &t : campus.getTeachers() )
	{
		std::cout  << t.getStatus()<< "prof it campus  \n" << t.getFirstName() << "ss\n";

		elementTeacher.SetAttribute( "mUiId"  , t.getId() );
		elementTeacher.SetAttribute( "mStrFirstName"  , t.getFirstName() );
		elementTeacher.SetAttribute( "mStrLastName", t.getLastName() );
		elementTeacher.SetAttribute( "mStrStatus", t.getStatus() );
		elementTeacher.SetAttribute( "mUiSalary"  , t.getSalary() );

		listTeachersNode.InsertEndChild( elementTeacher );
	}
}



void Datas::loadDatasFromXML(CampusManager &campusManager, const std::string &pathFile)
{
	std::unique_ptr< TiXmlDocument > ptrTinyXMLDoc = std::make_unique< TiXmlDocument >( pathFile );
	TiXmlHandle XmlHandle( ptrTinyXMLDoc.get() );
	std::string strTown, strRegion;
	TiXmlElement *campusNode = XmlHandle.FirstChildElement().FirstChildElement("Campus").Element();


	if( !ptrTinyXMLDoc -> LoadFile() )
	{
		std::cerr << "error #" << ptrTinyXMLDoc -> ErrorId() << " : " <<
					 ptrTinyXMLDoc -> ErrorDesc() << "\n";
		return;
	}
	//root/campus
	//campusNode = &XmlHandle.FirstChildElement().FirstChildElement("Campus");
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
		if( !campusNode -> QueryIntAttribute( "mUiCapacity", &memEffectiveCampus ) )
		{
			std::cout << "Error while earning campus id\n";
		}

		if( !campusNode -> QueryIntAttribute( "mUiCapacity", &memCapacityCampus ) )
		{
			std::cout << "Error while earning campus id\n";
		}

		strTown = campusNode -> Attribute("mStrTown");
		strRegion = campusNode -> Attribute("mStrRegion");

		//check if the arguments are corrects
		Campus campus( strTown, strRegion, ( unsigned int )memCapacityCampus );

		loadStudentsDatasFromXML( campus, *campusNode );
		loadTeachersDatasFromXML( campus, *campusNode );

		campusManager.addCampus( campus );

		campusNode = campusNode -> NextSiblingElement(); // iteration
	}
}

void Datas::loadStudentsDatasFromXML(Campus &campus, TiXmlElement &campusNode)
{
	int memIdStudent = 0;
	std::string strFirstName, strLastName;
	TiXmlElement *studentNode = campusNode.FirstChildElement("ListStudents")->FirstChildElement();
	while ( studentNode )
	{
		//earn elements from xml file for each objects
		if( !campusNode.QueryIntAttribute( "mUiId", &memIdStudent ) )
		{
			std::cout << "Error while earning student id\n";
		}

		strFirstName = campusNode.Attribute("mStrFirstName");
		strLastName = campusNode.Attribute("mStrLastName");

		campus.addStudent( Student( (unsigned int)memIdStudent, strFirstName, strLastName ) );

		studentNode = studentNode -> NextSiblingElement(); // iteration
	}
}

void Datas::loadTeachersDatasFromXML(Campus &campus, TiXmlElement &campusNode)
{
	int memIdTeacher = 0, memSalary = 0;
	std::string strFirstName, strLastName, strStatus;
	TiXmlElement *teacherNode = campusNode.FirstChildElement("ListStudents") -> FirstChildElement();
	while ( teacherNode )
	{
		//earn elements from xml file for each objects
		if( !campusNode.QueryIntAttribute( "mUiId", &memIdTeacher ) )
		{
			std::cout << "Error while earning teacher id\n";
		}
		if( !campusNode.QueryIntAttribute( "mUiSalary", &memSalary ) )
		{
			std::cout << "Error while earning teacher salary\n";
		}

		strFirstName = campusNode.Attribute("mStrFirstName");
		strLastName = campusNode.Attribute("mStrLastName");
		strStatus = campusNode.Attribute("mStrStatus");

		if( strStatus == "internal" )
		{
			InternalTeacher teacher( ( unsigned int )memIdTeacher, strFirstName, strLastName );
			teacher.defineGlobalSalaryInternal( memSalary );
			campus.addTeacher( teacher );
		}
		else if( strStatus == "external" )
		{
			ExternalTeacher teacher( ( unsigned int )memIdTeacher, strFirstName, strLastName );
			teacher.editSalaryExternal( ( unsigned int ) memSalary );
			campus.addTeacher( teacher );
		}
		teacherNode = teacherNode -> NextSiblingElement(); // iteration
	}
}

