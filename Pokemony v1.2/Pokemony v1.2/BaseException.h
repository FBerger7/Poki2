#pragma once
#include<string>
#include<exception>
#include<iostream>

using namespace std;

class BaseException: public exception
{
protected:
	string Reason;
public:
	BaseException(const char* why) :Reason(why) {}
	const char* what() const throw();
	~BaseException();
};



