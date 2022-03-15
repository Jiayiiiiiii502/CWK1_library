//
// Created by Jiayi on 2022/3/6.
//

#ifndef CW1_LIBRARY_LIBRARIAN_H
#define CW1_LIBRARY_LIBRARIAN_H


//管理员信息初始化：
void admin_initial();
User* librarian_info();

//管理员登录：
void librarian_login();

//图书管理员操作：
void add_book();
void remove_book();

void query_user();
void all_history();
void user_change(User*);
int delete_user(User*);
void history(User*);

#endif //CW1_LIBRARY_LIBRARIAN_H
