#include<stdio.h>
#include<string.h>
struct student
{
    char a[20];
    int number1,number2;
};
int main()
{
    int n,i;
    scanf("%d",&n);
    struct student stu[10000];
    for(i=0;i<n;i++)
        scanf("%s%d%d",stu[i].a,&stu[i].number1,&stu[i].number2);
    int m;
    scanf("%d",&m);
    int s,j;
    for(i=0;i<m;i++)
    {
        scanf("%d",&s);
            for(j=0;;j++)
            {
                if(stu[j].number1==s)
                {
                    printf("%s %d\n",stu[j].a,stu[j].number2);
                    break;
                }
            }
    }
    return 0;
}
