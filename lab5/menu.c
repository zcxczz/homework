
/**************************************************************************************************/
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  SA17225354                                                           */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * 2017/10/20
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include "linktable.h"

int Help();
int Quit();
int add();
int sub();
int mul();
int divi();
int max();
int min();
int mod();


#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10



/* data struct and its operations */
typedef struct DataNode
{
    tLinkTableNode * pNext;
    char*   cmd;
    char*   desc;
    int     (*handler)();
} tDataNode;

int SearchCondition(tLinkTableNode * pLinkTableNode,void * args)
{
    char * cmd=(char *)args;
    tDataNode * pNode = (tDataNode *)pLinkTableNode;
    if(strcmp(pNode->cmd, cmd) == 0)
    {
        return  SUCCESS;
    }
    return FAILURE;
}

/* find a cmd in the linklist and return the datanode pointer */
tDataNode* FindCmd(tLinkTable * head, char * cmd)
{
    return  (tDataNode*)SearchLinkTableNode(head,SearchCondition,cmd);
}

/* show all cmd in listlist */
int ShowAllCmd(tLinkTable * head)
{
    tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        printf("%s - %s\n", pNode->cmd, pNode->desc);
        pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    return 0;
}

int InitMenuData(tLinkTable ** ppLinktable)
{
    *ppLinktable = CreateLinkTable();
    tDataNode* pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "help";
    pNode->desc = "Menu List:";
    pNode->handler = Help;
    AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "version";
    pNode->desc = "Menu Program V4.0";
    pNode->handler = NULL;
    AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "add";
    pNode->desc = "this is an add cmd";
    pNode->handler = add;
    AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "sub";
    pNode->desc = "this ia a sub cmd";
    pNode->handler = sub;
    AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "mul";
    pNode->desc = "this is a mul cmd";
    pNode->handler = mul;
    AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "divi";
    pNode->desc = "this is a divi cmd";
    pNode->handler = divi;
    AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "max";
    pNode->desc = "this a max cmd";
    pNode->handler = max;
    AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "min";
    pNode->desc = "this is a min cmd";
    pNode->handler = min;
    AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "mod";
    pNode->desc = "this is a mod cmd";
    pNode->handler = mod;
    AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "quit";
    pNode->desc = "Quit from Menu Program V4.0";
    pNode->handler = Quit;
    AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);

    return 0;
}

/* menu program */

tLinkTable * head = NULL;

int main()
{
    InitMenuData(&head);
   /* cmd line begins */
    char cmd[CMD_MAX_LEN];
    while(1)
    {
        printf("Input a cmd number > ");
        scanf("%s", cmd);
        tDataNode *p = FindCmd(head, cmd);
        if( p == NULL)
        {
            printf("This is a wrong cmd!\n ");
            continue;
        }
        printf("%s - %s\n", p->cmd, p->desc);
        if(p->handler != NULL)
        {
            p->handler();
        }

    }
}

int Help()
{
    ShowAllCmd(head);
    return 0;
}

int Quit()
{
    exit(0);
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



int mod()
{
    printf("enter 2 int numbers: ");
    int a,b;
    scanf("%d%d",&a,&b);
    printf("result is %d: ",a%b);
    printf("\n");
    return 0;
}
