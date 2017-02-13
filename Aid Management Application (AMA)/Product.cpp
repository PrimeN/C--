#include <iostream>
#include <cstring>
#include <string>
#include "Product.h"
#include "general.h"
using namespace std;
namespace sict {

	sict::Product::Product()
	{
		sku_[0] = '\0';
		name_ = nullptr;
		price_ = 0;
		taxed_ = 0;
		quantity_ = 0;
		qtyNeeded_ = 0;
	}

	Product::~Product() {
		delete name_;
		name_ = nullptr;
	}

	sict::Product::Product(const char* SKU, const char* Name, bool Taxed, double Price, int QtyNeeded)
	{
		strncpy(sku_, SKU, MAX_SKU_LEN);
		sku_[MAX_SKU_LEN + 1] = '\0';

		char* TemP = nullptr;
		TemP = new char[strlen(Name) +1];
		name_ = TemP;

		for (int counter = 0; counter < (strlen(Name) + 1); counter++)
			name_[counter] = Name[counter];

		quantity_ = 0;
		price_ = Price;
		taxed_ = Taxed;
		qtyNeeded_ = QtyNeeded;


	}

	Product & Product::operator=(const Product & SentL)
	{
		if (this != &SentL) {
			sku(SentL.sku_);
			name(SentL.name_);
			price(SentL.price_);
			taxed(SentL.taxed_);
			quantity(SentL.quantity_);
			qtyNeeded(SentL.qtyNeeded_);
		}
		return *this;
	}

	bool Product::operator==(const char * SentL)
	{
		return (!strcmp(sku_, SentL));
	}

	int Product::operator+=(const int SentL)
	{
		quantity_ = quantity_ + SentL;
		return quantity_;
	}

	int Product::operator-=(const int SentL)
	{
		quantity_ = quantity_ - SentL;
		return quantity_;
	}


	Product::Product(const Product& SentL)
	{

		if (this != &SentL) {
			name_ = nullptr;
			sku(SentL.sku_);
			name(SentL.name_);
			price(SentL.price_);
			taxed(SentL.taxed_);
			quantity(SentL.quantity_);
			qtyNeeded(SentL.qtyNeeded_);
		}
	}

	double Product::cost() const
	{

		if (taxed_)
			return (price_ * (1 + TAX));
		else
			return price_;
	}

	bool Product::isEmpty() const
	{
		if (sku_[0] == '\0' && name_ == nullptr && price_ == 0 && taxed_ == 0 && quantity_ == 0 && qtyNeeded_ == 0)
			return true;

		else
			return false;
	}

	void Product::sku(const char* Sku)
	{
		strncpy(sku_, Sku, MAX_SKU_LEN);
		sku_[MAX_SKU_LEN + 1] = '\0';
	}

	void Product::name(const char* Name)
	{
		
		if (name_ != nullptr)
		{
		//	delete[] name_;
			name_ = nullptr;
		}
		if (Name != nullptr)
		{ 
		name_ = new char[strlen(Name) + 1];
		for (int counter = 0; counter < (strlen(Name) + 1); counter++)
			name_[counter] = Name[counter];
		}
	}

	void Product::price(double Price)
	{		
		price_ = Price;
	}

	void Product::taxed(bool Taxed)
	{
		taxed_ = Taxed;
	}

	void Product::quantity(int Quantity)
	{
		quantity_ = Quantity;
	}

	void Product::qtyNeeded(int QtyNeeded)
	{
		qtyNeeded_ = QtyNeeded;
	}
	double operator+=(double& SentR, const Product& SentO)
	{
		SentR = SentR + (SentO.cost() * SentO.quantity());
		return SentR;
	}
	ostream & operator<<(ostream & output, const Product & SentL)
	{
		return SentL.write(output, true);
	}
	istream & operator>>(istream & input, Product & SentL)
	{
		return	SentL.read(input);
	}
}
