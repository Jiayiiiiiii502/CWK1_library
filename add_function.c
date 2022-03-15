//
// Created by Jiayi on 2022/3/9.
//
#include <stdio.h>
#include "add_function.h"
#include "user.h"

void display_user(){
    int user_num=1;
    users*np;
    np=user_head->next;
    printf("Order\t\tUsername\t\tPassword\n");
    while(np){
        printf("%d)  %-20s  %-20s  ",user_num,np->username,np->password);
        np=np->next;
        user_num++;
    }
}