#include <iostream>
#include "userController.hpp"
#include <pqxx/pqxx>
int main() {
    pqxx::connection Conn(
           "host=ep-gentle-frost-ah8aaayp-pooler.c-3.us-east-1.aws.neon.tech "
           "port=5432 "
           "dbname=neondb "
           "user=neondb_owner "
           "password=npg_teqvF1lVGu0d "
           "sslmode=require"
       );
    UserController uc(Conn);
    uc.updateUser(1,std::nullopt,"my.cool.email@gmail.com");
    uc.updateUser(45,2,"my_other.cool.email@yahoo.com");
    uc.viewUsers();
    return 0;
}