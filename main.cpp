#include <iostream>
#include "userController.hpp"
#include <pqxx/pqxx>
#include <cstdlib>
auto getEnv = [](const char* key) -> std::string {
    const char* val = std::getenv(key);
    if (!val) {
        throw std::runtime_error(std::string("Missing env var: ") + key);
    }
    return {val};
};

int main() {
    try {
        const std::string host  = getEnv("DB_HOST");
        const std::string port  = getEnv("DB_PORT");
        const std::string db    = getEnv("DB_NAME");
        const std::string user  = getEnv("DB_USER");
        const std::string pass  = getEnv("DB_PASS");

        pqxx::connection Conn(
            "host=" + host +
            " port=" + port +
            " dbname=" + db +
            " user=" + user +
            " password=" + pass +
            " sslmode=require"
        );
        const UserController uc(Conn);
        uc.updateUser(1,std::nullopt,"my.cool.email@gmail.com");
        uc.updateUser(45,2,"my_other.cool.email@yahoo.com");
        uc.viewUsers();

    }
    catch (const std::exception& e) {
        std::cerr << "CONFIG ERROR: " << e.what() << "\n";
    }


    return 0;
}