#include <iostream>
#include "userController.hpp"

int main() {
    UserController uc;
    uc.addUser(123456789,"mycoolemail@gmail.com");
    uc.viewUsers();

    return 0;
}