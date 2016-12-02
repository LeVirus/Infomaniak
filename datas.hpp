#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include "campusmanager.hpp"
#include <tinyxml.h>

class Datas
{
private:
	//TiXmlElement mTinyXMLElement;
	void saveStudentsDatasFromXML(const Campus &campus, TiXmlElement &listStudentsNode );
	void saveTeachersDatasFromXML( const Campus &campus, TiXmlElement &listTeachersNode );
	void loadStudentsDatasFromXML( Campus &campus, TiXmlElement &campusNode );
	void loadTeachersDatasFromXML( Campus &campus, TiXmlElement &campusNode );
public:
	Datas() = default;
	void saveDatasFromXML( const CampusManager &campusManager = CampusManager() ,
						   const std::string &pathFile = "doc.xml");
	void loadDatasFromXML( CampusManager &campusManager ,const std::string &pathFile = "doc.xml" );

};

#endif // DATA_HPP
