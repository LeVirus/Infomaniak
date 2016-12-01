#include "datas.hpp"
#include "campusmanager.hpp"
#include "campus.hpp"
#include "student.hpp"
#include <memory>
#include <vector>
#include <functional>


void Datas::saveDatasFromXML(const std::string &pathFile , const CampusManager &campusManager)
{
	std::unique_ptr< TiXmlDocument > ptrTinyXMLDoc = std::make_unique< TiXmlDocument >( pathFile );

	TiXmlElement elementAdd( "Campus" ), rootNode( "Root" );

	ptrTinyXMLDoc -> LoadFile();
	ptrTinyXMLDoc -> Clear();
	ptrTinyXMLDoc -> LinkEndChild( &rootNode );

	for( const Campus &campus : campusManager.getAllCampus() )
	{
		std::cout << pathFile << "iteration campus\n";

		elementAdd.Clear();
		elementAdd.SetAttribute( "mStrTown"  , campus.getTown() );
		elementAdd.SetAttribute( "mStrRegion"  , campus.getRegion() );
		elementAdd.SetAttribute( "mUiCapacity", campus.getCapacity() );
		elementAdd.SetAttribute( "mUiEffective", campus.getEffective() );
		saveStudentsDatasFromXML( campus, elementAdd );
		saveTeachersDatasFromXML( campus, elementAdd );

		rootNode.InsertEndChild( elementAdd );
	}

	//send datas to xml file
	if( !ptrTinyXMLDoc -> SaveFile( pathFile ) )
	{
		std::cerr << "error while writing to xml file\n";
	}
}

void Datas::saveStudentsDatasFromXML( const Campus &campus, TiXmlElement &elementAdd )
{
	TiXmlElement elementStudent( "Student" );
	for( const Student &s : campus.getStudents() )
	{
		elementStudent.SetAttribute( "mUiId"  , s.getId() );
		elementStudent.SetAttribute( "mStrFirstName"  , s.getFirstName() );
		elementStudent.SetAttribute( "mStrLastName", s.getLastName() );

		elementAdd.InsertEndChild( elementStudent );
	}
}

void Datas::saveTeachersDatasFromXML( const Campus &campus, TiXmlElement &elementAdd )
{
	TiXmlElement elementTeacher( "Teacher" );
	for( const std::reference_wrapper < Teacher > t : campus.getTeachers() )
	{
		std::cout  << "prof it campus  \n" << t.get().getFirstName() << "\n";

		elementTeacher.SetAttribute( "mUiId"  , t.get().getId() );
		elementTeacher.SetAttribute( "mStrFirstName"  , t.get().getFirstName() );
		elementTeacher.SetAttribute( "mStrLastName", t.get().getLastName() );
		elementTeacher.SetAttribute( "mStrStatus", t.get().getStatus() );
		elementTeacher.SetAttribute( "mUiSalary"  , t.get().getSalary() );


		elementAdd.InsertEndChild( elementTeacher );
	}
}

void Datas::loadDatasFromXML(const std::string &pathFile)
{
	/*int idStudent;
	std::string firstNameStudent, lastNameStudent;
	TiXmlElement *elementAdd;
	std::unique_ptr< TiXmlDocument > ptrTinyXMLDoc = std::make_unique< TiXmlDocument >( pathFile );
	TiXmlHandle XmlHandle( ptrTinyXMLDoc.get() );

	if( !ptrTinyXMLDoc -> LoadFile() )
	{
		std::cerr << "error #" << ptrTinyXMLDoc -> ErrorId() << " : " <<
					 ptrTinyXMLDoc -> ErrorDesc() << "\n";
		return;
	}

	//get first user in the node root of xml file
	elementAdd = XmlHandle.FirstChildElement().FirstChildElement().Element();

	if( !elementAdd )
	{
		std::cerr << "inexistent node\n";
		return;
	}

	while ( elementAdd )
	{
		idStudent = ERR_ID;
		firstNameStudent = "";
		lastNameStudent = "";

		//earn elements from xml file for each objects
		if( !elementAdd -> QueryIntAttribute( "mUiId", &idStudent ) )
		{
			std::cout << "Error while earning student id\n";
		}
		firstNameStudent = elementAdd -> Attribute("mStrFirstName");
		lastNameStudent = elementAdd -> Attribute("mStrLastName");

		//check if the arguments are corrects
		if( idStudent != -1 && firstNameStudent != "" && lastNameStudent != "" )
		{
			mVectStudents.push_back( Student( ( unsigned int )idStudent, firstNameStudent, lastNameStudent ) );
		}

		elementAdd = elementAdd -> NextSiblingElement(); // iteration
	}*/
}


