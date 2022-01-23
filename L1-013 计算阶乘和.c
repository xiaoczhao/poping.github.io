#include<stdio.h>
int fac(int n)
{
    int i;
    int sum=1;
    for(i=1;i<=n;i++)
    {
        sum*=i;
    }
    return sum;
}
int main()
{
    int i,n;
    int sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        sum+=fac(i);
    }
    printf("%d",sum);
    return 0;
}
