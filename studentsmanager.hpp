#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include "student.hpp"
#include <vector>
#include <string>

class StudentsManager
{
private:
	std::vector< Student > mVectStudents;
	std::string xml_filename;
public:
	StudentsManager();
	void initXML( const std::string &filename );
	void saveStudentsFromXML( const std::string &pathFile );
	void loadStudentsFromXML( const std::string &pathFile );
	void testInit();
	void displayStudents()const;

};

#endif
