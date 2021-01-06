#include "admin_ui.h"

AdminUI::AdminUI(ShoppingDB &db, std::ostream& os): UI(db, os) { }

void AdminUI::add_product(std::string name, int price) {
    // TODO: For problem 1-1
    if (price>0){
        get_os()<<"ADMIN_UI: "+name+" is added to the database.\n";
        Product* pr=new Product(name, price);
        db.set_product(pr);
        }
    else{
        get_os()<<"ADMIN_UI: Invalid price.\n";
    }


}

void AdminUI::edit_product(std::string name, int price) {
    // TODO: For problem 1-1
std::vector<Product*> pr=db.get_product();
bool exist=false;
std::vector<Product*>::iterator it;
int i=0;
int place=0;
for (it=pr.begin(); it!=pr.end();it++){
    if (pr.at(i)->name==name){
        exist=true;
        place=i;
        break;
    }
    i++;
}
if (!exist){
    get_os()<<"ADMIN_UI: Invalid product name.\n";
    return;
}
    if (price<=0){
    get_os()<<"ADMIN_UI: Invalid price.\n";
}
    else{
        get_os()<<"ADMIN_UI: "+name+" is modified from the database.\n";
        db.modify(place, new Product(name, price));
    }

}

void AdminUI::list_products() {
    // TODO: For problem 1-1
std::vector<Product*> pr=db.get_product();
std::vector<Product*>::iterator it;
if (pr.size()==0){
    get_os()<<"ADMIN_UI: Products: []\n";
    return;
}
else{
    int i=0;
    get_os()<<"ADMIN_UI: Products: [";
    for (it=pr.begin();it!=pr.end(); it++){
        if (i==0){
            get_os()<<"("<<pr.at(i)->name<<", "<<pr.at(i)->price<<")";
        }
        else{
        get_os()<<", ("<<pr.at(i)->name<<", "<<pr.at(i)->price<<")";
        }
        i++;
    }
    get_os()<<"]\n";
}
}
