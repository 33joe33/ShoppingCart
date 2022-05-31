cmake_minimum_required(VERSION 3.22)
project(ShoppingCart)

set(CMAKE_CXX_STANDARD 14)

add_executable(ShoppingCart
        main.cpp
        Elements.cpp
        Cart.cpp
        Menu.cpp Cart.h)
