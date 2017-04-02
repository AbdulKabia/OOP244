#define _CRT_SECURE_NO_WARNINGS
#include "ErrorMessage.h"
#include <iomanip>
#include <iostream>
#include <cstring>
using namespace std;
namespace sict{

	ErrorMessage::ErrorMessage(){
		message_ = nullptr;
	}

	ErrorMessage::ErrorMessage(const char* errorMessage){
		message_ = nullptr;
		message(errorMessage);
	}

	ErrorMessage& ErrorMessage::operator=(const char* errorMessage){
		delete[] message_;
		message_ = new char[strlen(errorMessage) + 1];
		strcpy(message_, errorMessage);
		return *this;

	}

	ErrorMessage::~ErrorMessage(){
		delete[] message_;
	}

	void ErrorMessage::clear(){
		delete[] message_;
		message_ = nullptr;
	}

	bool ErrorMessage::isClear() const{
		if (message_ == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void ErrorMessage::message(const char* value){
		delete[] message_;
		message_ = new char[strlen(value) + 1];
		strcpy(message_, value);

	}

	const char* ErrorMessage::message() const{
		return message_;
	}


	std::ostream& operator<<(std::ostream& os, ErrorMessage& m){
		if (!m.isClear())
		{
			cout << m.message();
		}
		return os;
	}

}