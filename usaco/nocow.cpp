/*
ID: sakuag31
LANG: C++
TASK: nocow
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
#include<cstdlib>
using namespace std;


/*---------WRONG--------*/

int n,k;
int cnt=0,mod=9901;

int f(int node,int height,int a[])
{
cout<<node<<" "<<height<<endl;
for(int i=1;i<=height;i++)
cout<<a[i]<<" ";
cout<<endl;
if(height>k || node>n)
return 0;
if(node==n && height==k)
return 1;
int tmp=0;
for(int i=1;i<height;i++)
{
if(a[i]==0)
continue;
a[i]--;
a[i+1]+=2;
tmp=(tmp+((1+a[i])*(f(node+2,height,a)%mod))%mod)%mod;
a[i]++;
a[i+1]-=2;
}
a[height]--;
a[height+1]+=2;
tmp=(tmp+((1+a[height])*(f(node+2,height+1,a)%mod))%mod)%mod;
a[height]++;
a[height+1]-=2;
return tmp;
}

int main()
{
FILE *fin  = fopen ("nocows.in", "r");
FILE *fout = fopen ("nocows.out", "w");
cin>>n>>k;
if(n%2==0)
{
cout<<"0"<<endl;
//fprintf(fout,"0\n");
return 0;
}
//fscanf(fin,"%d%d",&n,&k);
int a[201];
for(int i=1;i<=k;i++)
a[i]=0;
a[1]=1;
int ans=f(1,1,a);
cout<<ans<<endl;
//fprintf(fout,"%d\n",ans);
return 0;
}
