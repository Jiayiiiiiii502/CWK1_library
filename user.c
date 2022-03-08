//
// Created by Jiayi on 2022/3/6.
//

#include "user.h"
#include "page.h"
#include <stdio.h>

void page_user(){
    int choice;
    printf("(Logged in as: Sam)\n");
    printf("Please choose an option:\n");
    printf("1) Borrow a book\n");
    printf("2) Return a book\n");
    printf("3) Search for books\n");
    printf("4) Display all books\n");
    printf("5) Quit\n");
    scanf("%d",&choice);
    if(choice>=1 && choice<=5){
        switch(choice){
            case 1:borrow_book();
                break;
            case 2:return_book();
                break;
            case 3:search_book();
                break;
            case 4:display_all();
                break;
            case 5:return;
            default:printf("Sorry, the option you entered was invalid, please try again.");
        }
    }
    else{
        printf("Sorry, the option you entered was invalid, please try again.");

    }
}

//用户注册账号
void regist(){
    char name[];
    char password[];
    printf("Please enter your username: ");
    scanf("%s",name);
    printf("Please enter your password: ");
    scanf("%s",password);
}


//用户登录
void login(){
    char name[];
    char password[];
    printf("Please enter your username: ");
    scanf("%s",name);
    printf("Please enter your password: ");
    scanf("%s",password);
}


//borrow book
void borrow_book(){

}


//return book
void return_book(){

}
