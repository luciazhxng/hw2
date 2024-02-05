#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>

#include "util.h"
#include "book.h"
#include "clothing.h"
#include "movie.h"


using namespace std;

int main() {
  /*
  // TEST UTIL PARSESTRINGTOWORDS
  string words1 = "my name is lucia ss";
  string words2 = "my grade is three'ss";
  set<string> parsed_1 = parseStringToWords(words1);
  set<string> parsed_2 = parseStringToWords(words2);

  // TEST SET INTERSECTION
  cout << "set intersection:" <<endl;
  set<string> ret_val = setIntersection(parsed_1, parsed_2);
  set<string>::iterator it;
  for(it = ret_val.begin() ; it != ret_val.end(); ++it){
    cout << *it << endl; 
  }

  // TEST SET UNION
  cout << "set union:"<<endl;
  ret_val = setUnion(parsed_1, parsed_2);
  for(it = ret_val.begin() ; it != ret_val.end(); ++it){
    cout << *it << endl; 
  }
  */

  Book temp_book("book", "the things they carried", 13.0, 4, "978-000000000-1", "tim o'brien");

  cout <<"book keywords:"<<endl;
  temp_book.keywords();
  set<string> ret_val = temp_book.keywords();
  set<string>::iterator it;
  for(it = ret_val.begin() ; it != ret_val.end(); ++it){
    cout << *it << endl; 
  }
  cout << temp_book.displayString() << endl;

  Clothing temp_clothing("clothing", "t-shirt", 13.0, 4, "medium", "uniqlo");

  cout <<"clothing keywords:"<<endl;
  temp_clothing.keywords();
  ret_val = temp_clothing.keywords();
  for(it = ret_val.begin() ; it != ret_val.end(); ++it){
    cout << *it << endl; 
  }

  cout << temp_clothing.displayString()<<endl;

  Movie temp_movie("movie", "dune", 13.0, 4, "historical fantasy", "4.2");

  cout <<"movie keywords:"<<endl;
  temp_movie.keywords();
  ret_val = temp_movie.keywords();
  for(it = ret_val.begin() ; it != ret_val.end(); ++it){
    cout << *it << endl; 
  }

  cout << temp_movie.displayString()<<endl;

}