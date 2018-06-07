#include"user.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

extern List INFO;
extern char NAME[CONTACTMAX][Contact_LEN];
extern char NUMBER[CONTACTMAX][phone_LEN];
extern char GROUPS[CONTACTMAX][group_LEN];
extern int count;


Status List_showBygroups(List INFO)
{
    system("cls");
    int i=7,j=0,k;
    printf("%d\n",count);
    while(j<count)
    {
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
        for(k=0;k<3;k++)
        {
            gotoxy(i,20);
            printf("Name:%s",NAME[j]);
            gotoxy(i+1,20);
            printf("Number:%s",NUMBER[j]);
            gotoxy(i+2,20);
            printf("Group:%s\n",GROUPS[j]);
            j++;
            if(j==count) break;
            gotoxy(i,52);
            printf("Name:%s",NAME[j]);
            gotoxy(i+1,52);
            printf("Number:%s",NUMBER[j]);
            gotoxy(i+2,52);
            printf("Group:%s",GROUPS[j]);
            j++;
            if(j==count) break;
            i=i+4;
        }
    }
    char reply[replyLEN];
    getchar();
    return OK;
}
