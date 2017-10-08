typedef struct datanode
{
    char *cmd;
    char *desc;
    int (*func)();
    struct datanode * next;
}tdatanode;

int showcmd(tdatanode *);
tdatanode * findcmd(tdatanode *,char *);
