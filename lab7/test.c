#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "linktable.h"

int quit();
int echo(int argc, char* argv[]);
int add(int argc,char *argv[]);
int sub(int argc,char *argv[]);
int mul(int argc,char *argv[]);
int divi(int argc,char *argv[]);

int main(int argc, char* argv)
{
    MenuConfig("quit","quit from the menu program", quit);
    MenuConfig("echo","printf all you input in the terminal", echo);
    MenuConfig("add","printf all you input in the terminal", add);
    MenuConfig("sub","printf all you input in the terminal", sub);
    MenuConfig("mul","printf all you input in the terminal", mul);
    MenuConfig("divi","printf all you input in the terminal", divi);

    ExecuteMenu();

    return 0;
}

int quit()
{
    exit(0);

    return 0;
}

int echo(int argc, char* argv[])
{
    int i;
    if(argc == 1)
    {
        printf("echo on\n");
    }

    for(i = 1;i < argc;i ++)
    {
        printf("%d:%s\n",i, argv[i]);
    }
    return 0;
}

int add(int argc, char* argv[])
{
    int i,r;
    if(argc !=3)
    {
        printf("warning input 2 numbers\n");
        return 0;
    }
    r=atoi(argv[1])+atoi(argv[2]);
    printf("result is %d\n",r);
    return 0;
}

int sub(int argc, char* argv[])
{
    int i,r;
    if(argc !=3)
    {
        printf("warning input 2 numbers\n");
        return 0;
    }
    r=atoi(argv[1])-atoi(argv[2]);
    printf("result is %d\n",r);
    return 0;
}

int mul(int argc, char* argv[])
{
    int i,r;
    if(argc !=3)
    {
        printf("warning input 2 numbers\n");
        return 0;
    }
    r=atoi(argv[1])*atoi(argv[2]);
    printf("result is %d\n",r);
    return 0;
}

int divi(int argc, char* argv[])
{
    int i;
    float r;
    if(argc !=3)
    {
        printf("warning input 2 numbers\n");
        return 0;
    }
    r=((float)atoi(argv[1]))/atoi(argv[2]);
    printf("result is %.2f\n",r);
    return 0;
}
