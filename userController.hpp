//
// Created by DELL on 19/01/2026.
//

#ifndef BANKINGSYSTEM_USERCONTROLLER_HPP
#define BANKINGSYSTEM_USERCONTROLLER_HPP
#include <string>
#include <pqxx/pqxx>

class UserController {
    pqxx::connection& C;
public:
    explicit UserController(pqxx::connection& connection):C(connection){};
      void addUser(long long id,const std::string& email) const;
     void viewUsers() const;
     void removeUser(long long id) const;
     void updateUser(int old_id, std::optional<int> new_id = std::nullopt,
         const std::optional<std::string>& new_email = std::nullopt) const;


};


#endif //BANKINGSYSTEM_USERCONTROLLER_HPP