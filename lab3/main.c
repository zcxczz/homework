/***************************************************/
/*FLLE NAME:mlh                                    */
/*LANGUAGE:C                                       */
/*AUTHOR:SA17225354                                */
/***************************************************/
/*Revision Log:1017/10/8
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include "linklist.h"
#define COM_LEN 128
#define DESC_LEN 1024
#define COM_NUM 10

int help();
int add();
int sub();
int mul();
int divi();
int max();
int min();
int avg();
int mod();
int quit();


static tdatanode head[]=
{
    {"help","this is a help command",help,&head[1]},
    {"version","this version is 2.0",NULL,&head[2]},
    {"add","this is an add command",add,&head[3]},
    {"sub","this is a sub command",sub,&head[4]},
    {"mul","this is a mul command",mul,&head[5]},
    {"divi","this is a divi command",divi,&head[6]},
    {"max","this is a max command",max,&head[7]},
    {"min","this is a min commmand",min,&head[8]},
    {"avg","this is a average command",avg,&head[9]},
    {"mod","this is a mod command",mod,&head[10]},
    {"quit","this is a quit",quit,NULL}
};

int main()
{
    while(1)
    {
        char cmd[COM_LEN];
        printf("input a cmd number >");
        scanf("%s",cmd);
        tdatanode *p=findcmd(head,cmd);
        if(p==NULL)
        {
            printf("this is a wrong commmand\n");
            continue;
        }
        printf("%-10s %-30s\n",p->cmd,p->desc);
        if(p->func!=NULL)
        {
            p->func();
        }

    }
}



int help()
{
   return showcmd(head);
}

int add()
{
    printf("enter 2 int numbers: ");
    int a,b;
    scanf("%d%d",&a,&b);
    printf("result is %d: ",a+b);
    printf("\n");
    return 0;
}

int sub()
{
    printf("enter 2 int numbers: ");
    int a,b;
    scanf("%d%d",&a,&b);
    printf("result is %d: ",a-b);
    printf("\n");
    return 0;
}

int mul()
{
    printf("enter 2 int numbers: ");
    int a,b;
    scanf("%d%d",&a,&b);
    printf("result is %d: ",a*b);
    printf("\n");
    return 0;
}

int divi()
{
    printf("enter 2 int numbers: ");
    int a,b;
    scanf("%d%d",&a,&b);
    printf("result is %d: ",a/b);
    printf("\n");
    return 0;
}

int max()
{
    printf("enter 2 int numbers: ");
    int a,b;
    scanf("%d%d",&a,&b);
    printf("result is %d: ",a>b?a:b);
    printf("\n");
    return 0;
}

int min()
{
    printf("enter 2 int numbers: ");
    int a,b;
    scanf("%d%d",&a,&b);
    printf("result is %d: ",a<b?a:b);
    printf("\n");
    return 0;
}

int avg()
{
    printf("enter 2 int numbers: ");
    int a,b;
    scanf("%d%d",&a,&b);
    printf("result is %d: ",(a+b)/2);
    printf("\n");
    return 0;
}

int mod()
{
    printf("enter 2 int numbers: ");
    int a,b;
    scanf("%d%d",&a,&b);
    printf("result is %d: ",a%b);
    printf("\n");
    return 0;
}

int quit()
{
    exit(0);
}
