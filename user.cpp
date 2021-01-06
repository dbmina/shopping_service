#include <algorithm>
#include "user.h"

User::User(std::string name, std::string password): name(name), password(password) {

}
std::string User::get_pass(){
    return password;
}


bool User:: compare(User* a, User* b){
    if (a->common==b->common){
        return ((a->id)<(b->id));
    }
    return ((a->common)>(b->common));
}
NormalUser::NormalUser(std::string name, std::string password) :
User(name, password) {

}
PremiumUser::PremiumUser(std::string name, std::string password) :
        User(name, password) {

}