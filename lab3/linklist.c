#include"linklist.h"
#include<stdio.h>
int showcmd(tdatanode *head)
{
    printf("menu list:\n");
    tdatanode *p=head;
    while(p!=NULL)
    {
        printf("%-10s %-30s\n",p->cmd,p->desc);
        p=p->next;
    }
    return 0;
}

tdatanode * findcmd(tdatanode * head,char * cmd)
{
    if(head==NULL||cmd==NULL)
    {
        return NULL;
    }
    tdatanode *p=head;
    while(p!=NULL)
    {
        if(strcmp(p->cmd,cmd)==0)
        {
            return p;
        }
        p=p->next;
    }
    if(p==NULL)
    return NULL;
}
