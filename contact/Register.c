//
// Created by 王文涛 on 2018/4/10.
//

#include <stdio.h>
#include "user.h"
#include <string.h>

char username[username_MAX];
char password[password_MAX];
char filename[flname_LEN];
char filetmp[flname_LEN];
char flcontact[flname_LEN];

int user_register()
{
    char reply[replyLEN];
    system("cls");
    char ch;
    int i=0;;
    printf("\n\n\n");
    printf("        -----------------------------------------REGISTER--------------------------------------- \n");
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
    i=0;
    gotoxy( 7,43);
    ch=getchar();
    //***************************************************************************************
    //下面是用户名与文件名的读入
    while(ch!='\n')
    {
        username[i]=ch;
        filetmp[i]=ch;
        i++;
        ch=getchar();
    }
    filetmp[i]='\0';
    username[i]=ch;
    username[++i]='\0';
    int NOTOK=0;
    for(i=0; i<strlen(username)-1; i++)
    {
        if(username[i]==' ')
        {
            NOTOK=1;
            break;
        }
    }
    while(strlen(username)>username_LEN-1||NOTOK)
    {
        system("cls");
        i=0;
        printf("\n\n\n");
        printf("        -----------------------------------------REGISTER--------------------------------------- \n");
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
            filetmp[i]=ch;
            i++;
            ch=getchar();
        }
        filetmp[i]='\0';
        username[i]=ch;
        username[++i]='\0';
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
    sprintf(filename,"data/userID_data/%s.txt",filetmp);//创建用户文件路径
    sprintf(flcontact,"data/Contact_data/%s.txt",filetmp);//同上
    //printf("%s",flcontact);
    //printf("%s\n",filename);
    FILE *fpID,*fpCont;
    if((fpID=fopen(filename,"r"))==NULL)
    {
        if(!(fpID=fopen(filename,"w")))
            return ERROR;
        if(!(fpCont=fopen(flcontact,"w")))
            return ERROR;
    }
    else  // user already existed!
    {
        system("cls");
        printf("\n\n\n");
        printf("        -----------------------------------------REGISTER--------------------------------------- \n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                 Username ALREADY EXISTED!                              |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                  Please choose:                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                  1.Register again.                                     |\n");
        printf("       |                                  2.Login.                                              |\n");
        printf("       |                                  3.Back to Menu.                                       |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                  Input number:                                         |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("        ----------------------------------------------------------------------------------------\n");
        gotoxy(15,56);
        gets(reply);
        while(strlen(reply)!=1||reply[0]!='1'&&reply[0]!='2'&&reply[0]!='3')
        {
            system("cls");
            printf("\n\n\n");
            printf("        -----------------------------------------REGISTER--------------------------------------- \n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                 Username Already EXISTED!                              |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                  Please choose:                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                  1.Register again.                                     |\n");
            printf("       |                                  2.Login.                                              |\n");
            printf("       |                                  3.Back to Menu.                                       |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                 Input ONLY number:                                     |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("        ----------------------------------------------------------------------------------------\n");
            gotoxy(15,60);
            gets(reply);
        }
        switch(reply[0])
        {
            case '1':
                return 1;
            case '2':
                return 2;
            case '3':
                return OK;
        }
    }//user already existed;

    //***************************************************************************************
    //下面是密码的读入
    system("cls");
    printf("\n\n\n");
    printf("        -----------------------------------------REGISTER--------------------------------------- \n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                   Input username:"); for(i=0;i<strlen(username)-1;i++) printf("%c",username[i]);for(i=0;i<(username_LEN-strlen(username));i++) printf(" ");printf("                                 |\n");
    printf("       |                                                                                        |\n");
    printf("       |                   (length<=20,no space,end with ENTER)                                 |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                   Input password:                                                      |\n");
    printf("       |                                                                                        |\n");
    printf("       |                   (length<=20,no space,end with ENTER)                                 |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("        ----------------------------------------------------------------------------------------\n");
    gotoxy(12,43);
    i=0;
    ch=getchar();
    while(ch!='\n'){
        password[i++]=ch;
        ch=getchar();
    }
    password[i]=ch;  password[++i]='\0';
    NOTOK=0;
    for(i=0;i<strlen(password)-1;i++)
    {
        if(password[i]==' ')
        {
            NOTOK=1;
            break;
        }
    }
    while(strlen(password)>password_LEN-1||NOTOK)
    {
        system("cls");
        printf("\n\n\n");
        printf("        -----------------------------------------REGISTER--------------------------------------- \n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                   Input username:"); for(i=0;i<strlen(username)-1;i++) printf("%c",username[i]);for(i=0;i<(username_LEN-strlen(username));i++) printf(" ");printf("                                 |\n");
        printf("       |                                                                                        |\n");
        printf("       |                   (length<=20,no space,end with ENTER)                                 |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                   Input password:                                                      |\n");
        printf("       |                                                                                        |\n");
        printf("       |    !**ATTENTION**!(length<=20,no space,end with ENTER)                                 |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("       |                                                                                        |\n");
        printf("        ----------------------------------------------------------------------------------------\n");
        gotoxy(12,43);
        i=0;
        ch=getchar();
        while(ch!='\n')
        {
            password[i++]=ch;
            ch=getchar();
        }
        password[i]=ch;
        password[++i]='\0';
        NOTOK=0;
        for(i=0; i<strlen(password)-1; i++)
        {
            if(password[i]==' ')
            {
                NOTOK=1;
                break;
            }
        }
    }
    //***************************************************************************************
    //存入文件
    fputs(username,fpID);
    fputs(password,fpID);
    system("cls");
    printf("\n\n\n");
    printf("        -----------------------------------------REGISTER--------------------------------------- \n");
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
    fclose(fpID);
    fclose(fpCont);
    Sleep(500);
    return OK;
}
