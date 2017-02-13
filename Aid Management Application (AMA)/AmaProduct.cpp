#include "AmaProduct.h"
#include "ErrorMessage.h"
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;
namespace sict{
	AmaProduct::AmaProduct(char FileTag)
	{
		if (FileTag != '\0')
		fileTag_ = FileTag;
	}
	const char * AmaProduct::unit() const
	{
		return unit_;
	}
	void AmaProduct::unit(const char * value)
	{
		strncpy(unit_, value, 10);
		unit_[11] = '\0';
	}
	fstream & AmaProduct::store(fstream & file, bool addNewLine) const
	{
		if (file.is_open()) {
			file << fileTag_ << "," << sku() << "," << name() << "," << price() << "," << taxed() << "," << quantity() << "," << unit_ << "," << qtyNeeded();

			if (addNewLine)
				file << endl;
		}
		return file;
	}
	fstream & AmaProduct::load(fstream & file)
	{
		char sku[MAX_SKU_LEN + 1];
		char name[50];
		double price;
		bool taxed;
		int quantity, qtyNeeded;

			file.seekp(0);
			file.get();
			file.get();
			file.getline(sku, 30, ',');
			file.getline(name, 30, ',');
			file >> price;
			file.get();
			file >> taxed;
			file.get();
			file >> quantity;
			file.get();
			file.getline(unit_, 100, ',');
			file >> qtyNeeded;

			Product::sku(sku);
			Product::name(name);
			Product::price(price);
			Product::taxed(taxed);
			Product::quantity(quantity);
			Product::qtyNeeded(qtyNeeded);
		
		return file;
	}
	ostream & AmaProduct::write(ostream & os, bool linear) const
	{
		if (!err_.isClear()){
			os << err_;
		}
		else {
			if (linear) {
				os << setw(MAX_SKU_LEN) << left << sku() << "|"
					<< setw(20) << left << name() << "|"
					<< setw(7) << right << fixed << setprecision(2) << cost() << "|"
					<< setw(4) << right << quantity() << "|"
					<< setw(10) << left << unit_ << "|"
					<< setw(4) << right << qtyNeeded() << "|";
			}
			else {
				os << "Sku: " << sku() << endl
					<< "Name: " << name() << endl
					<< "Price: " << price() << endl
					<< "Price after tax: ";

				if (taxed())
					os << cost();
				else
					os << "N/A";

				os << endl << "Quantity On Hand: " << quantity() << " " << unit_ << endl << "Quantity Needed: " << qtyNeeded();
			}
		}
		return os;
	}
	istream & AmaProduct::read(istream & istr)
	{
		char sku[MAX_SKU_LEN + 1], name[50], taxed;
		double price;
		int quantity, qtyNeeded;
		bool ValiD = true;
		err_.clear();

		cout << "Sku: ";
		istr >> sku;
		cout << "Name: ";
		istr >> name;
		cout << "Unit: ";
		istr >> unit_;
		cout << "Taxed? (y/n): ";
		istr.get();
		istr.get(taxed);

		if (taxed == 'Y' || taxed == 'y')
			Product::taxed(true);
		else if (taxed == 'N' || taxed == 'n')
			Product::taxed(false);
		else
		{
			err_.message("Only (Y)es or (N)o are acceptable");
			istr.setstate(ios::failbit);
			ValiD = 0;
		}	

		if (ValiD)
		{
			cout << "Price: ";
			cin >> price;
			if (cin.fail())
			{ 
			istr.setstate(ios::failbit);
			ValiD = 0;
			err_.message("Invalid Price Entry");
			}
		}

		if (ValiD)
		{
			cout << "Quantity On hand: ";
			cin >> quantity;
			if (cin.fail())
			{
				istr.setstate(ios::failbit);
				ValiD = 0;
				err_.message("Invalid Quantity Entry");
			}
		}

		if (ValiD)
		{
			cout << "Quantity Needed: ";
			cin >> qtyNeeded;
			if (cin.fail())
			{
				istr.setstate(ios::failbit);
				ValiD = 0;
				err_.message("Invalid Quantity Needed Entry");
			}
		}

		if (ValiD)
		{
			Product::sku(sku);
			Product::name(name);
			Product::price(price);
			Product::quantity(quantity);
			Product::qtyNeeded(qtyNeeded);
		}
		return istr;
	}
}