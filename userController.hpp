//
// Created by DELL on 19/01/2026.
//

#ifndef BANKINGSYSTEM_USERCONTROLLER_HPP
#define BANKINGSYSTEM_USERCONTROLLER_HPP
#include <string>
#include <pqxx/pqxx>

class UserController {

    static pqxx::connection connect();
public:
    static  void addUser(long long id,const std::string& email);

    static void viewUsers();
    static void removeUser(long long id);
    static void updateUser(int old_id, std::optional<int> new_id = std::nullopt,
                const std::optional<std::string>& new_email = std::nullopt);

};


#endif //BANKINGSYSTEM_USERCONTROLLER_HPP