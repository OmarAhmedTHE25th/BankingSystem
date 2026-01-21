//
// Created by DELL on 19/01/2026.
//

#ifndef BANKINGSYSTEM_USERCONTROLLER_HPP
#define BANKINGSYSTEM_USERCONTROLLER_HPP
#include <string>


class UserController {
public:
    static  void addUser(long long id,std::string email);

    static void viewUsers();

};


#endif //BANKINGSYSTEM_USERCONTROLLER_HPP