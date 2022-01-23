#include<stdio.h>
int main()
{
    int N,temp;
    int i=1,j=1,m=0,p=0,num=1;
    char s;
    scanf("%d %c",&N,&s);
    while(2*j*j-1<=N)
    {
        j++;
    }
    j--;
    p=2*j-1;
    temp=N-2*j*j+1;
    while(p>0)
	{
        for(i=0;i<m;i++)
            printf(" ");
        for(i=0;i<p;i++)
            printf("%c",s);
        printf("\n");
        m++;
        p-=2;
    }
	m--;
	p+=2;
	while(m>0)//输出沙漏下半部分
	{
        m--;
        p+=2;
        for(i=0;i<m;i++)
            printf(" ");
        for(i=0;i<p;i++)
            printf("%c",s);
        printf("\n");
    }
    printf("%d",temp);
    return 0;
}
