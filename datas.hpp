#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include "campusmanager.hpp"
#include <tinyxml.h>

class Datas
{
private:
	void saveStudentsDatasFromXML(const std::unique_ptr<Campus> &campus, TiXmlElement &listStudentsNode );
	void saveTeachersDatasFromXML( const std::unique_ptr<Campus> &campus, TiXmlElement &listTeachersNode );
	void loadStudentsDatasFromXML(std::unique_ptr<Campus> &campus, TiXmlElement &campusNode );
	void loadTeachersDatasFromXML(std::unique_ptr<Campus> &campus, TiXmlElement &campusNode );
public:
	Datas() = default;
	void saveDatasFromXML( const CampusManager &campusManager = CampusManager() ,
						   const std::string &pathFile = "doc.xml");
	void loadDatasFromXML( CampusManager &campusManager ,const std::string &pathFile = "doc.xml" );

};

#endif // DATA_HPP
