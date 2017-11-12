#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int add()
{ int a,b;
      while(!scanf("%d",&a)||!scanf("%d",&b))
      {while((getchar())!='\n') continue; }
      return a+b;

  }
  int sub()
{ int a,b;
      while(!scanf("%d",&a)||!scanf("%d",&b))
      {while((getchar())!='\n') continue; }
      return a-b;

  }
 int mul()
{ int a,b;
     while(!scanf("%d",&a)||!scanf("%d",&b))
      {while((getchar())!='\n') continue; }
      return a*b;

  }
 int dif()
{ int a,b;
      while(!scanf("%d",&a)||!scanf("%d",&b))
      {while((getchar())!='\n') continue; }
      return a/b;

  }
  void help()
{
    while((getchar())!='\n') continue;printf("add sub mul div mod min max help quit\n");
  }
  int mod()
{ int a,b;
      while(!scanf("%d",&a)||!scanf("%d",&b))
      {while((getchar())!='\n') continue; }
      return a%b;

  }
 int max()
{ int a,b;
      while(!scanf("%d",&a)||!scanf("%d",&b))
      {while((getchar())!='\n') continue; }
      return a>b?a:b;

  }
  int min()
{ int a,b;
      while(!scanf("%d",&a)||!scanf("%d",&b))
      {while((getchar())!='\n') continue; }
      return a<b?a:b;

  }

int main()
{
    while(1)
    {   printf("input:");
        char a[10];
        scanf("%s",a);
        if(strcmp(a,"-add")==0) {printf("result %d\n",add());}
        else if(strcmp(a,"-sub")==0){printf("result %d\n",sub());}
        else if(strcmp(a,"-mul")==0){printf("result %d\n",mul());}
        else if(strcmp(a,"-dif")==0){printf("result %d\n",dif());}
        else if(strcmp(a,"-help")==0){help();}
        else if(strcmp(a,"-mod")==0){printf("result %d\n",mod());}
        else if(strcmp(a,"-min")==0){printf("result %d\n",min());}
        else if(strcmp(a,"-max")==0){printf("result %d\n",max());}
        else if(strcmp(a,"-quit")==0){break;}
}

}
