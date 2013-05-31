#include<iostream>
#include<stdio.h>
#include<cstring>
#include<vector>
using namespace std;

int main()
{
int n,q,i,x,cnt;
string s;
char x1;
scanf("%d%d",&n,&q);
vector<pair<pair<int,int>,int> > query;
int qry_cnt=0;
for(int j=1;j<=q;j++)
{
getchar();
s="";
while(1)
{
x1=getchar();
if(x1==' ')
break;
s+=x1;
}
if(s=="RowQuery" || s=="ColQuery")
{
scanf("%d",&i);
if(s=="RowQuery")
query.push_back(make_pair(make_pair(3,i),-1));
else
query.push_back(make_pair(make_pair(4,i),-1));
}
else
{
scanf("%d%d",&i,&x);
if(s=="RowSet")
query.push_back(make_pair(make_pair(1,i),x));
else
query.push_back(make_pair(make_pair(2,i),x));
}
}
qry_cnt=query.size();
vector<bool> rcolor(n+1),ccolor(n+1);
vector<int> rcnt(qry_cnt),ccnt(qry_cnt);
for(int i=1;i<=n;i++)
{
rcolor[i]=false;
ccolor[i]=false;
}
for(int i=0;i<qry_cnt;i++)
{
rcnt[i]=0;
ccnt[i]=0;
}
int row=0,col=0;
for(int i=query.size()-1;i>=0;i--)
{
rcnt[i]=row;
ccnt[i]=col;
if(query[i].first.first>2)
continue;
if(query[i].first.first==1 && !rcolor[query[i].first.second])
{rcolor[query[i].first.second]=true;row++;}
if(query[i].first.first==2 && !ccolor[query[i].first.second])
{ccolor[query[i].first.second]=true;col++;}
}
for(int i=0;i<qry_cnt;i++)
cout<<i<<" "<<rcnt[i]<<" "<<ccnt[i]<<endl;
return 0;
}
