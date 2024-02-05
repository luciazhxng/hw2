#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <deque>
#include "book.h"
#include "movie.h"
#include "clothing.h"
#include "datastore.h"
#include "product.h"
#include "util.h"

class MyDataStore : public DataStore {
  public:
    MyDataStore();
    ~MyDataStore();
    void addProduct(Product* p);
    void addUser(User* u);
    std::vector<Product*> search(std::vector<std::string>& terms, int type);
    void dump(std::ostream& ofile);
    void addToCart(std::string username, int hit_index, std::vector<Product*> hits);
    void viewCart(std::string username);
    void buyCart(std::string username);

  private:
    std::vector<User*> users;
    std::map<std::string, std::deque<Product*>> user_carts;
    std::vector<Product*> products;
    std::map<std::string, std::set<std::string>> product_keywords;
    std::map<std::string, std::set<Product*>> keyword_products;
};
