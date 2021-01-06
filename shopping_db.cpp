#include "shopping_db.h"

ShoppingDB::ShoppingDB() {



}

std::vector<Product*> ShoppingDB::get_product(){
    return products;
};

void ShoppingDB::set_product(Product* pr){
    products.push_back(pr);
};
void ShoppingDB::modify(int place, Product* n_pr){
    products.at(place)->price=n_pr->price;
};

void ShoppingDB::signup(User* us){
    std::vector<User*>::iterator it;
    bool exist=false;
    int i=0;
    for(it=users.begin(); it!=users.end(); it++){
        if (users.at(i)->name==us->name){
            exist=true;
            break;
        }
    }
    if(!exist){
        users.push_back(us);
    }

}

std::vector<User*> ShoppingDB::get_user(){
 return users;
}
