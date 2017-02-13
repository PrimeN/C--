#ifndef SICT_AMAPERISHABLE_H__
#define SICT_AMAPERISHABLE_H__
#include <iostream> 
#include "Product.h"
#include "ErrorMessage.h"
#include "AmaProduct.h"
#include "Date.h"
using namespace std;

namespace sict{
  class AmaPerishable:public AmaProduct{
  private:
	  Date expiry_;
  public:
	 AmaPerishable(char fileTag = 'P') :AmaProduct(fileTag) {}
	  //AmaPerishable() : AmaProduct('P') {}
	  const Date& expiry()const;
	  void expiry(const Date &value);
	  fstream& store(fstream& file, bool addNewLine = true)const;
	  fstream& load(fstream& file);
	  ostream& write(ostream& ostr, bool linear)const;
	  istream& read(istream& istr);
	  ~AmaPerishable();
  };
}
#endif
