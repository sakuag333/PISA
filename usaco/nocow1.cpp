/*
ID: sakuag31
LANG: C++
TASK: nocows
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
#include<cstdlib>
using namespace std;

int n,k,cnt=0,mod=9901;
//map<pair<pair<int,int>,int>,bool> ck;
//map<pair<pair<int,int>,int>,int> mp;

int mp[201][101][102];

int g(int n,int r)
{
int tmp=1;
for(int i=1;i<=r;i++)
{
tmp=((tmp*(n-i+1))/i);
}
return tmp%mod;
}

int f(int h,int val,int lim)
{
if(h>k || val>n)
return 0;
//cout<<val<<" "<<h<<" "<<lim<<endl;
if(h==k && val==n)
return 1;
if(mp[val][h][lim/2]!=-1)
return mp[val][h][lim/2];
//if(ck[make_pair(make_pair(h,val),lim)])
//return mp[make_pair(make_pair(h,val),lim)];
//ck[make_pair(make_pair(h,val),lim)]=true;
int tmp=0;
for(int i=2;i<=lim;i+=2)
tmp=(tmp+((g(lim/2,i/2))*(f(h+1,val+i,2*i)%mod)%mod))%mod;
mp[val][h][lim/2]=tmp;
return tmp;
}

int main()
{
FILE *fin  = fopen ("nocows.in", "r");
FILE *fout = fopen ("nocows.out", "w");
fscanf(fin,"%d%d",&n,&k);
if(n%2==0)
{fprintf(fout,"0\n");return 0;}
for(int i=0;i<=n;i++)
for(int j=0;j<=k;j++)
for(int l=0;l<=(n/2)+1;l++)
mp[i][j][l]=-1;
int ans=f(1,1,2);
fprintf(fout,"%d\n",ans%mod);
return 0;
}
