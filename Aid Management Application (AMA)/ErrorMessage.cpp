#include "ErrorMessage.h"
#include <cstring>
using namespace std;
namespace sict{
	ErrorMessage::ErrorMessage()
	{
		char * ptr = new char;
		ptr = nullptr;
		message_ = ptr;
	}

	ErrorMessage::ErrorMessage(const char* errorMessage)
	{
		clear();
		message(errorMessage);
	}

	ErrorMessage & ErrorMessage::operator=(const char * errorMessage)
	{

		clear();
		message(errorMessage);
		return *this;
		}

	ErrorMessage::~ErrorMessage()
	{
		clear();
	}

	void ErrorMessage::clear()
	{
		message_ = nullptr;
		delete (message_);
	}

	bool ErrorMessage::isClear() const
	{
		return (message_ == nullptr);
	}

	void ErrorMessage::message(const char * value)
	{
		clear();
		int size = (strlen(value) + 1);
		char* TemP = nullptr;
		TemP = new char[size];
		message_ = TemP;

		for (int counter = 0; counter < size; counter++)
			message_[counter] = value[counter];


	}

	const char * ErrorMessage::message() const
	{
		return message_;
	}


	ostream & operator<<(ostream & output, const ErrorMessage & MyErrorMessage)
	{
		if (MyErrorMessage.isClear())
			return output;
		else
			return output << MyErrorMessage.message();	
	}
}