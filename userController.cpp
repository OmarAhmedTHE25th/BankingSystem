//
// Created by DELL on 19/01/2026.
//

#include "userController.hpp"

#include <iostream>
#include <pqxx/pqxx>

pqxx::connection UserController::connect() {
    pqxx::connection C(
           "host=ep-gentle-frost-ah8aaayp-pooler.c-3.us-east-1.aws.neon.tech "
           "port=5432 "
           "dbname=neondb "
           "user=neondb_owner "
           "password=npg_teqvF1lVGu0d "
           "sslmode=require"
       );
    return C;
}

void UserController::addUser(long long id,const std::string& email) {
    try {
       pqxx::connection C = connect();
        C.prepare("add_user", "CALL addUser($1,$2)");
        pqxx::work W(C);
         W.exec_prepared("add_user", id,email);
        W.commit();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

}

void UserController::viewUsers() {
    try {
        pqxx::connection C = connect();
        pqxx::work W(C);
        const pqxx::result R = W.exec("SELECT * FROM Users");
        for (auto const &row : R) {
            // Access columns by name and print them
            std::cout << "ID: " << row["id"].c_str() << ", ";
            std::cout << "Email: " << row["email"].c_str() << std::endl; // Use appropriate type conversion
        }
    } catch (std::exception &e) {
        std::cerr << e.what()<<std::endl;
    }
}

void UserController::removeUser(long long id) {
    try {
        pqxx::connection C=connect();
        C.prepare("remove_user"," DELETE FROM users WHERE id = ($1)");
        pqxx::work W(C);
        W.exec_prepared("remove_user",id);
        W.commit();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

}

void UserController::updateUser(int old_id, std::optional<int> new_id, const std::optional<std::string>& new_email) {
    try {
        pqxx::connection C = connect();
        C.prepare("update_user","CALL updateUser($1,$2,$3)");
        pqxx::work W(C);
        W.exec_prepared("update_user",old_id,new_id,new_email);
        W.commit();
    }catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}
