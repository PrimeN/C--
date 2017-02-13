#include <iomanip>
#include <iostream>
using namespace std;
#include "Date.h"
#include "general.h"
namespace sict{
	
	int Date::Validate(int Year, int Month, int Day)
	{
		if (Year < MIN_YEAR || Year > MAX_YEAR)
			return YEAR_ERROR;
		else if (Month < 1 || Month > 12)
			return MON_ERROR;
		else if (Day > mdays() || Day < 1)
			return DAY_ERROR;
		else
			return NO_ERROR;
	}

	void Date::Set(int Year, int Month, int Day)
	{
		year_ = Year;
		mon_ = Month;
		day_ = Day;
		readErrorCode_ = Validate(Year, Month, Day);
	}
	
	int Date::value()const
  {
    return year_ * 372 + mon_ * 31 + day_;
  }

	std::istream & Date::read(std::istream & istr)
	{
		istr >> year_;
		istr.get();
		istr >> mon_;
		istr.get();
		istr >> day_;
		if (istr.fail())
		{
			readErrorCode_ = CIN_FAILED;
		}
		else
		readErrorCode_ = Validate(year_, mon_, day_);
		return istr;
	}

	std::ostream & Date::write(std::ostream & ostr) const
	{
		ostr << year_ << "/" << setfill('0') << setw(2) << mon_ << "/" << setfill('0') << setw(2) << day_;
		return ostr;
	}

	int Date::mdays()const
  {
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
    mon--;
    return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
  }

	Date::Date()
  {
	day_ = 0;
	mon_ = 0;
	year_ = 0;
	readErrorCode_ = 0;
  }

	Date::Date(int Year, int Month, int Day)
  {
	  Set(Year, Month, Day);
  }

	void Date::errCode(int errorCode)
  {
	  readErrorCode_ = errorCode;
  }

	bool Date::operator==(const Date & D) const
	{
		if (this->value() == D.value())
			return true;
		else
			return false;
	}

	bool Date::operator!=(const Date & D) const
	{
		if (this->value() != D.value())
			return true;
		else
			return false;
	}

	bool Date::operator<(const Date & D) const
	{
		if (this->value() < D.value())
			return true;
		else
			return false;
	}

	bool Date::operator>(const Date & D) const
	{
		if (this->value() > D.value())
			return true;
		else
			return false;
	}

	bool Date::operator<=(const Date & D) const
	{
		if (this->value() <= D.value())
			return true;
		else
			return false;
	}

	bool Date::operator>=(const Date & D) const
	{
		if (this->value() >= D.value())
			return true;
		else
			return false;
	}

	istream & operator>>(istream & input, Date & MRead)
	{
		return	MRead.read(input);
	}

	ostream & operator<<(ostream & output, const Date & MWrite)
	{
		return MWrite.write(output);
	}

}
