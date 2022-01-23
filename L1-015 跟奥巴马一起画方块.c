#include<stdio.h>
#include<string.h>
int main()
{
  int n,a,i,j;
  char b[10];
  scanf("%d",&n);
  scanf("%s",&b);
    if(n%2!=0)
        a=n/2+1;
    else
        a=n/2;
  for(i=1;i<=a;i++)
  {
      for(j=1;j<=n;j++)
          printf("%s",b);
      printf("\n");
  }
  return 0;
}
