#include <vector>
#include "client_ui.h"
#include "product.h"
#include "user.h"
#include <map>
#include<cmath>
#include <algorithm>
#include<iostream>
int User::num=0;
ClientUI::ClientUI(ShoppingDB &db, std::ostream& os) : UI(db, os), current_user() {
    current_log=false;
}

ClientUI::~ClientUI() {
    delete current_user;
}

void ClientUI::signup(std::string username, std::string password, bool premium) {
    // TODO: For problem 1-2
    if (premium){
        User* a=new User(username, password);
        a->premium=true;
        a->id=a->num;
        a->num++;
        db.signup(a);
    }
    else{
        User* a=new User(username, password);
        a->premium=false;
        a->id=a->num;
        a->num++;
        db.signup(a);
    }


    get_os()<<"CLIENT_UI: "<<username<<" is signed up.\n";

}

void ClientUI::login(std::string username, std::string password) {
    // TODO: For problem 1-2
    if (current_log==true){
        get_os()<<"CLIENT_UI: Please logout first.\n";
        return;
    }
    std::vector<User*> us=db.get_user();
    std::vector<User*>::iterator userit;

    int i=0;
    for(userit=us.begin();userit!=us.end(); userit++ ){
     if ((us.at(i)->name==username)&& (us.at(i)->get_pass()==password) ){

             current_log=true;
             current_user=us.at(i);
             get_os()<<"CLIENT_UI: "<<username<<" is logged in.\n";

         return;
         }
     i++;
     }


        get_os()<<"CLIENT_UI: Invalid username or password.\n";


}

void ClientUI::logout() {
    // TODO: For problem 1-2

if (!current_log){
    get_os()<<"CLIENT_UI: There is no logged-in user.\n";
}
else{
    get_os()<<"CLIENT_UI: "<<current_user->name<<" is logged out.\n";
    current_log=false;
}


}

void ClientUI::add_to_cart(std::string product_name) {
    // TODO: For problem 1-2
    if (!current_log){
        get_os()<<"CLIENT_UI: Please login first.\n";
        return;
    }
    std::vector<Product*> pr=db.get_product();
    Product* real_pro;
    std::vector<Product*>::iterator  it;
    bool exist=false;
    int i=0;
    for(it=pr.begin(); it!=pr.end(); it++){
        if (pr.at(i)->name==product_name){
            exist=true;
            real_pro=pr.at(i);
            break;
        }
        i++;
    }

    if(!exist){
        get_os()<<"CLIENT_UI: Invalid product name.\n";
        return;
    }

    else{


            current_user->cart.push_back(real_pro);


        get_os()<<"CLIENT_UI: "<<product_name<<" is added to the cart.\n";
    }


}

void ClientUI::list_cart_products() {
    // TODO: For problem 1-2.
    if (!current_log){
        get_os()<<"CLIENT_UI: Please login first.\n";
        return;
    }

    std::vector<Product*> cart=current_user->cart;
    std::vector<Product*>::iterator it;
    get_os()<<"CLIENT_UI: Cart: [";
    int i=0;

    for(it=cart.begin(); it!=cart.end(); it++){
        if (i==0){
                if (cart.size()>=1){
                    if (current_user->premium){
                        get_os()<<"("<<cart.at(i)->name<<", "<<round((cart.at(i)->price)*0.9)<<")";
                    }
                    else{
                        get_os()<<"("<<cart.at(i)->name<<", "<<cart.at(i)->price<<")";
                    }

                }

        }
        else{
            if (current_user->premium){
                get_os()<<", ("<<cart.at(i)->name<<", "<<round((cart.at(i)->price)*0.9)<<")";
            }
            else {
                get_os() << ", (" << cart.at(i)->name << ", " << cart.at(i)->price << ")";
            }
        }
        i++;
    }
    get_os()<<"]\n";

}

void ClientUI::buy_all_in_cart() {
    // TODO: For problem 1-2
    if (!current_log){
        get_os()<<"CLIENT_UI: Please login first.\n";
        return;
    }
int sum=0;
    std::vector<Product*> cart_info=current_user->cart;
    std::vector<Product*>::iterator cartit;
    int i=0;
    for (cartit=cart_info.begin(); cartit!=cart_info.end();cartit++){
        sum+=cart_info.at(i)->price;
        current_user->purchase.insert(current_user->purchase.begin(), cart_info.at(i) );
        i++;
    }
    (current_user->cart).clear();
    if (current_user->premium){
        get_os()<<"CLIENT_UI: Cart purchase completed. Total price: "<<round(sum*0.9)<<".\n";
    }
    else{
        get_os()<<"CLIENT_UI: Cart purchase completed. Total price: "<<sum<<".\n";
    }

}

void ClientUI::buy(std::string product_name) {
    // TODO: For problem 1-2
    if (!current_log){
        get_os()<<"CLIENT_UI: Please login first.\n";
        return;
    }
    std::vector<Product*> pr=db.get_product();

    Product* real_pro;
    std::vector<Product*>::iterator it;

    int i=0;
    bool valid=false;

    for(it=pr.begin();it!=pr.end(); it++){
        if (pr.at(i)->name==product_name){
            real_pro=pr.at(i);
            valid=true;
            break;
        }
        i++;
    }
    if (!valid){
        get_os()<<"CLIENT_UI: Invalid product name.\n";
        return;
    }


       if (current_user->premium){
          get_os()<<"CLIENT_UI: Purchase completed. Price: "<<round((real_pro->price)*0.9)<<".\n";
       }
       else{
           get_os()<<"CLIENT_UI: Purchase completed. Price: "<<real_pro->price<<".\n";

       }
    current_user->purchase.insert(current_user->purchase.begin(),  real_pro);
    }




void ClientUI::recommend_products() {
    // TODO: For problem 1-3.
if (!current_log){
    get_os()<<"CLIENT_UI: Please login first.\n";
    return;
}

    int j=0;
    std::vector<Product*> product;
    std::vector<Product*>::iterator it;
    std::vector<Product*>::iterator it2;
    int ch=0;
    for(it=current_user->purchase.begin(); it!=current_user->purchase.end(); it++){
        bool ex=false;
        int in=0;
        for(it2=product.begin(); it2!=product.end(); it2++){
            if ((product.at(in)->name)==((current_user->purchase).at(ch)->name)){
                ex=true;
                break;
            }
            in++;
        }
        if (!ex){
            product.push_back(current_user->purchase.at(ch));
        }
        ch++;
    }

    if (!(current_user->premium)){
             int i=0;
             get_os()<<"CLIENT_UI: Recommended products: [";
             for(it=product.begin(); it!=product.end(); it++){
                 if (i==0){
                     if (product.size()>=1)
                     get_os()<<"("<<product.at(i)->name<<", "<<product.at(i)->price<<")";
                 }
                 else{
                     if (product.size()>=(i+1))
                     get_os()<<", ("<<product.at(i)->name<<", "<<product.at(i)->price<<")";
                 }
                 i++;
                 if(i>=3){
                     break;
                 }
             }
         get_os()<<"]\n";
    }
    else{
        std::vector<User*> user=db.get_user();
        std::vector<User*> sorteduser;
        std::vector<User*>::iterator user_it;
        std::vector<Product*>::iterator pro;
        std::vector<Product*>::iterator pro2;
        int i=0;
        for(user_it=user.begin(); user_it!=user.end(); user_it++){
            std::vector<Product*> result;
            if (user.at(i)==current_user){
                i++;
                current_user->common=-1;
                continue;
            }

int a=0;
           std::vector<Product*> st2=user.at(i)->purchase;

            int s=0;
            for(pro=product.begin(); pro!=product.end(); pro++){
            int b=0;

                for(pro2=st2.begin(); pro2!=st2.end(); pro2++){
                    if (st2.at(b)->name==product.at(a)->name){
                        s++;
                        break;
                    }
                    b++;
                }

                a++;
            }
            user.at(i)->common=s;

i++;
        }

        std::vector<Product*> final_result;

        std::vector<User*> tmp_user=user;
        std::vector<User*> ::iterator it;
        std::vector<Product*> ::iterator pr;
       std::sort(tmp_user.begin(),tmp_user.end(), User::compare);
        int c=0;

       for(it=tmp_user.begin(); it!=tmp_user.end(); it++){

           int x=0;
bool exi=false;
              for (pr=final_result.begin(); pr!=final_result.end(); pr++){
                  if (final_result.at(x)->name==tmp_user.at(c)->purchase.at(0)->name){
                      exi=true;
                      break;
                  }
                  x++;}

                  if((tmp_user.at(c)!=current_user) && !exi){

                      final_result.push_back(new Product(tmp_user.at(c)->purchase.at(0)->name,
                                       std::round((tmp_user.at(c)->purchase.at(0)->price)*0.9)));

                  }


              c++;
       }
       os<<"CLIENT_UI: Recommended products: [";
        for(j=0; j<3; j++){
            if (final_result.size()>=(j+1)){
                if (j==0){

                    os<<"("<<final_result.at(j)->name<<", "<<final_result.at(j)->price<<")";
                }
                else {

                        os<< ", (" << final_result.at(j)->name << ", " << final_result.at(j)->price << ")";
                }
            }

        }
        os<<"]\n";
    }
}
