#include"user.h"
#include<stdio.h>
#include<string.h>

extern char username[username_MAX];
char name[Contact_LEN];
char number[phone_LEN];
char group[group_LEN];
List INFO;

int Logged_Menu()
{
    //***************create list and import contact info
    INFO=InitList(INFO);
    INFO=List_import(INFO);
    while(1)
    {
        int i,response;
        system("cls");
        printf("\n\n\n");
        printf("       |===================================Contacts Management==================================|\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                               1.Add new contact                        |\n");
        printf("       |       Welcome back                                                                     |\n");
        printf("       |                                               2.Edit contact                           |\n");
        printf("       |                                                                                        |\n");
        printf("       |       ");
        printf("%s",username);
        for(i=0; i<username_LEN-strlen(username); i++) printf(" ");
        printf("                  3.Search contacts                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                               4.Display by groups                      |\n");
        printf("       |                                                                                        |\n");
        printf("       |       Input number:                           5.Contacts INFO                          |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                               6.Log out                                |\n");
        printf("       |                                                                                        |\n");
        printf("        ----------------------------------------------------------------------------------------\n");
        //List_showarray();
        //List_showList();
        char reply[replyLEN];
        gotoxy(15,29);
        gets(reply);
        while(strlen(reply)!=1||reply[0]!='1'&&reply[0]!='2'&&reply[0]!='3'&&reply[0]!='4'&&reply[0]!='5'&&reply[0]!='6')
        {
            system("cls");
            printf("\n\n\n");
            printf("       |===================================Contacts Management==================================|\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                               1.Add new contact                        |\n");
            printf("       |       Welcome back                                                                     |\n");
            printf("       |                                               2.Edit contact                           |\n");
            printf("       |                                                                                        |\n");
            printf("       |       ");
            printf("%s",username);
            for(i=0; i<username_LEN-strlen(username); i++) printf(" ");
            printf("                  3.Search contacts                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                               4.Display by groups                      |\n");
            printf("       |                                                                                        |\n");
            printf("       |       Input number:                           5.Contacts INFO                          |\n");
            printf("       |                                                                                        |\n");
            printf("       |   !**!Please input again                      6.Log out                                |\n");
            printf("       |                                                                                        |\n");
            printf("        ----------------------------------------------------------------------------------------\n");
            gotoxy(15,29);
            gets(reply);
        }
        switch(reply[0])
        {
        case '1':
            response=NewContact();
            break;
        case '2':
            INFO=EditContact(INFO);
            break;
        case '3':
            response=List_Search();
            break;
        case '4':
            response=List_showBygroups(INFO);
            break;
        case '5':
            Contact_Count();
            break;
        case '6':
            List_save(INFO);
            return quit;
        }
    }
}
