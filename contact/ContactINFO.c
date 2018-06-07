#include"user.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


extern List INFO;
extern char NAME[CONTACTMAX][Contact_LEN];
extern char NUMBER[CONTACTMAX][phone_LEN];
extern char GROUPS[CONTACTMAX][group_LEN];
extern int count;
int num;

void Group_swap(int j,char iscount[][group_LEN],int groupnum[])
{
    char tmp1[group_LEN];
    strcpy(tmp1,iscount[j]);
    strcpy(iscount[j],iscount[j+1]);
    strcpy(iscount[j+1],tmp1);
    int tmp2;
    tmp2=groupnum[j];
    groupnum[j]=groupnum[j+1];
    groupnum[j+1]=tmp2;
}

void Contact_Count()
{
    char iscount[CONTACTMAX][group_LEN];
    int groupnum[CONTACTMAX];
    system("cls");
    int i,j;
    for(i=0;i<CONTACTMAX;i++) memset(iscount[i],'\0',group_LEN);
    memset(groupnum,0,CONTACTMAX);
    num=0;
    for(i=0;i<count;i++)
    {
        for(j=0;j<num;j++)
        {
            if(strcmp(GROUPS[i],iscount[j])==0)
                break;
        }
        if(j==num)
        {
            strcpy(iscount[j],GROUPS[i]);
            groupnum[j]++;
            num++;
        }
        else
            groupnum[j]++;
    }
    for(i=0;i<num-1;i++)
    {
        for(j=0;j<num-i-1;j++)
        {
            if(strcmp(iscount[j],iscount[j+1])>0)
                Group_swap(j,iscount,groupnum);
        }
    }
    printf("\n\n\n");
    printf("        --------------------------------------CONTACTS-INFO------------------------------------- \n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    gotoxy(7,44);
    printf("Contacts amount: %d",count);
    gotoxy(9,44);
    printf("Groups amount: %d",num);
    int times=0,col=28;
    if(num)
    {
        gotoxy(12,1);
        printf("       |---------------------------------------GROUPS-INFO--------------------------------------|\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        j=13;
        for(i=0; i<num; i++)
        {
            if(times%2==0)
            {
                j+=3;
                col=28;
                gotoxy(j,1);
                printf("       |                                                                                        |\n");
                printf("       |                                                                                        |\n");
                printf("       |                                                                                        |\n");
            }
            else col+=39;
            gotoxy(j,col);
            printf("Group: %s",iscount[i]);
            gotoxy(j+1,col);
            printf("Amount:%d",groupnum[i]);
            times++;
        }
        j+=3; col=1;
        gotoxy(j,col);
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("        ----------------------------------------------------------------------------------------\n");
        gotoxy(j+1,28);
        printf("All information loaded. Press ENTER back to Menu...");
    }
    else
    {
        gotoxy(12,1);
        printf("       |---------------------------------------GROUPS-INFO--------------------------------------|\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("        ----------------------------------------------------------------------------------------\n");
        gotoxy(15,47);
        printf("Groups EMPTY!");
        gotoxy(17,40);
        printf("Press ENTER back to Menu...");
    }
    char buf[100];
    gets(buf);
}
