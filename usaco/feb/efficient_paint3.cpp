#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

int n,glo,sz=2;
char board[50][50],color[50][50],init[50][50][50];

bool g(int x1,int y1,int x2,int y2)
{
for(int i=x1;i<=x2;i++)
for(int j=y1;j<=y2;j++)
if(color[i][j] || board[i][j]==init[glo][i][j])
return false;
return true;
}

int f(int x,int y,int &llx,int &lly,int &urx,int &ury)
{
for(int i=n-x-1;i>=0;i--)
for(int j=n-y-1;j>=0;j--)
if(!color[x+i][y+j] && g(x,y,x+i,y+j))
{
llx=x;
lly=y;
urx=x+i;
ury=y+j;
return (i+1)*(j+1);
}
}

int main()
{
cin>>n;
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
cin>>board[i][j];
vector<vector<pair<int,int> > > ans1(sz),ans2(sz);
vector<vector<char> > clr(sz);
int tmp1,tmp2,x1,y1,x2,y2,tx1,ty1,tx2,ty2,curr_min1=100000000,target;
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
{
init[0][i][j]='W';
init[1][i][j]='B';
}
ans1[1].push_back(make_pair(0,0));
ans2[1].push_back(make_pair(n-1,n-1));
//clr[0].push_back('B');
for(int u=0;u<sz;u++)
{
glo=u;
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
color[i][j]=false;
while(1)
{
tmp1=-1;
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
if(color[i][j] || board[i][j]==init[u][i][j])
continue;
tmp2=f(i,j,tx1,ty1,tx2,ty2);
if(tmp2>tmp1)
{
tmp1=tmp2;
x1=tx1;
x2=tx2;
y1=ty1;
y2=ty2;
}
}
}
if(tmp1==-1)
break;
for(int i=x1;i<=x2;i++)
for(int j=y1;j<=y2;j++)
color[i][j]=true;
ans1[u].push_back(make_pair(x1,y1));
ans2[u].push_back(make_pair(x2,y2));
clr[u].push_back(board[x1][y1]);
int p=ans1[u].size()-1;
if(ans1[u].size()>curr_min1)
break;
}
if(ans1[u].size()<curr_min1)
{
curr_min1=ans1[u].size();
target=u;
}
}
printf("%d\n",ans1[target].size());
for(int i=0;i<ans1[target].size();i++)
printf("%d %d %d %d F\n",ans1[target][i].first,ans1[target][i].second,ans2[target][i].first,ans2[target][i].second);
return 0;
}
