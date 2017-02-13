#ifndef SICT_DATE_H__
#define SICT_DATE_H__

#define NO_ERROR 0 //No error the date is valid
#define CIN_FAILED 1 //--istream failed when entering information
#define YEAR_ERROR 2 //--Year value is invalid
#define MON_ERROR 3 //--Month value is invalid
#define DAY_ERROR 4 //--Day value is invalid

#include <iostream>
using namespace std;

namespace sict{
  class Date{
 
  private:
	int Validate(int Year, int Month, int Day); // Validate Date, Month, Year and return the proper Error
	void Set(int Year, int Month, int Day); // Validates and sets valus
    int value()const;
	void errCode(int errorCode);
	int year_;
	int mon_;
	int day_;
	int readErrorCode_;

  public:
	  Date();
	  Date(int Year, int Month, int Day);
	  bool operator==(const Date& D)const;
	  bool operator!=(const Date& D)const;
	  bool operator<(const Date& D)const;
	  bool operator>(const Date& D)const;
	  bool operator<=(const Date& D)const;
	  bool operator>=(const Date& D)const;
	  int errCode()const { return readErrorCode_; }
	  bool bad()const { return true; }
	  std::istream& read(std::istream& istr);
	  std::ostream& write(std::ostream& ostr)const;
	  int mdays()const;
  };

  ostream &operator << (ostream &output, const Date &SentL);
  istream &operator >> (istream &output, Date &SentL);

}
#endif