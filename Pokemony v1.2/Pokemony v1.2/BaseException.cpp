#include "BaseException.h"



const char* BaseException::what() const throw()
{
	return Reason.c_str();
}


BaseException::~BaseException()
{
}
