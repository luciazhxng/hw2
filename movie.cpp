#include "movie.h"
#include "util.h"
#include <iostream>
#include <string>


using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating) : Product(category, name, price, qty) {
  genre_ = genre;
  rating_ = rating;
}
Movie::~Movie(){
  
}

std::set<std::string> Movie::keywords() const {
  set<string> ret_val;
  set<string> temp = parseStringToWords(name_);

  set<string>::iterator it;
  string add = ""; 
  string temp_word;
  for(it = temp.begin() ; it != temp.end(); ++it){
    temp_word = *it;
    ret_val.insert(convToLower(temp_word));
  }

  
  for(unsigned i = 0; i < genre_.length(); i++) {
    add += tolower(genre_[i]); 
  }
  ret_val.insert(add);
  return ret_val;
}
std::string Movie::displayString() const {
  string ret_val = name_ + "\n" + "Genre: " + genre_ + " Rating: " + rating_ + "\n" + to_string(price_) + " " + to_string(qty_) + " left.";
  return ret_val;
}
void Movie::dump(ostream& os) const {
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << endl;
}

