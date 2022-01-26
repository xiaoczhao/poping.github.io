#include<stdio.h>
int main()
{
 int n;
 scanf("%d",&n);
 int a,b,c;
 int s=0;
 for(a=0;5*a<=n;a++)
 {
  for(b=0;3*b<=n;b++)
  {
   for(c=0;c<=n;c+=3)
   {
    if(a+b+c==n&&a*5+b*3+c/3==n)
	{
     printf("%d %d %d\n",a,b,c);
     s++;
    }
   }
  }
 }
 if(s==0)
 {
  printf("No Answer.");
 }
 return 0;
}
