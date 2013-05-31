/*
ID: sakuag31
LANG: C++
TASK: fact4
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
using namespace std;

int f5(int n)
{
int ret=0,tmp1=5;
while(tmp1<=n)
{
ret+=(n/tmp1);
tmp1*=5;
}
return ret;
}

int main()
{
FILE *fin  = fopen ("fact4.in", "r");
FILE *fout = fopen ("fact4.out", "w");
int n;
fscanf(fin,"%d",&n);
int cnt=f5(n);
int ans=1,tmp;
for(int i=2;i<=n;i++)
{
tmp=i;
while(tmp%2==0 && cnt>0)
{
tmp/=2;
cnt--;
}
while(tmp%5==0)
tmp/=5;
ans*=tmp;
ans%=10;
}
fprintf(fout,"%d\n",ans);
return 0;
}
