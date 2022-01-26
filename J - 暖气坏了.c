#include<stdio.h>
int main()
{
	int n,m,i;
	int a[10000],s=0;
	scanf("%d %d",&n,&m);
	for (i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (i=1;i<n;i++)
	{
		if (a[i]-a[i-1]<=m)
		s+=a[i]-a[i-1];
		if (a[i]-a[i-1]>m)
		s+=m;
	}
	s+=m;
	printf("%d",s);
}
