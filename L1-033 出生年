#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    int born[4];
    int year,a;
    scanf("%d%d",&year,&a);
    int b,count=0;
    for (b=year;b<4000;b++)
    {
    count=1;
    born[0]=b/1000;
    born[1]=b/100%10;
    born[2]=b/10%10;
    born[3]=b%10;
    if(born[0]!=born[1]&&born[0]!=born[2]&&born[0]!=born[3])
        count++;
    if(born[1]!=born[2]&&born[1]!=born[3])
        count++;
    if(born[2]!=born[3])
        count++;
        if(count==a)
            break;
}
printf("%d %04d",b-year,b);
system("pause");
return 0;
}
