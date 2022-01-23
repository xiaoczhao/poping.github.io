#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char a[10005];
    while(gets(a)!=NULL)
    {
        int k,x,m=0,n=0;
        int b=0,c=0;
        k=strlen(a);
        for(int i=0;i<k;i++)
        {
            if(a[i]==' ')
            {
                x=i;
                break;
            }
        }
        for(int i=0;i<x;i++)
        {
            if(a[i]<'0'||a[i]>'9')
            {
                m=1;
            }
        }
        for(int i=x+1;i<k;i++)
        {
            if(a[i]<'0'||a[i]>'9')
            {
                n=1;
            }
        }
        if(m==0)
        {
            for(int i=0;i<x;i++)
            {
                b=b+(a[i]-'0')*pow(10,x-i-1);
            }
            if(b==0||b>1000)
            {
                m=1;
            }
        }
        if(n==0)
        {
            for(int i=x+1;i<k;i++)
            {
                c=c+(a[i]-'0')*pow(10,k-1-i);
            }
            if(c==0||c>1000)
            {
                n=1;
            }
        }
        if(m==0)
        {
                printf("%d",b);
        }
        else
        {
            printf("?");
        }
        printf(" + ");
        if(n==0)
        {
                printf("%d",c);
        }
        else
        {
            printf("?");
        }
        printf(" = ");
        if(m==0&&n==0)
        {
            printf("%d",b+c);
        }
        else
        {
            printf("?");
        }
        printf("\n");
    }
    return 0;
}
