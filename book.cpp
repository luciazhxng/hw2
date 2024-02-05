#include "book.h"
#include "util.h"
#include <iostream>
#include <string>


using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, const std::string ISBN, const std::string author) : Product(category, name, price, qty) {
  ISBN_ = ISBN;
  author_ = author;
}
Book::~Book(){
  
}

std::set<std::string> Book::keywords() const {
  set<string> ret_val;
  set<string> temp = parseStringToWords(name_);

  set<string>::iterator it;
  string add = ""; 
  string temp_word;
  for(it = temp.begin() ; it != temp.end(); ++it){
    temp_word = *it;  
    ret_val.insert(convToLower(temp_word));
  }

  ret_val.insert(convToLower(ISBN_));

  temp = parseStringToWords(author_);
  for(it = temp.begin() ; it != temp.end(); ++it){
    temp_word = *it;
    ret_val.insert(convToLower(temp_word));
    cout <<"Author: " << temp_word << endl;
  }

  return ret_val;
}
std::string Book::displayString() const {
  string ret_val = name_ + "\n" + "Author: " + author_ + " ISBN: " + ISBN_ + "\n" + to_string(price_) + " " + to_string(qty_) + " left.";
  return ret_val;
}
void Book::dump(ostream& os) const {
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << ISBN_ << "\n" << author_ << endl;
}

