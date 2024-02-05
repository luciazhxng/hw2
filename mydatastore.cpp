#include <iostream>
#include <string>
#include <set>
#include <vector>
#include "mydatastore.h"

using namespace std;

MyDataStore::MyDataStore() {
}

MyDataStore::~MyDataStore() {
  for(unsigned i = 0; i < users.size(); i++) {
    delete users[i];
  }
  for(unsigned i = 0; i < products.size(); i++) {
    delete products[i];
  }
}

void MyDataStore::addProduct(Product* p) {
  products.push_back(p);
  product_keywords[p->getName()] = p->keywords();
  set<string>::iterator it;
  set<string> keywords = p->keywords();
  for(it = keywords.begin(); it != keywords.end(); ++it) {
    keyword_products[*it].insert(p);
  }
}
void MyDataStore::addUser(User* u) {
  users.push_back(u);
  user_carts[convToLower(u->getName())] = deque<Product*>();
}
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) {
  vector<Product*> ret_val;
  set<Product*> temp;
  string keyword;
  set<Product*>::iterator it;   
  if(terms.size() == 1) {
    
    set<Product*> temp_products = keyword_products[terms[0]];
    for(it = temp_products.begin() ; it != temp_products.end(); ++it){
      ret_val.push_back(*it);
    }
    return ret_val;
  }

  if(type == 0) {
    string keyword1 = terms[0];
    string keyword2 = terms[1];
    temp = setIntersection(keyword_products[keyword1], keyword_products[keyword2]);
    for(unsigned i = 2; i < terms.size(); i++) {
      keyword1 = terms[i];
      temp = setIntersection(temp, keyword_products[keyword1]);
    }
    for(it = temp.begin() ; it != temp.end(); ++it){
      ret_val.push_back(*it);
    }
    return ret_val;
  }

   if(type == 1) {
    string keyword1 = terms[0];
    string keyword2 = terms[1];
    temp = setUnion(keyword_products[keyword1], keyword_products[keyword2]);
    for(unsigned i = 2; i < terms.size(); i++) {
      keyword1 = terms[i];
      temp = setUnion(temp, keyword_products[keyword1]);
    }
    for(it = temp.begin() ; it != temp.end(); ++it){
      ret_val.push_back(*it);
    }
    return ret_val;
  }
  return ret_val;


}
void MyDataStore::dump(std::ostream& ofile) {
  ofile << "<products>" << endl;
  for(unsigned i = 0; i < products.size(); i++) {
    products[i]->dump(ofile);
  }
  ofile << "</products>" << endl;
  ofile << "<users>" << endl;
  for(unsigned i = 0; i < users.size(); i++) {
    users[i]->dump(ofile);
  }
  ofile << "</users>" << endl;

}
void MyDataStore::addToCart(std::string username, int hit_index, vector<Product*> hits) {
  if(hit_index > hits.size() || hit_index < 1) {
    cout << "Invalid request" << endl;
    return;
  }
  if(user_carts.find(username) == user_carts.end()) {
    cout << "Invalid request" << endl;
    return;
  }

  Product* add = hits[hit_index - 1];
  user_carts[username].push_front(add);
}
void MyDataStore::viewCart(std::string username) {
  if(user_carts.find(username) == user_carts.end()) {
    cout << "Invalid username" << endl;
    return;
  }
  deque <Product*> cart = user_carts[username];
  Product* temp;
  int j = 1;
  for(int i = cart.size() - 1; i >= 0; i--) {
    temp = cart[i];
    cout << "Item " << j << ":" << endl;
    cout << temp->displayString() << endl;
    cout << endl;
    j++;
  }
}
void MyDataStore::buyCart(std::string username) {
  if(user_carts.find(username) == user_carts.end()) {
    cout << "Invalid username" << endl;
    return;
  }
  User* user;
  for(unsigned i = 0; i < users.size(); i++) {
    if(convToLower(users[i]->getName()) == username) {
      user = users[i];
    }
  }
  deque <Product*> cart_copy = user_carts[username];
  Product* temp;
  for(int i = cart_copy.size() - 1; i >= 0; i--) {
    temp = cart_copy[i];
    if((temp->getQty() > 0) && (temp->getPrice() < user->getBalance())) {
      user_carts[username].erase(user_carts[username].begin() + i);
      temp->subtractQty(1);
      user->deductAmount(temp->getPrice());
    }
  }
}
