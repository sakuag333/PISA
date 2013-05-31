#include<iostream>
#include<stdio.h>
using namespace std;
 
int n,t;
long long int rem=1000000007,a[3][3],b[3][3],c[3][3];
 
inline void initialize(long long int d[][3])
{
d[0][0]=1;
d[0][1]=2;
d[0][2]=3;
d[0][3]=1;
d[1][0]=1;
d[1][1]=0;
d[1][2]=0;
d[1][3]=0;
d[2][0]=0;
d[2][1]=1;
d[2][2]=0;
d[2][3]=0;
d[3][0]=0;
d[3][1]=0;
d[3][2]=1;
d[3][3]=0;
}
 
inline void mat_mul()
{
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
c[i][j]=0;
for(int k=0;k<3;k++)
{
c[i][j]=(c[i][j]+(a[i][k]*b[k][j])%rem)%rem;
}
}
}
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
a[i][j]=c[i][j];
}
}
}
 
inline void mat_sq()
{
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
c[i][j]=0;
for(int k=0;k<3;k++)
{
c[i][j]=(c[i][j]+(a[i][k]*a[k][j])%rem)%rem;
}
}
}
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
a[i][j]=c[i][j];
}
}
}
 
void f(int x)
{
if(x==1)
{
initialize(a);
return;
}
f(x/2);
mat_sq();
if(x%2==1)
mat_mul();
}
 
 
int main()
{
initialize(b);
scanf("%d",&t);
for(int i=0;i<t;i++)
{
scanf("%d",&n);
if(n<5)
{
if(n==1)
printf("1\n");
else if(n==2)
printf("2\n");
else if(n==3)
printf("5\n");
else if(n==4)
printf("12\n");
}
else
{
f(n-4);
printf("%lld\n",((a[0][0]*12)%rem+(5*a[0][1])%rem+(2*a[0][2])%rem+a[0][3])%rem);
}
}
return 0;
} 
