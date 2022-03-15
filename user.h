//
// Created by Jiayi on 2022/3/6.
//

#ifndef CW1_LIBRARY_USER_H
#define CW1_LIBRARY_USER_H
#include "page.h"
#include "librarian.h"
#include "book_management.h"

void page_user();
void registration();
//user链表
void create_user_info(char*,char*);
void user_initial(users*);
void login();


void user_menu(users*);


//定义用户结构体

struct borrowed{//原名字为node
    int borrow_num,max_borrowed;
    Book borrow_books[10];
};


typedef struct user{//原名字为user
    char name[20];
    char username[20];
    char password[20];
    int librarian;
    struct borrowed user_borrowed_books;
    struct user* next;
}User;//原名字为User
//user链表头节点

User* user_head_node;  //user head pointer.  //users* u_head_node
User* admin;  //administrator account
User* librarian;
int user_num;//user_amout

v//用户初始化：
void user_borrow(User*);
int user_num;  //the number of user


//用户注册：
void user_register();

//用户登录：
void user_login();


//找用户名：
User* serch_username(char*);


//用户操作：
void borrow_book(User*);
void return_book(User*);


//用户管理加载：
void store_users();//结构体写入文件
void users_file_to_list();//读取文件到链表
void creat_user_list(char*,char*, char*);


#endif //CW1_LIBRARY_USER_H
