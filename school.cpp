#include "school.hpp"
#include "internalteacher.hpp"
#include "externalteacher.hpp"

void School::addStudentToCampus()
{
	std::string firstName, lastName;
	unsigned int numCampus, studId;
	if( mCampusManager.getNumberCampus() > 0 )
	{
		std::cout << "Which campus? 0 - "<<
					 mCampusManager.getNumberCampus() - 1 <<"\n";
		std::cin >> numCampus;
		if( numCampus >= mCampusManager.getNumberCampus() )
		{
			std::cout << "Error return to menu";
			return;
		}
		std::cout << "ID?";
		std::cin >> studId;
		std::cout << "First name?";
		std::cin >> firstName;
		std::cout << "Last name?";
		std::cin >> lastName;
		if( !mCampusManager.addStudentToCampus( Student( studId, firstName, lastName ), numCampus ))
		{
			std::cout << "Student not found\n";
		}
		else
		{
			std::cout << "Student removed\n";
		}
	}
	else
	{
		std::cout << "There is no campus\n";
	}
}

void School::addTeacherToCampus()
{
	std::unique_ptr< Teacher > tmpTeacher;
	unsigned int  numCampus, teachId;
	bool internal;
	if( mCampusManager.getNumberCampus() > 0 )
	{
		std::cout << "Which campus? 0 - "<< mCampusManager.getNumberCampus() - 1<<"\n";
		std::cin >> numCampus;

		if( numCampus >= mCampusManager.getNumberCampus() )
		{
			std::cout << "Error return to menu";
			return;
		}

		std::cout << "ID?";
		std::cin >> teachId;
		std::cout << "Internal(1) or external(0)?";
		std::cin >> internal;
		if( internal )
		{
			tmpTeacher = std::make_unique< InternalTeacher >( teachId, "Richard", "Stallman" );
		}
		else
		{
			tmpTeacher = std::make_unique< ExternalTeacher >( teachId, "Richard", "Stallman" );
		}
		if( ! mCampusManager.addTeacherToCampus( tmpTeacher, numCampus ) )
		{
			std::cout << "Error\n";
		}
		else
		{
			std::cout << "Teacher added\n";
		}
	}
	else
	{
		std::cout << "There is no campus\n";
	}
}

void School::addCampus()
{
	std::unique_ptr< Campus > tmpCamp = std::make_unique< Campus >( "Avignon", "PACA", 4 );
	if (mCampusManager.addCampus( tmpCamp ) )
	{
		std::cout << "Campus added with default value\n";
	}
	else
	{
		std::cout << "Campus already exists\n";
	}
}

void School::removeCampus()
{
	std::unique_ptr< Campus > tmpCamp;
	std::string town, region;
	unsigned int numCampus;
	std::cout << "Town?\n";
	std::cin >> town;
	std::cout << "Region?\n";
	std::cin >> region;
	std::cout << "capacity?\n";
	std::cin >> numCampus;
	tmpCamp = std::make_unique< Campus >( town, region, numCampus );
	if( mCampusManager.rmCampus( tmpCamp ) )
	{
		std::cout << "Campus removed\n";
	}
	else
	{
		std::cout << "Campus not found\n";
	}
}

void School::removeTeacherFromCampus()
{
	unsigned int numCampus, teachId;
	bool internal;
	std::string firstName, lastName;
	std::unique_ptr< Teacher > tmpTeacher;

	std::cout << "Which campus? 0 - "<< mCampusManager.getNumberCampus() - 1<<"\n";
	std::cin >> numCampus;

	if( numCampus >= mCampusManager.getNumberCampus() )
	{
		std::cout << "Error return to menu";
		return;
	}

	std::cout << "ID?";
	std::cin >> teachId;
	std::cout << "Internal(1) or external(0)?";
	std::cin >> internal;
	std::cout << "First name?";
	std::cin >> firstName;
	std::cout << "Last name?";
	std::cin >> lastName;
	if( internal )
	{
		tmpTeacher = std::make_unique< InternalTeacher >( teachId, firstName, lastName );
	}
	else
	{
		tmpTeacher = std::make_unique< ExternalTeacher >( teachId, firstName, lastName );
	}
	if( !mCampusManager.removeTeacherToCampus( tmpTeacher, numCampus ) )
	{
		std::cout << "Teacher not found\n";
	}
	else
	{
		std::cout << "Teacher removed\n";
	}
}

void School::removeStudentFromCampus()
{
	std::string firstName, lastName;
	unsigned int numCampus, studId;
	//	Student stud( studId, firstName, lastName );
	if( mCampusManager.getNumberCampus() > 0 )
	{
		std::cout << "Which campus? 0 - "<<
					 mCampusManager.getNumberCampus() - 1 <<"\n";
		std::cin >> numCampus;
		if( numCampus >= mCampusManager.getNumberCampus() )
		{
			std::cout << "Error return to menu";
			return;
		}
		std::cout << "ID?";
		std::cin >> studId;
		std::cout << "First name?";
		std::cin >> firstName;
		std::cout << "Last name?";
		std::cin >> lastName;
		if ( !mCampusManager.removeStudentToCampus( Student( studId, firstName, lastName ), numCampus ) )
		{
			std::cout << "Student not found\n";
		}
		else
		{
			std::cout << "Student removed\n";
		}
	}
	else
	{
		std::cout << "There is no campus\n";
	}
}

void School::runTest()
{
	//test save
	mCampusManager.testInit();
	saveDatas();

	//test load
	//loadDatas();
	//mCampusManager.displayAllCampus();

}

void School::saveDatas()
{
	mDatas.saveDatasFromXML( mCampusManager );
}

void School::loadDatas()
{
	mDatas.loadDatasFromXML( mCampusManager );
}

void School::testInteract()
{
	unsigned int cmd;
	do
	{
		std::cout << "Type 0 for help\n";
		std::cin >> cmd;
		switch ( cmd )
		{
		case 0://Display menu
			displayMenu();
			break;
		case 1://Add student to campus
			addStudentToCampus();
			break;
		case 2://Add teacher to campus
			addTeacherToCampus();
			break;
		case 3://Display all campus
			mCampusManager.displayAllCampus();
			break;
		case 4://Save to XML file
			saveDatas();
			break;
		case 5://Load to XML file
			loadDatas();
			break;
		case 6://Run complete test : Initialize entities and save to XML
			runTest();
			break;
		case 7://Add campus
			addCampus();
			break;
		case 8://Remove campus
			removeCampus();
			break;
		case 9://Remove teacher from campus
			removeTeacherFromCampus();
			break;
		case 10://Remove student from campus
			removeStudentFromCampus();
			break;
		case 11://Quit
			break;
		default:
			std::cout << "Error command\n";
			break;
		}
	}while( cmd != 11 );

}



void School::displayMenu() const
{
	std::cout << "0 : Display this menu \n1 : Add student to campus \n2 : Add teacher to campus \n" <<
				 "3 : Display all campus \n4 : Save to XML file \n5 : Load to XML file \n" <<
				 "6 : Run complete test \n7 : Add campus\n"
				 "8 : Remove campus \n9 : Remove teacher from campus \n"
				 "10 : Remove student from campus \n11 Quit\n";
}
