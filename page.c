//
// Created by Jiayi on 2022/3/6.
//

#include "page.h"
#include "user.h"
#include "book_management.h"
#include "librarian.h"
#include <stdio.h>

//main page for all users:
void main_menu()//show_page模块
{
    while (1)
    {
        load_books();
        users_file_to_list();
        printf("Please choose an option\n");
        printf("1)Register an account\n");
        printf("2)Users login\n");
        printf("3)Librarian login\n");
        printf("4)Display all books\n");
        printf("5)Search for book\n");
        printf("6)Quit\n");
        printf("  Option:");
        int option; scanf("%d", &option);

        switch (option)
        {
            case 1: user_register();
                break;
            case 2: user_login();
                break;
            case 3: librarian_login();
                break;
            case 4: display_book();
                break;
            case 5: search_book_menu();
                break;
            case 6: return;
            default: printf("Invalid option!\n"); break;
        }
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


