#include "studentsmanager.hpp"
#include "constants.hpp"
#include <memory>
#include <tinyxml.h>

/*
	pour acquerir des donnees d'un fichier xml dont le nom est passe en argument
*/

StudentsManager::StudentsManager(): xml_filename( "doc.xml" )
{

}

void StudentsManager::saveStudentsFromXML( const std::__cxx11::string &pathFile )
{
	std::unique_ptr< TiXmlDocument > ptrTinyXMLDoc = std::make_unique< TiXmlDocument >( pathFile );

	TiXmlElement elementAdd( "user" ), rootNode( "root" );

	ptrTinyXMLDoc -> LoadFile();
	ptrTinyXMLDoc -> Clear();
	ptrTinyXMLDoc -> LinkEndChild( &rootNode );

	for( const Student &student : mVectStudents )
	{
		std::cerr << pathFile << "iteration student\n";
		elementAdd.SetAttribute( "mUiId"  , student.getId() );
		elementAdd.SetAttribute( "mStrFirstName"  , student.getFirstName() );
		elementAdd.SetAttribute( "mStrLastName", student.getLastName() );

		rootNode.InsertEndChild( elementAdd );
	}

	//send datas to xml file
	if( !ptrTinyXMLDoc -> SaveFile( pathFile ) )
	{
		std::cerr << "error while writing to xml file\n";
	}
}

void StudentsManager::loadStudentsFromXML( const std::__cxx11::string &pathFile )
{
	int idStudent;
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
	}
}

void StudentsManager::testInit()
{
	mVectStudents.push_back( Student( 1, "dd", "ss" ) );
	mVectStudents.push_back( Student( 8, "sqqs", "dss" ) );
	mVectStudents.push_back( Student( 3, "dd", "sxs" ) );
}

void StudentsManager::displayStudents() const
{
	std::cout << "Begin display students vector\n";
	for( Student s : mVectStudents )
	{
		s.displayStudent();
	}
	std::cout << "End display students vector\n";

}
