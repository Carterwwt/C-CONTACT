//
// Created by 王文涛 on 2018/4/10.
//
#include "user.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char username[username_MAX];
extern char password[password_MAX];
extern char filename[flname_LEN];
char passtmp[password_LEN];

void get_password(char passtmp[],FILE *fp){
    int i;
    for(i=1;i<=2;i++){
        fgets(passtmp,password_LEN,fp);
    }
    passtmp[strlen(passtmp)-1]='\0';
}//获取对应密码


int user_login()
{
    char reply[replyLEN];
    system("cls");
    int flag=0;// 从文件中获取到密码后不再读取
    printf("\n\n\n");
    printf("        -----------------------------------------LOGIN------------------------------------------ \n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                   Input username:                                                      |\n");
    printf("       |                                                                                        |\n");
    printf("       |                   (length<=20,no space,end with ENTER)                                 |\n");
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
    gotoxy( 7,43);
    int i=0;
    char ch;
    ch=getchar();
    while(ch!='\n'){
        username[i++]=ch;
        ch=getchar();
    }
    username[i]='\0';
    int NOTOK=0;
    for(i=0;i<strlen(username)-1;i++)
    {
        if(username[i]==' ')
        {
            NOTOK=1;
            break;
        }
    }
    while(strlen(username)>username_LEN-2||NOTOK)
    {
        system("cls");
        i=0;
        printf("\n\n\n");
        printf("        -----------------------------------------LOGIN------------------------------------------ \n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                   Input username:                                                      |\n");
        printf("       |                                                                                        |\n");
        printf("       |   !**ATTENTION**! (length<=20,no space,end with ENTER)                                 |\n");
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
        gotoxy( 7,43);
        ch=getchar();
        //***************************************************************************************
        //下面是用户名与文件名的读入
        while(ch!='\n')
        {
            username[i]=ch;
            i++;
            ch=getchar();
        }
        username[i]='\0';
        NOTOK=0;
        for(i=0; i<strlen(username)-1; i++)
        {
            if(username[i]==' ')
            {
                NOTOK=1;
                break;
            }
        }
    }
    sprintf(filename,"data/userID_data/%s.txt",username);
    //printf("%s\n",filename);
    //下面寻找是否存在用户名
    FILE *fp;
    if(!(fp=fopen(filename,"r")))
    {
        system("cls");
        printf("\n\n\n");
            printf("        -----------------------------------------LOGIN------------------------------------------\n");
            printf("       |                                                                                        |\n");
            printf("       |                                  Username not found!                                   |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                    Please choose:                                      |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                    1.Register                                          |\n");
            printf("       |                                    2.Login again                                       |\n");
            printf("       |                                    3.Back to menu                                      |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                    Input number:                                       |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("        ----------------------------------------------------------------------------------------\n");
        gotoxy(14,58);
        gets(reply);
        while(strlen(reply)!=1||reply[0]!='1'&&reply[0]!='2'&&reply[0]!='3')
        {
            system("cls");
            printf("\n\n\n");
            printf("        -----------------------------------------LOGIN------------------------------------------\n");
            printf("       |                                                                                        |\n");
            printf("       |                                  Username not found!                                   |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                    Please choose:                                      |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                    1.Register                                          |\n");
            printf("       |                                    2.Login again                                       |\n");
            printf("       |                                    3.Back to menu                                      |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                  Input ONLY number:                                    |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("        ----------------------------------------------------------------------------------------\n");
            gotoxy(14,61);
            gets(reply);
        }
        switch(reply[0])
        {
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return OVER;
        }
    }
    else {
        //输入密码
        int count=0,response;
loop:
        gotoxy(13,28);
        printf("Input password:");
        gotoxy(13,43);
        i=0;
        ch = getchar();
        while (ch != '\n')
        {
            password[i++] = ch;
            ch = getchar();
        }
        password[i] = '\0';
        if(flag==0) get_password(passtmp,fp);
        if (strcmp(passtmp,password)==0)//-------**********Login SUCCESS*********----------------
        {
            response=Logged_Menu();
            if(response==quit)  return OVER;
        }

        //////---------------------------------------------------------------------------------
        //     password wrong;
        else
        {
            flag=1;
            count++;
            if(count==3)
            {
                system("cls");
                printf("\n\n\n");
                printf("        -----------------------------------------LOGIN------------------------------------------ \n");
                printf("       |                                                                                        |\n");
                printf("       |                                     3 times ERROR!                                     |\n");
                printf("       |                                                                                        |\n");
                printf("       |                                     Please choose:                                     |\n");
                printf("       |                                                                                        |\n");
                printf("       |                                                                                        |\n");
                printf("       |                                   1.Back to start menu.                                |\n");
                printf("       |                                   2.Continue trying.                                   |\n");
                printf("       |                                                                                        |\n");
                printf("       |                                                                                        |\n");
                printf("       |                                     Input number:                                      |\n");
                printf("       |                                                                                        |\n");
                printf("       |                                                                                        |\n");
                printf("       |                                                                                        |\n");
                printf("        ----------------------------------------------------------------------------------------\n");
                gotoxy(15,59);
                gets(reply);
                while(strlen(reply)!=1||reply[0]!='1'&&reply[0]!='2')
                {
                    system("cls");
                    printf("\n\n\n");
                    printf("        -----------------------------------------LOGIN------------------------------------------ \n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                     3 times ERROR!                                     |\n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                     Please choose:                                     |\n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                   1.Back to start menu.                                |\n");
                    printf("       |                                   2.Continue trying.                                   |\n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                   Input ONLY number:                                   |\n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                                                                        |\n");
                    printf("        ----------------------------------------------------------------------------------------\n");
                    gotoxy(15,62);
                    gets(reply);
                }
                switch (reply[0])
                {
                case '1':
                    return OVER;
                case '2':
                    return 2;
                }
            }//if(count==3)
            system("cls");

            printf("\n\n\n");
            printf("        -----------------------------------------LOGIN------------------------------------------ \n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                   Input username:");
            printf("%s",username);
            for(i=0; i<(username_LEN-strlen(username)); i++) printf(" ");
            printf("                                |\n");
            printf("       |                                                                                        |\n");
            printf("       |                   (length<=20,no space,end with ENTER)                                 |\n");
            printf("       |                                                                                        |\n");
            printf("       |                   PASSWORD ERROR!                                                      |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("        ----------------------------------------------------------------------------------------\n");
            goto loop;
        }//else(password wrong)
        return OK;
    }
}
