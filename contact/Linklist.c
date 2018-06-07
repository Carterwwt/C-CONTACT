#include"user.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

extern char username[username_MAX];
extern char filename[flname_LEN];
extern char name[Contact_LEN];
extern char number[phone_LEN];
extern char group[group_LEN];
extern List INFO;
extern char iscount[CONTACTMAX][group_LEN];
extern char groupnum[CONTACTMAX];
extern int num;

char NAME[CONTACTMAX][Contact_LEN];
char NUMBER[CONTACTMAX][phone_LEN];
char GROUPS[CONTACTMAX][group_LEN];
int count;

List InitList(List INFO)
{
    INFO.head=(NODE *)malloc(sizeof(NODE));
    INFO.head->next=NULL;
    INFO.tail=INFO.head;
    return INFO;
}

List InsertList(List INFO,char name[],char number[],char group[])
{
    NODE *p1,*p,*prev;
    p1=(NODE *)malloc(sizeof(NODE));
    p=(NODE *)malloc(sizeof(NODE));
    prev=(NODE *)malloc(sizeof(NODE));
    p1=INFO.head->next;
    prev=INFO.head;
    strcpy(p->name,name);
    strcpy(p->number,number);
    strcpy(p->group,group);
    if(!p1){
        INFO.head->next=p;
        p->next=NULL;
        INFO.tail=p;
    }
    else
    {
        while(p1)
        {
            if(strcmp(name,p1->name)<0||strcmp(name,p1->name)==0)
                break;
            prev=p1;
            p1=p1->next;
        }
        prev->next=p;
        p->next=p1;
    }
    int i,j;
    for(i=0;i<count;i++)
    {
        if(strcmp(name,NAME[i])<0||strcmp(name,NAME[i])==0)
            break;
    }
    if(i==count)
    {
        strcpy(NAME[i],name);
        strcpy(NUMBER[i],number);
        strcpy(GROUPS[i],group);
    }
    else
    {
        for(j=count; j>i; j--)
        {
            strcpy(NAME[j],NAME[j-1]);
            strcpy(NUMBER[j],NUMBER[j-1]);
            strcpy(GROUPS[j],GROUPS[j-1]);
        }
        strcpy(NAME[j],name);
        strcpy(NUMBER[j],number);
        strcpy(GROUPS[j],group);
    }
    count++;
    return INFO;
}

void List_swap(int j)
{
    char tmp1[Contact_LEN];
    strcpy(tmp1,NAME[j]); strcpy(NAME[j],NAME[j+1]); strcpy(NAME[j+1],tmp1);
    char tmp2[phone_LEN];
    strcpy(tmp2,NUMBER[j]); strcpy(NUMBER[j],NUMBER[j+1]); strcpy(NUMBER[j+1],tmp2);
    char tmp3[group_LEN];
    strcpy(tmp3,GROUPS[j]); strcpy(GROUPS[j],GROUPS[j+1]); strcpy(GROUPS[j+1],tmp3);
}

List List_import(List INFO)
{
    int k;
    for(k=0;k<CONTACTMAX;k++) memset(NAME[k],'\0',Contact_LEN);
    for(k=0;k<CONTACTMAX;k++) memset(NUMBER[k],'\0',phone_LEN);
    for(k=0;k<CONTACTMAX;k++) memset(GROUPS[k],'\0',group_LEN);
    FILE *fp;
    sprintf(filename,"data/Contact_data/%s.txt",username);
    fp=fopen(filename,"r");
    int j=0,i;
    count=0;
    while(fgets(name,Contact_LEN,fp)!=NULL)
    {
        fgets(number,phone_LEN,fp);
        fgets(group,group_LEN,fp);
        for(i=0;name[i]!='\n';i++);   name[i]='\0';      strcpy(NAME[j],name);
        for(i=0;number[i]!='\n';i++); number[i]='\0';    strcpy(NUMBER[j],number);
        for(i=0;group[i]!='\n';i++);  group[i]='\0';     strcpy(GROUPS[j],group);
        j++;
        count++;
    }
    for(i=0;i<count-1;i++)
    {
        for(j=0;j<count-i-1;j++)
        {
            if(strcmp(NAME[j],NAME[j+1])>0)
                List_swap(j);
        }
    }
    for(i=0;i<count;i++)
    {
        NODE *p=(NODE *)malloc(sizeof(NODE));
        strcpy(p->name,NAME[i]);
        strcpy(p->number,NUMBER[i]);
        strcpy(p->group,GROUPS[i]);
        INFO.tail->next=p;
        INFO.tail=p;
    }
    fclose(fp);
    return INFO;
}

Status List_save(List INFO)
{
    FILE *fp;
    sprintf(filename,"data/Contact_data/%s.txt",username);
    fp=fopen(filename,"w");
    NODE *p=(NODE *)malloc(sizeof(NODE));
    p=INFO.head->next;
    while(p)
    {
        fputs(p->name,fp);
        fputc('\n',fp);
        fputs(p->number,fp);
        fputc('\n',fp);
        fputs(p->group,fp);
        fputc('\n',fp);
        p=p->next;
    }
    fclose(fp);
    return OK;
}

void List_showarray()
{
    int i;
    for(i=0;i<count;i++)
    {
        puts(NAME[i]);
        puts(NUMBER[i]);
        puts(GROUPS[i]);
        putchar('\n');
    }
}

void List_showList()
{
    NODE *p=(NODE *)malloc(sizeof(NODE));
    p=INFO.head->next;
    while(p)
    {
        puts(p->name);
        puts(p->number);
        puts(p->group);
        putchar('\n');
        p=p->next;
    }
}

void List_showGroup(char iscount[][group_LEN],int groupnum[])
{
    int i;
    for(i=0;i<num;i++)
    {
        puts(iscount[i]);
        printf("%d",groupnum[i]);
        putchar('\n');
    }
}
