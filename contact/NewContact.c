#include"user.h"
#include<stdio.h>
#include<string.h>

extern char username[username_MAX];
extern char filename[flname_LEN];
extern char name[Contact_LEN];
extern char number[phone_LEN];
extern char group[group_LEN];
extern List INFO;
extern int count;

extern char NAME[CONTACTMAX][Contact_LEN];
extern char NUMBER[CONTACTMAX][phone_LEN];
extern char GROUPS[CONTACTMAX][group_LEN];

Status NewContact()
{
    int i;
    char ch;
    system("cls");
    printf("\n\n\n");
    printf("        ---------------------------------------NEW CONTACT-------------------------------------- \n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                   NAME:                                                                |\n");
    printf("       |                                                                                        |\n");
    printf("       |                   PHONE:                                                               |\n");
    printf("       |                                                                                        |\n");
    printf("       |                   GROUP:                                                               |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("        ----------------------------------------------------------------------------------------\n");
    gotoxy(9,33);
    i=0;
    ch=getchar();
    while(ch!='\n')
    {
        name[i++]=ch;
        ch=getchar();
    }
    name[i]='\0'; //name[++i]='\0';
    gotoxy(11,34);
    i=0;
    ch=getchar();
    while(ch!='\n')
    {
        number[i++]=ch;
        ch=getchar();
    }
    number[i]='\0'; //number[++i]='\0';
    gotoxy(13,34);
    i=0;
    ch=getchar();
    while(ch!='\n')
    {
        group[i++]=ch;
        ch=getchar();
    }
    group[i]='\0'; //group[++i]='\0';
    gotoxy(19,97);
    INFO = InsertList(INFO,name,number,group);
    system("cls");
    printf("\n\n\n");
    printf("        ---------------------------------------NEW CONTACT-------------------------------------- \n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                         SUCCESS!                                       |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("        ----------------------------------------------------------------------------------------\n");
    Sleep(500);
    //List_showarray();
    return OK;
}
