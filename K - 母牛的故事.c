#include<stdio.h>
int main()
{
	int fac[100];
	int i,n;
	while(scanf("%d",&n)!=EOF)
	{
		fac[1]=1;
		fac[2]=2;
		fac[3]=3;
		for(i=4;i<=n;i++)
		{
			fac[i]=fac[i-3]+fac[i-1];
		}
		printf("%d\n",fac[n]);
	}
	return 0;
}
