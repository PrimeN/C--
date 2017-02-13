#ifndef SICT__Product_H_
#define SICT__Product_H_
#include <iostream>
#include <fstream>
#include "Streamable.h"
#include "general.h"

using namespace std;
namespace sict {
	class Product : public Streamable {
	public:
		Product();
		virtual ~Product();
		Product(const char* SKU,const char* Name, bool Taxed = true, double Price = 0, int QtyNeeded = 0);
		Product& operator=(const Product& SentL);
		bool operator==(const char *);
		int operator+=(const int SentL);
		int operator-=(const int SentL);
		Product(const Product& SentL);
		const char* sku() const { return sku_; }
		char* name() const { return name_; }
		double price() const { return price_; }
		bool taxed() const { return taxed_; }
		int quantity() const { return quantity_; }
		int qtyNeeded() const { return qtyNeeded_; }
		double cost() const;
		bool isEmpty() const;
		void sku(const char* sku);
		void name(const char* Name);
		void price(double Price);
		void taxed(bool Taxed);
		void quantity(int Quantity);
		void qtyNeeded(int QtyNeeded);


	private:
		char sku_[MAX_SKU_LEN + 1];
		char * name_;
		double price_;
		bool taxed_;
		int quantity_;
		int qtyNeeded_;
	};

	double operator+=(double& SentR, const Product& SentO);
	ostream &operator << (ostream &output, const Product &SentL);
	istream &operator >> (istream &output, Product &SentL);


}
#endif