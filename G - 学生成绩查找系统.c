#include<stdio.h>
#include<string.h>
struct student
{
    char name[20];
    int score;
}stu[100];
int main()
{
 int i,m=0;
 char str[20];
 char a[20];
 int  flag;
    while(scanf("%s",str))
    {        
            if(strcmp(str,"insert")==0)
           {
            scanf("%s %d",&stu[m].name,&stu[m].score);
            m++;
           }
        if(strcmp(str,"find")==0)
        {
            scanf("%s", a);
            flag = 1;
               for(i=0;i<m;i++)
			   {
			   if(strcmp(a,stu[i].name)==0)
			   {
			   printf("%d\n",stu[i].score);  
			   flag=0;
			   break;
			   }
			   }
            if(flag==1)
                printf("-1\n");
        }
        if(strcmp(str,"end")==0)
		break;
    }
    return 0;
}
