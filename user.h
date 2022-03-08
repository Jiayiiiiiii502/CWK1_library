//
// Created by Jiayi on 2022/3/6.
//

#ifndef CW1_LIBRARY_USER_H
#define CW1_LIBRARY_USER_H
void registration();
void login();
void page_user();
void borrow_book();
void return_book();
void create_user_info();


//定义用户结构体
typedef struct Users_info{
    char username[15];
    char password[20];
}users;




#endif //CW1_LIBRARY_USER_H
