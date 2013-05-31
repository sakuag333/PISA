#include<stdio.h>

int reverse_binary(int n)
{
int val=0;
while(n>0)
{
val*=2;
if(n%2==1)
val++;
n/=2;
}
return val;
}

int main()
{
int n;
scanf("%d",&n);
printf("%d\n",reverse_binary(n));
return 0;
}
