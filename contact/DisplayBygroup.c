#include"user.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

extern List INFO;
extern char NAME[CONTACTMAX][Contact_LEN];
extern char NUMBER[CONTACTMAX][phone_LEN];
extern char GROUPS[CONTACTMAX][group_LEN];
extern int count;


Status List_showBygroups()
{
    system("cls");
    int i=7,j=0,k=25,times=0;
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
    printf("Input group name:");
    char reply[replyLEN];
    gets(reply);
    system("cls");
    times=0;
    NODE *p=(NODE *)malloc(sizeof(NODE));
    p=INFO.head->next;
    printf("\n\n\n");
    printf("        -----------------------------------------CONTACTS--------------------------------------- \n");
    printf("       |                                                                                        |\n");
    while(j<count)
    {
        if(strcmp(p->group,reply)==0)
        {
            times++;
            if(times%2==1)
            {
                printf("       |                                                                                        |\n");
                printf("       |                                                                                        |\n");
                printf("       |                                                                                        |\n");
                printf("       |                                                                                        |\n");
                printf("       |                                                                                        |\n");
                printf("       |                                                                                        |\n");
            }
            if(times%2==0) k=k+32;
            gotoxy(i,k);
            printf("Name:%s",p->name);
            gotoxy(i+1,k);
            printf("Number:%s",p->number);
            gotoxy(i+2,k);
            printf("Group:%s\n",p->group);
            if(times%2==0) i=i+6;
            k=25;
        }
        j++;
        p=p->next;
    }
    if(times%2==1)i=i+6;
    k=25;
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
    gotoxy(i,k);
    printf("All contacts loaded");
    gotoxy(i+2,k);
    printf("Press Enter Back To Menu...");
    gets(reply);
    return OK;
}

