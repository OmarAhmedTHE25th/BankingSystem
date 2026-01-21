//
// Created by DELL on 19/01/2026.
//

#include "userController.hpp"

#include <iostream>
#include <pqxx/pqxx>

void UserController::addUser(long long id,std::string email) {
    try {
        pqxx::connection C(
            "host=ep-gentle-frost-ah8aaayp-pooler.c-3.us-east-1.aws.neon.tech "
            "port=5432 "
            "dbname=neondb "
            "user=neondb_owner "
            "password=npg_teqvF1lVGu0d "
            "sslmode=require"
        );
        C.prepare("add_user", "CALL addUser($1,$2)");
        pqxx::work W(C);
         W.exec_prepared("add_user", id,email);
        W.commit();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

}

void UserController::viewUsers() {
    pqxx::connection C(
           "host=ep-gentle-frost-ah8aaayp-pooler.c-3.us-east-1.aws.neon.tech "
           "port=5432 "
           "dbname=neondb "
           "user=neondb_owner "
           "password=npg_teqvF1lVGu0d "
           "sslmode=require"
       );
    pqxx::work W(C);
    for (const pqxx::result R = W.exec("SELECT id FROM Users"); auto row : R) {
        std::cout << row["id"].c_str() << std::endl;
    }
}
