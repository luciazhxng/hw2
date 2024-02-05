#include "clothing.h"
#include "util.h"
#include <iostream>
#include <string>


using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand) : Product(category, name, price, qty) {
  size_ = size;
  brand_ = brand;
}

Clothing::~Clothing(){
  
}

std::set<std::string> Clothing::keywords() const {
  set<string> ret_val;
  set<string> temp = parseStringToWords(name_);

  set<string>::iterator it;
  string add = ""; 
  string temp_word;
  for(it = temp.begin() ; it != temp.end(); ++it){
    temp_word = *it;
    ret_val.insert(convToLower(temp_word));
  }

  temp = parseStringToWords(brand_);
  for(it = temp.begin() ; it != temp.end(); ++it){
    temp_word = *it;
    ret_val.insert(convToLower(temp_word));
  }

  return ret_val;
}
std::string Clothing::displayString() const {
  string ret_val = name_ + "\n" + "Size: " + size_ + " Brand: " + brand_ + "\n" + to_string(price_) + " " + to_string(qty_) + " left.";
  return ret_val;
}
void Clothing::dump(ostream& os) const {
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << size_ << "\n" << brand_ << endl;
}

