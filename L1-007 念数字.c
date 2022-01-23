#include<stdio.h>
int main()
{
    char N[100];
    scanf("%s",&N);
    int len=strlen(N);
    int i;
    for(i=0;i<len;i++)
    {
        if(N[i]=='-')
            printf("fu");
        else if(N[i]=='0')
            printf("ling");
        else if(N[i]=='1')
            printf("yi");
        else if(N[i]=='2')
            printf("er");
        else if(N[i]=='3')
            printf("san");
        else if(N[i]=='4')
            printf("si");
        else if(N[i]=='5')
            printf("wu");
        else if(N[i]=='6')
            printf("liu");
        else if(N[i]=='7')
            printf("qi");
        else if(N[i]=='8')
            printf("ba");
        else
            printf("jiu");
        if(i!=len-1)
            printf(" ");
    }
    return 0;
}
