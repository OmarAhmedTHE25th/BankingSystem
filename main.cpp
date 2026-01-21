#include <iostream>
#include "userController.hpp"

int main() {
 UserController::updateUser(1,std::nullopt,"my.cool.email@gmail.com");
    UserController::updateUser(45,2,"my_other.cool.email@yahoo.com");
UserController::viewUsers();
    return 0;
}