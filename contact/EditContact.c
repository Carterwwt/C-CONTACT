#include"user.h"
#include<stdio.h>
#include<string.h>

void EditContact_Name(NODE *p);
void EditContact_Number(NODE *p);
void EditContact_Group(NODE *p);
Status EditContact_Delete(NODE *p,NODE *prev,int i);
void ContactDelete(NODE *p,NODE *prev,int i);
extern int count;

extern char NAME[CONTACTMAX][Contact_LEN];
extern char NUMBER[CONTACTMAX][phone_LEN];
extern char GROUPS[CONTACTMAX][group_LEN];

char nametmp[Contact_LEN];
char numbertmp[phone_LEN];
char grouptmp[group_LEN];

List EditContact(List INFO)
{

    memset(nametmp,'\0',Contact_LEN);
    memset(numbertmp,'\0',Contact_LEN);
    memset(grouptmp,'\0',Contact_LEN);
    int response,i;
    system("cls");
    printf("\n\n\n");
    printf("        -----------------------------------------CONTACTS--------------------------------------- \n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("        ----------------------------------------------------------------------------------------\n");
    gotoxy(11,35);
    printf("Input contact name:");
    char reply[replyLEN];
    gets(reply);
    NODE *p=(NODE *)malloc(sizeof(NODE));
    NODE *prev=(NODE *)malloc(sizeof(NODE));
    if(!p) return INFO;
    p=INFO.head->next;
    prev=INFO.head;
    i=0;
    while(p)
    {
        if(strcmp(p->name,reply)==0) break;
        prev=p;
        p=p->next;
        i++;
    }
    if(!p)
    {
        system("cls");
        printf("\n\n\n");
        printf("        -----------------------------------------CONTACTS--------------------------------------- \n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("        ----------------------------------------------------------------------------------------\n");
        gotoxy(9,35);
        printf("Contact not found!");
        gotoxy(12,35);
        printf("Press Enter Back to Menu...");
        gets(reply);
        return INFO;
    }
    else
    {
        strcpy(nametmp,p->name);
        strcpy(numbertmp,p->number);
        strcpy(grouptmp,p->group);
        while(1)
        {
            system("cls");
            printf("\n\n\n");
            printf("        -----------------------------------------CONTACTS--------------------------------------- \n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("        ----------------------------------------------------------------------------------------\n");
            gotoxy(8,25);
            printf("Name : %s",p->name);
            gotoxy(10,25);
            printf("Number:%s",p->number);
            gotoxy(12,25);
            printf("Group :%s",p->group);
            gotoxy(7,55);
            printf("1.Edit name");
            gotoxy(9,55);
            printf("2.Edit number");
            gotoxy(11,55);
            printf("3.Edit group");
            gotoxy(13,55);
            printf("4.Delete contact");
            gotoxy(15,55);
            printf("5.Back to Menu");
            gotoxy(17,55);
            printf("Input reply:");
            gets(reply);
            while(strlen(reply)!=1|| (reply[0]!='1'&&reply[0]!='2'&&reply[0]!='3'&&reply[0]!='4'&&reply[0]!='5'))
            {
                system("cls");
                printf("\n\n\n");
                printf("        -----------------------------------------CONTACTS--------------------------------------- \n");
                printf("       |                                                                                        |\n");
                printf("       |                                                                                        |\n");
                printf("       |                                                                                        |\n");
                printf("       |                                                                                        |\n");
                printf("       |                                                                                        |\n");
                printf("       |                                                                                        |\n");
                printf("       |                                                                                        |\n");
                printf("       |                                                                                        |\n");
                printf("       |                                                                                        |\n");
                printf("       |                                                                                        |\n");
                printf("       |                                                                                        |\n");
                printf("       |                                                                                        |\n");
                printf("       |                                                                                        |\n");
                printf("       |                                                                                        |\n");
                printf("        ----------------------------------------------------------------------------------------\n");
                gotoxy(8,25);
                printf("Name : %s",p->name);
                gotoxy(10,25);
                printf("Number:%s",p->number);
                gotoxy(12,25);
                printf("Group :%s",p->group);
                gotoxy(7,55);
                printf("1.Edit name");
                gotoxy(9,55);
                printf("2.Edit number");
                gotoxy(11,55);
                printf("3.Edit group");
                gotoxy(13,55);
                printf("4.Delete contact");
                gotoxy(15,55);
                printf("5.Back to Menu");
                gotoxy(17,45);
                printf("!!retry!! Input reply:");
                gets(reply);
            }
            switch(reply[0])
            {
            case '1':
                EditContact_Name(p);
                break;
            case '2':
                EditContact_Number(p);
                break;
            case '3':
                EditContact_Group(p);
                break;
            case '4':
                response=EditContact_Delete(p,prev,i);
                if (response==quit) return INFO;
                break;
            case '5':
                ContactDelete(p,prev,i);
                INFO=InsertList(INFO,nametmp,numbertmp,grouptmp);
                return INFO;
            }
        }
    }
}

void EditContact_Name(NODE *p)
{
        system("cls");
        printf("\n\n\n");
        printf("        -----------------------------------------CONTACTS--------------------------------------- \n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("        ----------------------------------------------------------------------------------------\n");
        gotoxy(11,40);
        printf("Input new name:");
        char reply[replyLEN];
        gets(reply);
        strcpy(p->name,reply);
        strcpy(nametmp,reply);
}

void EditContact_Number(NODE *p)
{
        system("cls");
        printf("\n\n\n");
        printf("        -----------------------------------------CONTACTS--------------------------------------- \n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("        ----------------------------------------------------------------------------------------\n");
        gotoxy(11,39);
        printf("Input new number:");
        char reply[replyLEN];
        gets(reply);
        strcpy(p->number,reply);
        strcpy(numbertmp,reply);
}

void EditContact_Group(NODE *p)
{
        system("cls");
        printf("\n\n\n");
        printf("        -----------------------------------------CONTACTS--------------------------------------- \n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("        ----------------------------------------------------------------------------------------\n");
        gotoxy(11,39);
        printf("Input new group:");
        char reply[replyLEN];
        gets(reply);
        strcpy(p->group,reply);
        strcpy(grouptmp,reply);
}

Status EditContact_Delete(NODE *p,NODE *prev,int i)
{
    system("cls");
    printf("\n\n\n");
    printf("        ------------------------------------------DELETE--------------------------------------- \n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("        ----------------------------------------------------------------------------------------\n");
    gotoxy(10,25);
    printf("Name : %s",p->name);
    gotoxy(12,25);
    printf("Number:%s",p->number);
    gotoxy(14,25);
    printf("Group :%s",p->group);
    gotoxy(10,58);
    printf("!!****ATTENTION****!!");
    gotoxy(12,60);
    printf("Sure to DELETE?");
    gotoxy(14,61);
    printf("Input Y or N:");
    char reply[replyLEN];
    gets(reply);
    if(reply[0]=='Y'&&strlen(reply)==1)
    {
        prev->next=p->next;
        free(p);
        int j;
        for(j=i;j<count-1;j++)
        {
            strcpy(NAME[j],NAME[j+1]);
            strcpy(NUMBER[j],NUMBER[j+1]);
            strcpy(GROUPS[j],GROUPS[j+1]);
        }
        memset(NAME[count],'\0',Contact_LEN);
        memset(NUMBER[count],'\0',phone_LEN);
        memset(GROUPS[count],'\0',group_LEN);
        count--;
        system("cls");
        printf("\n\n\n");
        printf("        ------------------------------------------DELETE--------------------------------------- \n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("        ----------------------------------------------------------------------------------------\n");
        gotoxy(10,43);
        printf("DELETED SUCCESSFULLY!");
        Sleep(400);
        return quit;
    }
    return OK;
}

void ContactDelete(NODE *p,NODE *prev,int i)
{
        prev->next=p->next;
        free(p);
        int j;
        for(j=i;j<count-1;j++)
        {
            strcpy(NAME[j],NAME[j+1]);
            strcpy(NUMBER[j],NUMBER[j+1]);
            strcpy(GROUPS[j],GROUPS[j+1]);
        }
        memset(NAME[count],'\0',Contact_LEN);
        memset(NUMBER[count],'\0',phone_LEN);
        memset(GROUPS[count],'\0',group_LEN);
        count--;
}
