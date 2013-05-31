/*
ID: sakuag31
LANG: C++
TASK: inflate
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
#include<cstdlib>
#include<climits>
using namespace std;

map<pair<int,int>,bool> ck;
map<pair<int,int>,int> mp;
//vector<vector<int> > dp(10001);

inline int f_max(int a,int b)
{
if(a>=b)
return a;
return b;
}

/*int f(int m,int n)
{
if(m==0 || n==0)
return 0;
if(ck[make_pair(m,n)])
return mp[make_pair(m,n)];
ck[make_pair(m,n)]=true;
int t1=0,t2=0;
if(m-a[n][1]>=0)
t1=a[n][0]+f(m-a[n][1],n);
t2=f(m,n-1);
mp[make_pair(m,n)]=f_max(t1,t2);
return mp[make_pair(m,n)];
}*/

int main()
{
FILE *fin  = fopen ("inflate.in", "r");
FILE *fout = fopen ("inflate.out", "w");
int m,n;
fscanf(fin,"%d%d",&m,&n);
if(m*n>1000000)
{
double x,y;
vector<pair<double,pair<int,int> > > a(n);
for(int i=0;i<n;i++)
{
fscanf(fin,"%d%d",&a[i].second.first,&a[i].second.second);
x=a[i].second.first;
y=a[i].second.second;
cout<<x<<" "<<y<<endl;
a[i].first=y/x;
}
sort(a.begin(),a.end());
int val=0,tmp;
for(int i=0;i<n;i++)
{
if(a[i].second.second<=m)
{
cout<<a[i].second.second<<" "<<m<<endl;
tmp=m/a[i].second.second;
cout<<tmp<<endl;
val=val+tmp*a[i].second.first;
m=m-tmp*a[i].second.second;
}
}
fprintf(fout,"%d\n",val);
return 0;
}
int dp[m+1][n+1];
int a[n+1][2];
for(int i=1;i<=n;i++)
fscanf(fin,"%d%d",&a[i][0],&a[i][1]);
for(int i=0;i<=m;i++)
for(int j=0;j<=n;j++)
dp[i][j]=-1;
for(int i=0;i<=n;i++)
dp[0][i]=0;
for(int i=0;i<=m;i++)
dp[i][0]=0;
for(int i=1;i<=m;i++)
for(int j=1;j<=n;j++)
{
if(i-a[j][1]>=0)
dp[i][j]=f_max(a[j][0]+dp[i-a[j][1]][j],dp[i][j-1]);
else
dp[i][j]=dp[i][j-1];
}
fprintf(fout,"%d\n",dp[m][n]);
return 0;
}
