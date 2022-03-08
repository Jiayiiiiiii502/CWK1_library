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
void registration(){
    users already,new;
    FILE *fp_1;
    char password_temp[20];
    char password[];


    //读取已有的账户信息存储到结构体already中,b=already
    fp_1=fopen("users.txt","r");
    fread(&already,sizeof(struct Users_info),1,fp);

    //存储输入的账户信息到结构体new中,a=new
    printf("Please enter your username: \n");
    scanf("%s",&new.username);


    //比较输入的和已有的账户信息是否重合
    while(1){
        if(strcmp(already.username,new.username)!=0){//strcmp不返回0，字符串不相等，即注册信息有效
            if(feof(fp)!=0){//feof后面有字符返回0，没有返回非0
                fread(&already,sizeof(struct Users_info),1,fp_1)
            }
            else{
                break;
            }
        }
        else{//用户已经存在，提示重新注册
            printf("Sorry, the user have already existed!\n");
            printf("Please try again!\n");
            fclose(fp_1);
            return;
        }
    }


    //提示输入用户密码
    printf("Please enter your password: \n");
    scanf("%s",&new.password);
    printf("Please confirm your password: \n");
    scanf("%s",&password_temp);
    do{
        if(!strcmp(new.password,password_temp)){//如果密码确定一样，则写入文件
            fp_1=fopen("users.txt","a");
            fwrite(&new,sizeof(struct Users_info),1,fp);
            printf("Registered library account successfully!\n");
            fclose(fp_1);
            return;
        }
        else{
            printf("The two passwords do not match, please re-enter:\n");
            printf("Please enter your password: \n");
            scanf("%s",&new.password);
            printf("Please confirm your password: \n");
            scanf("%s",&password_temp);
        }
    }while(1);
}

void create_user_info(){
    FILE *fp;
    if((fp=fopen("users.txt","rb"))==NULL){
        if((fp=fopen("users.txt","wb+"))==NULL){
            printf("Sorry, you cannot create a new file.\n");
            exit(0);
        }
    }
}




//用户登录
void login(){
//    char name[];
//    char password[];
//    printf("Please enter your username: ");
//    scanf("%s",name);
//    printf("Please enter your password: ");
//    scanf("%s",password);

    users already,new;
    FILE *fp_2;

    //读取已有的账户信息存储到结构体already中,b=already
    fp_2=fopen("users.txt","r");
    fread(&already,sizeof(struct Users_info),1,fp_2);


    printf("Please enter your username: \n");
    scanf("%s",&new.username);

    while(1){//判断用户是否存在
        if(strcmp(new.username,already.username)==0){//用户存在
            break;
        }
        else{//用户不存在
            if(!feof(fp_2)){//文件没读完
                fread(&already,sizeof(struct Users_info),1,fp_2);
            }
            else{
                printf("This user doesn't exist!\n");
                //Sleep(500);
                fclose(fp_2);
                return;
            }
        }
    }
    printf("Please enter your password: \n");
    scanf("%s",&new.password);

    do{
        if(strcmp(new.password,already.password)==0){//密码正确
            fclose(fp_2);
            printf("Successfully login!\n");
            //Sleep(500);
            return;
        }
        else{
            printf("Invalid password! Please re-enter the password: \n");
            scanf("%s",&new.password);
        }
    }while(strcmp(new.password,already.password)==0);
}







//borrow book
void borrow_book(){

}


//return book
void return_book(){

}
