#include<iostream>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<set>
using namespace std;


void create(vector<int> &v1,vector<int> &v2,int a,int b,int ind)
{
v1[ind]=a;
v2[ind]=b;
if(a==b)
return;
create(v1,v2,a,(a+b)/2,2*ind+1);
create(v1,v2,1+((a+b)/2),b,2*ind+2);
}

void update(vector<int> &v1,vector<int> &v2,vector<int> &v3,int a,int b,int ind,int cnt)
{
//cout<<v1[ind]<<" "<<v2[ind]<<" "<<cnt<<endl;
if(v1[ind]==a && v2[ind]==b)
{
v3[ind]+=cnt;
//cout<<ind<<" "<<v3[ind]<<" "<<a<<" "<<b<<endl;
return;
}
v3[ind]+=cnt;
int mid=(v1[ind]+v2[ind])/2;
if(b<=mid)
update(v1,v2,v3,a,b,2*ind+1,cnt);
else if(a>mid)
update(v1,v2,v3,a,b,2*ind+2,cnt);
else
{
update(v1,v2,v3,a,mid,2*ind+1,cnt);
update(v1,v2,v3,1+mid,b,2*ind+2,cnt);
}
}

int query(vector<int> &v1,vector<int> &v2,vector<int> &v3,int a,int b,int ind)
{
//cout<<v1[ind]<<" "<<v2[ind]<<" "<<endl;
if(a>b)
return 0;
if(v1[ind]==a && v2[ind]==b)
{
//cout<<ind<<" "<<v3[ind]<<endl;
return v3[ind];
}
int mid=(v1[ind]+v2[ind])/2;
if(b<=mid)
return query(v1,v2,v3,a,b,2*ind+1);
else if(a>mid)
return query(v1,v2,v3,a,b,2*ind+2);
else
return query(v1,v2,v3,a,mid,2*ind+1) + query(v1,v2,v3,1+mid,b,2*ind+2);
}

inline int find_cnt(set<int> &s,int small,int large)
{
if(small>large)
return 0;
set<int>::iterator it1=s.lower_bound(small),it2=s.lower_bound(1+large);
return std::distance(it1,it2);
}

int main()
{
int n,q,i,x,cnt;
string s;
char x1;
scanf("%d%d",&n,&q);
vector<int> seg1(3*q+3),seg2(3*q+3),r0cnt(3*q+3),r1cnt(3*q+3),c0cnt(3*q+3),c1cnt(3*q+3);
create(seg1,seg2,1,q,0);
//vector<set<int> > rowset(2),colset(2);
vector<pair<int,int> > rlast(n+1),clast(n+1);
for(int i=1;i<=n;i++)
{
rlast[i].first=0;
clast[i].first=0;
rlast[i].second=0;
rlast[i].second=0;
}
int st,ed;
for(int j=1;j<=q;j++)
{
getchar();
s="";
while(1)
{
x1=getchar_unlocked();
if(x1==' ')
break;
s+=x1;
}
if(s=="RowQuery" || s=="ColQuery")
{
scanf("%d",&i);
if(s=="RowQuery")
{
st=1+rlast[i].first;
ed=j-1;
if(rlast[i].second==0)
{
cnt=n-query(seg1,seg2,c1cnt,st,ed,0);
//cnt=n-find_cnt(colset[1],st,ed);
/*minus colset[1] between st and ed*/
}
else
{
cnt=0+query(seg1,seg2,c0cnt,st,ed,0);
//cnt=0+find_cnt(colset[0],st,ed);
/*plus colset[0] between st and ed*/
}
}
else
{
st=1+clast[i].first;
ed=j-1;
if(clast[i].second==0)
{
//cout<<st<<" "<<ed<<" 0"<<endl;
cnt=n-query(seg1,seg2,r1cnt,st,ed,0);
//cnt=n-find_cnt(rowset[1],st,ed);
/*minus rowset[1] between st and ed*/
}
else
{
//cout<<st<<" "<<ed<<" 1"<<endl;
cnt=0+query(seg1,seg2,r0cnt,st,ed,0);
//cnt=0+find_cnt(rowset[0],st,ed);
/*plus rowset[0] between st and ed*/
}
}
printf("%d\n",cnt);
}
else
{
scanf("%d%d",&i,&x);
if(s=="RowSet")
{
if(rlast[i].first!=0)
{
if(rlast[i].second==0)
update(seg1,seg2,r0cnt,rlast[i].first,rlast[i].first,0,-1);
else
update(seg1,seg2,r1cnt,rlast[i].first,rlast[i].first,0,-1);
}
if(x==0)
update(seg1,seg2,r0cnt,j,j,0,1);
else
update(seg1,seg2,r1cnt,j,j,0,1);
rlast[i].first=j;
rlast[i].second=x;
}
else
{
if(clast[i].first!=0)
{
//cout<<"colset !"<<endl;
if(clast[i].second==0)
update(seg1,seg2,c0cnt,clast[i].first,clast[i].first,0,-1);
else
update(seg1,seg2,c1cnt,clast[i].first,clast[i].first,0,-1);
}
if(x==0)
{/*cout<<"colset 0"<<endl;*/update(seg1,seg2,c0cnt,j,j,0,1);}
else
{/*cout<<"colset 1"<<endl;*/update(seg1,seg2,c1cnt,j,j,0,1);}
clast[i].first=j;
clast[i].second=x;
}
}
}
return 0;
}
