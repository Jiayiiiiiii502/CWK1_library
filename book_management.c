//
// Created by Jiayi on 2022/3/6.
//

#include "book_management.h"
//建立图书馆板块：
void load_books()//将图书文件加载到链表中
{
    book_head = (Book*)malloc(sizeof(Book));
    book_head->next = NULL;
    book_num = 0;

    FILE* fp2;
    fp2 = fopen("all_books.txt", "rb");
    if (fp2 == NULL)
    {
        fp2 = fopen("all_books.txt", "wb");
        if (fp2 == NULL)
        {
            printf("Fail to load the books!\n"); exit(0);
        }
        fclose(fp2);
    }
    else
    {
        Book* bp;
        bp = book_head;
        Book* tp = (Book*)malloc(sizeof(Book));
        while (fread(tp, sizeof(Book), 1, fp2))
        {
            bp->next = tp;
            book_num++;
            tp = (Book*)malloc(sizeof(Book));
            bp = bp->next;
        }
        fclose(fp2);
    }
}

void store_books()//将链表写入图书文件
{
    FILE*fp = fopen("all_books.txt", "wb");
    Book* tb = book_head->next;
    while (tb)
    {
        fwrite(tb, sizeof(Book), 1, fp);
        tb = tb->next;
    }
    fclose(fp);
}

void creat_book_list(char* title, char* author, int id, int year, int copies)//更新所有书籍链表，调用store函数将新链表写入文件中
{
    Book* np;
    np = book_head;
    while (np->next) np = np->next;
    Book* tb = (Book*)malloc(sizeof(Book));
    strcpy(tb->authors, author);
    strcpy(tb->title, title);
    tb->id = id;
    tb->year = year;
    tb->copies =copies;
    tb->next = NULL;
    np->next = tb;
    store_books();
}






void add_book()//在所有书籍链表中添加一本书，并调用create_book_list函数（更新所有书籍链表，调用store函数将新链表写入文件中）
{
    char title[100],author[100];
    int id,year,copies;
    printf("Please enter the title:\n");
    //fgets(title,30,stdin);
    //gets(title);gets函数连用不了55555
    scanf("%s", title);
    printf("Please enter the author:\n");
    scanf("%s", author);
    gets(author);
    printf("Please enter the id:\n");
    scanf("%d", &id);
    printf("Please enter the year:\n");
    scanf("%d", &year);
    printf("Please enter its copies:\n");
    scanf("%d", &copies);
    book_num++;
    creat_book_list(title, author, id, year, copies);
    printf("%s has been added to the library successfully!\n", title);
}


void remove_book()//从链表里删除指定书籍，并调用store函数将新链表写入文件中
{
    while (1)
    {
        display_book();
        printf("Please enter the order of the book you wanna move out:(-1 to quit):\n");
        int choice;
        scanf("%d", &choice);
        if (choice == -1)
        {
            printf("Come back successfully!\n");
            return;
        }
        else if(choice<=book_num && choice>0){
            Book* tb;
            Book* np;
            np = book_head;
            tb = book_head->next;
            for (int i = 1; i < choice; ++i)
            {
                np = tb;
                tb = tb->next;
            }
            np->next = tb->next;
            free(tb);
            book_num--;
            store_books();
            printf("Remove successfully!\n");
        }
        else
        {
            printf("Invalid id!\n");
            printf("Please tyr again!\n");
        }

    }
}

void search_book_menu(){
    printf("Please choose a way to find books:\n");
    printf("1)Find book by title\n");
    printf("2)Find book by author\n");
    printf("3)Find book by year\n");
    printf("4)Quit\n");
    int choice;
    scanf("%d", &choice);
    switch(choice)
    {
        case 1: search_book_by_title();
            break;
        case 2: search_book_by_author();
            break;
        case 3: search_book_by_year();
            break;
        case 4: printf("Come back successfully!\n");
            return;
        default:printf("Invalid choice!\n");
            printf("Please try again!\n");
            search_book_menu();
    }
}

void search_book_by_title(){
    char temp[30];
    Book *tb=book_head->next;
    printf("please enter the title of the book:");
    scanf("%s",temp);
    while(tb)
    {
        if(strcmp(temp,tb->title)==0)
            break;
        tb=tb->next;
    }
    if(tb==NULL)
    {
        printf("Sorry,there is no such book in the library!\n");
        return;
    }
    tb=book_head->next;
    printf("ID\t\tTitle\t\tAuthor\t\tYear\t\tCopies\n");
    while(tb)
    {
        if(strcmp(temp,tb->title)==0)
            printf("%-15d %-15s %-15s %-15d %-15d\n", tb->id, tb->title, tb->authors, tb->year, tb->copies);
        tb=tb->next;
    }
    return;
}


void search_book_by_author ()//遍历所有书籍链表，按书记作者查找
{
    char temp[30];
    Book *tb=book_head->next;
    printf("Please enter the author of the book:");
    scanf("%s",temp);
    while(tb)
    {
        if(strcmp(temp,tb->authors)==0)
            break;
        tb=tb->next;
    }
    if(tb==NULL)
    {
        printf("Sorry,there is no such book in the library!\n");
        return;
    }
    tb=book_head->next;
    printf("ID\t\tTitle\t\tAuthor\t\tYear\t\tCopies\n");
    while(tb)
    {
        if(strcmp(temp,tb->authors)==0)
            printf("%-15d %-15s %-20s %-15d %-15d\n", tb->id, tb->title, tb->authors, tb->year, tb->copies);
        tb=tb->next;
    }
    return;
}

void search_book_by_year ()//遍历所有书籍链表，按年份查找
{
    int year;
    Book *tb=book_head->next;
    printf("Please enter the year of the book:");
    scanf("%d",&year);
    while(tb)
    {
        if(year==tb->year)
            break;
        tb=tb->next;
    }
    if(tb==NULL)
    {
        printf("Sorry,there is no such book in the library!\n");
        return;
    }
    tb=book_head->next;
    printf("ID\t\tTitle\t\tAuthor\t\tYear\t\tCopies\n");
    while(tb)
    {
        if(year==tb->year)
            printf("%-15d %-15s %-20s %-15d %-15d\n", tb->id, tb->title, tb->authors, tb->year, tb->copies);
        tb=tb->next;
    }
    return;
}



void display_book()//用链表展示书籍
{
    if (!book_num)
    {
        printf("Sorry! There is no book in the library!\n");
        return;
    }

    Book* all;
    all = book_head->next;
    printf("THE BOOKARRAY:\n");
    printf("ID\t\tTitle\t\tAuthor\t\tYear\t\tCopies\n");
    while (all)
    {
        printf("%-15d %-15s %-20s %-15d %-15d\n", all->id, all->title, all->authors, all->year, all->copies);
        all = all->next;
    }
}



















