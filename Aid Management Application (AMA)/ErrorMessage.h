#ifndef SICT_ERRORMESSAGE_H__
#define SICT_ERRORMESSAGE_H__
#include <iostream>
using namespace std;
namespace sict{
	class ErrorMessage {
	private:
		char* message_;


	public:
		ErrorMessage(const ErrorMessage& em) = delete;
		ErrorMessage();
		ErrorMessage(const char* errormessage);
		ErrorMessage& operator=(const char* errorMessage);
		ErrorMessage& operator=(const ErrorMessage& em) = delete;
		virtual ~ErrorMessage();
		void clear();
		bool isClear()const;
		void message(const char* value);
		const char* message()const;
	};
	
	ostream &operator << (ostream &output, const ErrorMessage &MyErrorMessage);



	





}
#endif

