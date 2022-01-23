#include<stdio.h>
int main()
{
    char N[10001];
    int i,a[10];
    scanf("%s",&N);
    for(i=0;i<strlen(N);i++)
        a[N[i]-'0']++;
    for(i=0;i<10;i++)
    {
        if(a[i]!=0)
            printf("%d:%d\n",i,a[i]);
    }
    return 0;
}
