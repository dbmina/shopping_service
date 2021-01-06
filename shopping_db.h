#ifndef PROBLEM1_SHOPPING_DB_H
#define PROBLEM1_SHOPPING_DB_H

#include <string>
#include <vector>
#include "user.h"
#include "product.h"
#include <map>


class ShoppingDB {
public:
    ShoppingDB();

    void set_product(Product* pr);
    std::vector<Product*> get_product();
    void modify(int place, Product* n_pr);

    void signup(User* us);

    std::vector<User*> get_user();
    std::map<User*, bool> login_test;
    std::map<User*, bool> premium_test;
private:

    std::vector<User*> users;
    std::vector<Product*> products;




};

#endif //PROBLEM1_SHOPPING_DB_H
