#ifndef FULLCAMPUSEXCEPTION_HPP
#define FULLCAMPUSEXCEPTION_HPP

#include <exception>

class FullCampusException : public std::exception
{
private:
	std::string mMessage;
public:
	FullCampusException( std::string message ) throw(): mMessage( message )
	{

	}

	virtual const char* what() const throw()
		 {
			 return mMessage.c_str();
		 }
};

#endif // FULLCAMPUSEXCEPTION_HPP
