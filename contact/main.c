#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include <stdlib.h>
int flag;

void gotoxy(int y,int x)    //设置光标的位置
{
    COORD c;
    c.X=x-1;
    c.Y=y-1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

int main() {
    char input[replyLEN],ch;
    int response,i;
    printf("\n\n\n");
    printf("        ---------------------------------------------------------------------------------------- \n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |==============================Welcome to Contacts Management============================|\n");
    printf("       |                                                                                        |\n");
    printf("       |                                    (Input number)                                      |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                      1.Register                                        |\n");
    printf("       |                                      2.Login                                           |\n");
    printf("       |                                      3.Exit                                            |\n");
    printf("       |                                                                                        |\n");
    printf("       |                               Input(End with ENTER):                                   |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("       |                                                                                        |\n");
    printf("        ----------------------------------------------------------------------------------------\n");
    gotoxy(15,62);
    loop:
        i=0;
        ch=getchar();
        while(ch!='\n')
        {
            input[i++]=ch;
            ch=getchar();
        }
        input[i]='\0';
        //下面处理非法输入情况
        while (strlen(input) != 1 || (input[0] != '1' && input[0] != '2' && input[0] != '3'))
            {
                system("cls");
                printf("\n\n\n");
                printf("        ---------------------------------------------------------------------------------------- \n");
                printf("       |                                                                                        |\n");
                printf("       |                                                                                        |\n");
                printf("       |==============================Welcome to Contacts Management============================|\n");
                printf("       |                                                                                        |\n");
                printf("       |                                    (Input number)                                      |\n");
                printf("       |                                                                                        |\n");
                printf("       |                                      1.Register                                        |\n");
                printf("       |                                      2.Login                                           |\n");
                printf("       |                                      3.Exit                                            |\n");
                printf("       |                                                                                        |\n");
                printf("       |                                       Error!                                           |\n");
                printf("       |                                 Please input again:                                    |\n");
                printf("       |                                                                                        |\n");
                printf("       |                                                                                        |\n");
                printf("        ----------------------------------------------------------------------------------------\n");
                gotoxy(16,62);
            goto loop;
        }

    while (1) {
        flag=0;
        switch (input[0]) {
            case '1':
                response = user_register();
                system("cls");
                if(response==1)
                {
                    input[0]='1'; input[1]='\0';
                    flag=1;
                }
                if(response==2)
                {
                    input[0]='2'; input[1]='\0';
                    flag=1;
                }
                // if response == 3,(back to menu) only break;
                break;
            case '2':
                response = user_login();
                system("cls");
                if (response == ERROR) printf("                                      Login Error!\n");
                if (response==1)
                {
                    flag=1;
                    input[0]='1'; input[1]='\0';
                }
                if (response==2)
                {
                    flag=1;
                    input[0]='2'; input[1]='\0';
                }
                break;/* if response == OVER , break only && back to menu*/
            case '3':
                    system("cls");
                    printf("\n\n\n");
                    printf("        ---------------------------------------------------------------------------------------- \n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                        EXITING...                                      |\n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                                                                        |\n");
                    printf("        ----------------------------------------------------------------------------------------\n");
                    Sleep(400);
                    system("cls");
                    printf("\n\n\n");
                    printf("        ---------------------------------------------------------------------------------------- \n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                        GOOD BYE!                                       |\n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                                                                        |\n");
                    printf("       |                                                                                        |\n");
                    printf("        ----------------------------------------------------------------------------------------\n");
                return 0;
        }
        /**/printf("\n\n\n");
        /**/printf("        ---------------------------------------------------------------------------------------- \n");
        /**/printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
        /**/printf("       |==============================Welcome to Contacts Management============================|\n");
        if(flag==0)
        {
            printf("       |                                                                                        |\n");
            printf("       |                                    (Input number)                                      |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                      1.Register                                        |\n");
            printf("       |                                      2.Login                                           |\n");
            printf("       |                                      3.Exit                                            |\n");
            printf("       |                                                                                        |\n");
            printf("       |                               Input(End with ENTER):                                   |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("       |                                                                                        |\n");
            printf("        ----------------------------------------------------------------------------------------\n");
            gotoxy(15,62);
            circle:
                i=0;
                ch=getchar();
                while(ch!='\n')
                {
                    input[i++]=ch;
                    ch=getchar();
                }
                input[i]='\0';
                //下面处理非法输入情况
                while (strlen(input) != 1 || (input[0] != '1' && input[0] != '2' && input[0] != '3'))
                    {
                        system("cls");
                        printf("\n\n\n");
                        printf("        ---------------------------------------------------------------------------------------- \n");
                        printf("       |                                                                                        |\n");
                        printf("       |                                                                                        |\n");
                        printf("       |==============================Welcome to Contacts Management============================|\n");
                        printf("       |                                                                                        |\n");
                        printf("       |                                    (Input number)                                      |\n");
                        printf("       |                                                                                        |\n");
                        printf("       |                                      1.Register                                        |\n");
                        printf("       |                                      2.Login                                           |\n");
                        printf("       |                                      3.Exit                                            |\n");
                        printf("       |                                                                                        |\n");
                        printf("       |                                        Error!                                          |\n");
                        printf("       |                                  Please input again:                                   |\n");
                        printf("       |                                                                                        |\n");
                        printf("       |                                                                                        |\n");
                        printf("        ----------------------------------------------------------------------------------------\n");
                        gotoxy(16,62);
                    goto circle;
                    }
        }
    }
    return 0;
}
