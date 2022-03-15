//
// Created by Jiayi on 2022/3/6.
//

#include "librarian.h"
#include "page.h"
#include<stdio.h>
//管理员登陆大板块：
//管理员信息初始化
User* librarian_info()//librariran_login
{
    librarian = (User*)malloc(sizeof(User));
    strcpy(librarian->name,"Librarian");
    strcpy(librarian->user_name, "0000");
    strcpy(librarian->password, "0000");
    return librarian;
}


void librarian_login(){
    User* initial=librarian_info();
    char name[25];
    char username[30];
    char password[30];
    printf("Welcome!\n");
    printf("Please enter your username:\n");
    scanf("%s",username);
    if(strcmp(initial->user_name,username)){
        printf("Invalid librarian username!\n");
        return;
    }
    printf("Please enter your password:\n");
    scanf("%s",password);
    if(strcmp(initial->password,password)){
        printf("Invalid librarian password!\n");
        return;
    }
    printf("Successfully login as librarian!\n");
    librarian_menu();
}

void librarian_menu(){
    printf("Welcome!\n");
    printf("Please enter your choice:\n");
    printf("1)add book\n");
    printf("2)remove book\n");
    printf("3)Search for book\n");
    printf("4)Display book\n");
    printf("5)Quit\n");
    int option;
    scanf("%d",&option);
    switch(option){
        case 1: add_book();
            break;
        case 2: remove_book();
            break;
        case 3: search_book_menu();
            break;
        case 4: display_book();
            break;
        case 5:printf("Librarian has been logged out!\n");
            return;
        default:printf("Invalid choice!\n");
    }
    librarian_menu();
}
