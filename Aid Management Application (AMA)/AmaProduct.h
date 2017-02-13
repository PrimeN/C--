#ifndef SICT_AMAPRODUCT_H__
#define SICT_AMAPRODUCT_H__
#include <iostream> 
#include "Product.h"
#include "ErrorMessage.h"
using namespace std;
namespace sict{
  class AmaProduct : public Product{
  private:
	  char fileTag_;
	  char unit_[11];
  protected:
	  ErrorMessage err_;
  public:
	  AmaProduct(char FileTag = 'N');
	  const char* unit()const;
	  void unit(const char* value);
	 virtual fstream& store(fstream& file, bool addNewLine = true)const;
	 virtual fstream& load(fstream& file);
	 virtual ostream& write(ostream& os, bool linear)const;
	 virtual istream& read(istream& istr);

	  
  };
}
#endif


