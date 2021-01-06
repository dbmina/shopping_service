#ifndef PROBLEM1_USER_H
#define PROBLEM1_USER_H

#include <string>
#include <vector>
#include "product.h"

class User {
public:
    User(std::string name, std::string password);
    const std::string name;
    std::string get_pass();
    std::vector<Product*> cart;
    std::vector<Product*> purchase;
    bool premium;
    void add_to_cart(Product*);
    int common;
    int place;
    static bool compare(User* a, User* b);
    int id;
    static int num;
private:
    std::string password;
};

class NormalUser : public User {
public:
    NormalUser( std::string name, std::string password);


};

class PremiumUser : public User {
public:
    PremiumUser(std::string name, std::string password);
};

#endif //PROBLEM1_USER_H
