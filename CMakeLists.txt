cmake_minimum_required(VERSION 3.22)
project(ShoppingCart)

set(CMAKE_CXX_STANDARD 14)

add_executable(ShoppingCart
        main.cpp
        Elements.cpp Elements.h
        Cart.cpp Cart.h
        Menu.cpp Menu.h
        sqlite3.c
        sqlite3.h
        sqlite3ext.h
        data.cpp data.h)


