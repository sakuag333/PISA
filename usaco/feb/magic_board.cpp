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
vector<int> rval(n+1),cval(n+1),rlast(n+1),clast(n+1),cset(q+1),rset(q+1);
int rowset[q+1][2],colset[q+1][2];
for(int i=1;i<=n;i++)
{
rval[i]=0;
cval[i]=0;
rlast[i]=0;
clast[i]=0;
}
cset[0]=0;
rset[0]=0;
rowset[0][0]=0;
rowset[0][1]=0;
colset[0][0]=0;
colset[0][1]=0;
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
colset[j][0]=colset[j-1][0];
colset[j][1]=colset[j-1][1];
rowset[j][0]=rowset[j-1][0];
rowset[j][1]=rowset[j-1][1];
cset[j]=cset[j-1];
rset[j]=rset[j-1];
scanf("%d",&i);
if(s=="RowQuery")
{
if(rval[i]==0)
cnt=n-(colset[j][1]-colset[rlast[i]][1])+(colset[j][0]-colset[rlast[i]][0]);
else
cnt=0-(colset[j][1]-colset[rlast[i]][1])+(colset[j][0]-colset[rlast[i]][0]);
}
else
{
if(cval[i]==0)
cnt=n-(rowset[j][1]-rowset[clast[i]][1])+(rowset[j][0]-rowset[clast[i]][0]);
else
cnt=0-(rowset[j][1]-rowset[clast[i]][1])+(rowset[j][0]-rowset[clast[i]][0]);
}
printf("%d\n",cnt);
}
else
{
scanf("%d%d",&i,&x);
if(s=="RowSet")
{
rset[j]=rset[j-1]+1;
cset[j]=cset[j-1];
if(rval[i]!=x || cset[j]-cset[rlast[i]]>0)
{
rval[i]=x;
rlast[i]=j;
rowset[j][x]=rowset[j-1][x]+1;
rowset[j][1-x]=rowset[j-1][1-x];
colset[j][x]=colset[j-1][x];
colset[j][1-x]=colset[j-1][1-x];
}
else
{
rlast[i]=j;
rowset[j][x]=rowset[j-1][x];
rowset[j][1-x]=rowset[j-1][1-x];
colset[j][x]=colset[j-1][x];
colset[j][1-x]=colset[j-1][1-x];
}
}
else
{
rset[j]=rset[j-1];
cset[j]=cset[j-1]+1;
if(cval[i]!=x || rset[j]-rset[clast[i]]>0)
{
cval[i]=x;
clast[i]=j;
colset[j][x]=colset[j-1][x]+1;
colset[j][1-x]=colset[j-1][1-x];
rowset[j][x]=rowset[j-1][x];
rowset[j][1-x]=rowset[j-1][1-x];
}
else
{
clast[i]=j;
colset[j][x]=colset[j-1][x];
colset[j][1-x]=colset[j-1][1-x];
rowset[j][x]=rowset[j-1][x];
rowset[j][1-x]=rowset[j-1][1-x];
}
}
}
//cout<<rowset[j][0]<<" "<<rowset[j][1]<<endl;
}
return 0;
}
