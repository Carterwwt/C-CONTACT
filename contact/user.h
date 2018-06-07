//
// Created by 王文涛 on 2018/4/10.
//
#ifndef C_CONTACT_USER_H
#define C_CONTACT_USER_H

#endif //C_CONTACT_USER_H
#define username_LEN 22
#define password_LEN 22
#define username_MAX 255
#define password_MAX 255
#define Contact_LEN  50
#define phone_LEN  50
#define group_LEN  50
#define flname_LEN   255
#define Status int
#define ERROR 0
#define OK 666
#define OVER -1
#define quit 999
#define replyLEN 100
#define CONTACTMAX 500

#include <windows.h>
typedef struct ContactInfo
{
    char name[Contact_LEN];
    char number[phone_LEN];
    char group[group_LEN];
    struct ContactInfo *next;
}NODE;

typedef struct Linklist
{
    struct ContactInfo *head;
    struct ContactInfo *tail;
}List;

extern int user_register();
extern int user_login();
extern int Logged_Menu();
extern Status NewContact();
extern List EditContact(List INFO);
extern void gotoxy(int y,int x);
extern List InitList(List INFO);
extern List InsertList(List INFO,char name[Contact_LEN],char number[phone_LEN],char group[group_LEN]);
extern List List_import(List INFO);
extern Status List_save(List INFO);
extern Status List_showBygroups();
extern void List_showarray();
extern Status List_Search();
extern void Contact_Count();
extern void List_showGroup();
extern void List_showList();
