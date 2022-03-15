cmake_minimum_required(VERSION 3.21)
project(cw1_library)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(cw1_library
        book_management.c
        book_management.h
        librarian.c
        librarian.h
        main.c
        page.c
        page.h
        user.c
        user.h
        Search.c Search.h add_function.c add_function.h)