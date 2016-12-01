#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include "campusmanager.hpp"
#include <tinyxml.h>

class Datas
{
private:
	//TiXmlElement mTinyXMLElement;
	void saveStudentsDatasFromXML( const Campus &campus, TiXmlElement &elementAdd );
	void saveTeachersDatasFromXML( const Campus &campus, TiXmlElement &elementAdd );
public:
	Datas() = default;
	void saveDatasFromXML( const std::string &pathFile = "doc.xml",
						   const CampusManager &campusManager = CampusManager() );
	void loadDatasFromXML( const std::string &pathFile = "doc.xml"
						   /*CampusManager &campusManager*/ );

};

#endif // DATA_HPP
