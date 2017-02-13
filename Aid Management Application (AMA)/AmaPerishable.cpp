#include <cstring>
#include <fstream>
#include <iomanip>
#include "AmaPerishable.h"
#include "Date.h"
using namespace std;
namespace sict{
	AmaPerishable::~AmaPerishable() {}

	const Date & AmaPerishable::expiry() const
	{
		return expiry_;
	}
	void AmaPerishable::expiry(const Date & value)
	{	
		expiry_ = value;
	}
	fstream & AmaPerishable::store(fstream & file, bool addNewLine) const
	{

		AmaProduct::store(file, false);
		
		if (addNewLine)
			file << "," << expiry_ << endl;
		else
			file << "," << expiry_;

		return file;
	}
	fstream & AmaPerishable::load(fstream & file)
	{
		AmaProduct::load(file);
		file.get();
		expiry_.read(file);
		
		return file;
	}
	ostream & AmaPerishable::write(ostream & ostr, bool linear) const
	{
		AmaProduct::write(ostr, linear);

		if (err_.isClear())
		{ 
		if (linear)
			ostr << expiry_;
		else
			ostr << endl << "Expiry date: " << expiry_;
		}
		return ostr;
	}
	istream & AmaPerishable::read(istream & istr)
	{
		Date Datetemp;
		AmaProduct::read(istr);

		if (err_.isClear())
		{
			std::cout << "Expiry date (YYYY/MM/DD): ";
			istr >> Datetemp;

			if (Datetemp.errCode() == 1)
				err_.message("Invalid Date Entry");
			else if (Datetemp.errCode() == 2)
				err_.message("Invalid Year in Date Entry");
			else if (Datetemp.errCode() == 3)
				err_.message("Invalid Month in Date Entry");
			else if (Datetemp.errCode() == 4)
				err_.message("Invalid Day in Date Entry");
		}

		if (err_.isClear())
			expiry(Datetemp);
		else
			istr.setstate(ios::failbit);

		return istr;
	}

}
