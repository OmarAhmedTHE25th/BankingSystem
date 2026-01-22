//
// Created by DELL on 19/01/2026.
//

#include "userController.hpp"

#include <iostream>
#include <pqxx/pqxx>


void UserController::addUser(long long id,const std::string& email) const {
    try {
        C.prepare("add_user", "CALL addUser($1,$2)");
        pqxx::work W(C);
         W.exec_prepared("add_user", id,email);
        W.commit();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

}

void UserController::viewUsers() const {
    try {

        pqxx::work W(C);
        const pqxx::result R = W.exec("SELECT * FROM Users");
        for (auto const &row : R) {
            // Access columns by name and print them
            std::cout << "ID: " << row["id"].c_str() << ", ";
            std::cout << "Email: " << row["email"].c_str() << std::endl;
        }
    } catch (std::exception &e) {
        std::cerr << e.what()<<std::endl;
    }
}

void UserController::removeUser(long long id) const {
    try {
        C.prepare("remove_user"," DELETE FROM users WHERE id = ($1)");
        pqxx::work W(C);
        W.exec_prepared("remove_user",id);
        W.commit();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

}

void UserController::updateUser(int old_id, std::optional<int> new_id, const std::optional<std::string>& new_email) const {
    try {
        C.prepare("update_user","CALL updateUser($1,$2,$3)");
        pqxx::work W(C);
        W.exec_prepared("update_user",old_id,new_id,new_email);
        W.commit();
    }catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}
