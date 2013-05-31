/*
ID: sakuag31
LANG: C++
TASK: ratios
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
#include<cmath>
using namespace std;

int y11,y2,y3,div1;
int a[4][3],a1[3];
int b[3];
vector<pair<int,pair<int,pair<int,int> > > > v;

int gcd(int a,int b)
{
if(b==0)
return a;
return gcd(b,a%b);
}

int f_gcd(int x,int y)
{
if(x>=y)
return gcd(x,y);
return gcd(y,x);
}

void lowest(int k[])
{
y11=k[0];
y2=k[1];
y3=k[2];
div1=f_gcd(y11,y2);
div1=f_gcd(y3,div1);
k[0]/=div1;
k[1]/=div1;
k[2]/=div1;
}

bool g(int q,int w,int e)
{
if(q+w+e==0)
return false;
for(int i=0;i<3;i++)
b[i]=q*a[1][i]+w*a[2][i]+e*a[3][i];
//lowest(b);
int div2=0;
for(int i=0;i<3;i++)
{
if(b[i]==0 && a1[i]==0)
continue;
if((b[i]!=0 && a1[i]==0 ) || b[i]%a1[i]!=0)
return false;
div2=b[i]/a1[i];
}
if(div2==0)
return false;
for(int i=0;i<3;i++)
{
if(b[i]%div2!=0 || a1[i]!=(b[i]/div2))
return false;
}
return true;
}

void f()
{
for(int i=0;i<100;i++)
for(int j=0;j<100;j++)
for(int k=0;k<100;k++)
if(g(i,j,k))
v.push_back(make_pair(i+j+k,make_pair(i,make_pair(j,k))));
}

int main()
{
FILE *fin  = fopen ("ratios.in", "r");
FILE *fout = fopen ("ratios.out", "w");
for(int i=0;i<3;i++)
fscanf(fin,"%d",&a1[i]);
for(int i=1;i<=3;i++)
for(int j=0;j<3;j++)
fscanf(fin,"%d",&a[i][j]);
int ta[3];
for(int i=0;i<3;i++)
ta[i]=a1[i];
//lowest(a1);
f();
if(v.size()==0)
{
fprintf(fout,"NONE\n");return 0;
}
sort(v.begin(),v.end());
int r1=v[0].second.first,r2=v[0].second.second.first,r3=v[0].second.second.second;
int factor=(r1*a[1][0]+r2*a[2][0]+r3*a[3][0])/ta[0];
fprintf(fout,"%d %d %d %d\n",r1,r2,r3,factor);
return 0;
}
