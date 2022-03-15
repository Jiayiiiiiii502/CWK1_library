//
// Created by Jiayi on 2022/3/6.
//

#include "user.h"
#include "page.h"
#include <stdio.h>
#include "Search.h"

//用户登录大板块：

//读取用户信息并将新的用户信息读到temp结构体中
void users_file_to_list()//link_list模块
{
    user_head_node = (User*)malloc(sizeof(User));//user_head_node
    user_head_node->next = NULL;//user_head_node->next=null
    user_num = 0;//user_num

    FILE* fp1;
    fp1 = fopen("new_users.txt", "rb");
    User* np;
    np = user_head_node;
    User* temp = (User*)malloc(sizeof(User));
    while (fread(temp, sizeof(User), 1, fp1))
    {
        np->next = temp;
        user_num++;
        temp = (User*)malloc(sizeof(User));
        np = np->next;
    }
    librarian= user_head_node->next;
    fclose(fp1);
}

void user_borrow(User* borrow)//用户信息初始化  link_list
{
    borrow->user_book.borrow_amount = 0;
    borrow->user_book.max_amount = 10;
    memset(borrow->user_book.borrow_book, 0, sizeof(borrow->user_book.borrow_book));
}

void store_users()//将temp结构体写入用户信息文件中  user_login
{
    FILE* fp = fopen("new_users.txt", "wb");
    User* temp = user_head_node->next;
    while (temp)
    {
        fwrite(temp, sizeof(User), 1, fp);
        temp = temp->next;
    }
    fclose(fp);
}


//case1: user_registration:
void user_register()//账户注册   user_registration
{
    char username[30];
    printf("Please enter your username:\n");
    scanf("%s", username);
    User* account;
    if (account = serch_username(username), account != NULL)
    {
        printf("This username has been already registered!\n");
        printf("Please change your username or login directly!\n");
        return;
    }
    char name[20];
    printf("Please enter your name:\n");
    scanf("%s",name);
    printf("Please input your password(no more than 30 letters or numbers):\n");
    char password[30];
    scanf("%s", password);
    creat_user_list(username,name, password);
    printf("register successfully!\n");
    user_num++;
}

User* serch_username(char* name)  //user_login
{
    User* np = user_head_node->next;
    while (np)
    {
        if (!strcmp(np->user_name, name)) return np;
        np = np->next;
    }
    return NULL;
}


void creat_user_list(char* username, char*name,char* password)//创建用户信息链表，并调用store users函数   link_list
{
    User* np;
    np = user_head_node;
    while (np->next) np = np->next;
    User* tp = (User*)malloc(sizeof(User));
    strcpy(tp->user_name, username);
    strcpy(tp->name,name);
    strcpy(tp->password, password);
    tp->admin = 0;
    tp->next = NULL;
    user_borrow(tp);
    np->next = tp;
    store_users();
}

//用户登录:
void user_login()//用户登录
{
    char username[25];
    char password[25];
    printf("Please enter your username:\n");
    scanf("%s", username);
    User* temp;
    if (temp = serch_username(username), temp == NULL)
    {
        printf("Invalid username!\n");
        printf("Please registrate first!\n");
        return;
    }
    printf("Please enter your password:\n");
    scanf("%s", password);
    if (strcmp(temp->password, password))
    {
        printf("Invalid password!\n");
        printf("Please try again!");
        return;
    }
    printf("Login successfully!...\n");
    user_menu(temp);
}

//用户操作主页
void user_menu(User* account)  //show_page
{
    while (1)
    {
        printf("+--------------------------------------------------------------+\n");
        printf("user:%s\n", account->user_name);
        printf("input your option\n");
        printf("1)borrow book\n");
        printf("2)return book\n");
        printf("3)my borrow\n");
        printf("4)display book\n");
        printf("5)change password\n");
        //printf("6)remove account\n");
        printf("0)log out\n");
        printf("+--------------------------------------------------------------+\n");
        int op; scanf("%d", &op);
        switch (op)
        {
            case 1: //borrow_book(account);
                printf("Borrow book!\n");
                break;
            case 2: //return_book(account);
                printf("Borrow book!\n");
                break;
            case 3: //history(account);
                printf("Borrow book!\n");
                break;
            case 4: //display_book();
                printf("Borrow book!\n");
                break;
            case 5: //user_change(account);
                printf("Borrow book!\n");
                break;
//            case 6: if (delete_user(account))
//                {
//                    printf("the account has been deleted!\n");
//                    return;
//                }
//                else break;
            case 0: printf("come back successfully!\n");return;
            default: printf("invalid option!\n"); break;
        }
    }
}



