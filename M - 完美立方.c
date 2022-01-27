#include<stdio.h>
int s(int a)
{
	return a*a*a;
}
int main()
{
	int a=6,b=3,c=4,d=5,n;
	scanf("%d",&n);
	while(a<=n)
	{
		if (s(a)==s(b)+s(c)+s(d)&&b<=c&&c<=d)
			printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);			
		d++;
		if (d>n)
		{
			d=2;
			c++;
		}
		if (c>n)
		{
			c=2;
			b++;
		}
		if (b>n)
		{
			b=2;
			a++;
		}
	}
	return 0;
}
