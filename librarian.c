//
// Created by Jiayi on 2022/3/6.
//

#include "librarian.h"
#include "page.h"
#include<stdio.h>
void page_librarian(){
    int choice;
    printf("(Logged in as: librarian)\n");
    printf("Please choose an option:\n");
    printf("1) Add a book\n");
    printf("2) Remove a book\n");
    printf("3) Search for books\n");
    printf("4) Display all books\n");
    printf("5) Quit\n");
    scanf("%d",&choice);
    if(choice>=1 && choice<=5){
        switch(choice){
            case 1:add_book();
                break;
            case 2:remove_book();
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


void add_book(){

}


void remove_book(){

}