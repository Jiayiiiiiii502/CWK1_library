//
// Created by Jiayi on 2022/3/6.
//

#include "page.h"
#include "librarian.h"
#include "user.h"
#include "book_management.h"
#include <stdio.h>

//main page for all users:
void page_browser(){
    int choice;
    float c;
    printf("Please choose an option:\n");
    printf("1) Register an account\n");
    printf("2) Login\n");
    printf("3) Search for books\n");
    printf("4) Display all books\n");
    printf("5) Quit\n");
    scanf("%d",&choice);
    if(choice>=1 && choice<=5){
        switch(choice){
            case 1:regist();
            break;
            case 2:login();
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



void search_book(){
    printf("1) Find books by title\n");
    printf("2) Find books by author\n");
    printf("3) Find books by year\n");
    printf("4) Return to previous menu\n");
    int choice;
    if(choice>=1 && choice<=4){
        switch(choice){
            case 1:
                find_book_by_title(); break;
            case 2:
                find_book_by_author(); break;
            case 3:
                find_book_by_year(); break;
            default:printf("Sorry, the option you entered was invalid, please try again.");

        }
    }
    else{
        printf("Sorry, the option you entered was invalid, please try again.");
    }
}

void display_all(){

}


