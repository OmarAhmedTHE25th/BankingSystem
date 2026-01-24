cmake_minimum_required(VERSION 3.29.7)
project(BankingSystem)

set(CMAKE_CXX_STANDARD 20)

add_executable(BankingSystem main.cpp
        userController.cpp
        userController.hpp
        bankAccountController.cpp
        bankAccountController.hpp)

# vcpkg installed target
find_package(libpqxx CONFIG REQUIRED)
target_link_libraries(BankingSystem PRIVATE libpqxx::pqxx)
