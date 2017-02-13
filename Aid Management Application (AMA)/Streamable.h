#ifndef SICT__Streamable_H_
#define SICT__Streamable_H_
#include <iostream>
#include <fstream>
using namespace std;
namespace sict{
  class Streamable{
  public:
    // pure virtual functions go here!
	virtual  fstream& store(fstream& file, bool addNewLine = true)const = 0;
	virtual  fstream& load(std::fstream& file) = 0;
	virtual  ostream& write(ostream& os, bool linear)const = 0;
	virtual  istream& read(istream& is) = 0;
  };
}
#endif