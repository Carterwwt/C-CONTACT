#include"user.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

extern List INFO;
extern char NAME[CONTACTMAX][Contact_LEN];
extern char NUMBER[CONTACTMAX][phone_LEN];
extern char GROUPS[CONTACTMAX][group_LEN];
extern int count;
int  firstname[CONTACTMAX];
int lastname[CONTACTMAX];

Status List_Search()
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
    gotoxy(11,35);
    printf("Input contact name:");
    char reply[replyLEN];
    gets(reply);
    int i,j=0,k=0;
    for(i=0; i<count; i++)
    {
        char *p=strstr(NAME[i],reply);
        if(p!=NULL)
        {
            if(p-NAME[i]==0)
                firstname[j++]=i;
            else
                lastname[k++]=i;
        }
    }
    system("cls");
    /*printf("j: %d k: %d \n",j,k);
    for(i=0;i<j;i++) printf("%s\n",firstname[i]);
    for(i=0;i<k;i++) printf("%s\n",lastname[i]);*/
    i=0;
    int row=7,col=25,times=0;
    printf("\n\n\n");
    printf("        -----------------------------------------CONTACTS--------------------------------------- \n");
    printf("       |                                                                                        |\n");
    while(i<j)
    {
        if(times%2==0)
        {
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
        }
        int LEN=firstname[i];
        if(times%2==0&&times) row=row+6;
        if(times%2==1) col=col+32;
        gotoxy(row,col);
        printf("Name:%s",NAME[LEN]);
        gotoxy(row+1,col);
        printf("Number:%s",NUMBER[LEN]);
        gotoxy(row+2,col);
        printf("Group:%s\n",GROUPS[LEN]);
        col=25;
        i++;
        times++;
    }
    i=0;
    while(i<k)
    {
        if(times%2==0)
        {
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
        }
        int LEN=lastname[i];
        if(times%2==0&&times) row=row+6;
        if(times%2==1) col=col+32;
        gotoxy(row,col);
        printf("Name:%s",NAME[LEN]);
        gotoxy(row+1,col);
        printf("Number:%s",NUMBER[LEN]);
        gotoxy(row+2,col);
        printf("Group:%s\n",GROUPS[LEN]);
        col=25;
        i++;
        times++;
    }
    if(times)row=row+6;
    col=25;
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
    gotoxy(row,col);
    printf("All contacts loaded");
    gotoxy(row+2,col);
    printf("Press Enter Back To Menu...");
    getchar();
    return OK;
}
