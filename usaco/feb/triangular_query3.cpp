#include<iostream>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

void create(vector<int> &v1,vector<int> &v2,int a,int b,int ind)
{
v1[ind]=a;
v2[ind]=b;
if(a==b)
return;
create(v1,v2,a,(a+b)>>1,(ind<<1)+1);
create(v1,v2,1+((a+b)>>1),b,(ind<<1)+2);
}

void update(vector<int> &v1,vector<int> &v2,vector<int> &v3,int a,int b,int ind,int cnt)
{
if(v1[ind]==a && v2[ind]==b)
{
v3[ind]+=cnt;
return;
}
v3[ind]+=cnt;
int mid=(v1[ind]+v2[ind])>>1;
if(b<=mid)
update(v1,v2,v3,a,b,(ind<<1)+1,cnt);
else if(a>mid)
update(v1,v2,v3,a,b,(ind<<1)+2,cnt);
else
{
update(v1,v2,v3,a,mid,(ind<<1)+1,cnt);
update(v1,v2,v3,1+mid,b,(ind<<1)+2,cnt);
}
}

int query(vector<int> &v1,vector<int> &v2,vector<int> &v3,int a,int b,int ind)
{
if(a>b)
return 0;
if(v1[ind]==a && v2[ind]==b)
return v3[ind];
int mid=(v1[ind]+v2[ind])>>1;
if(b<=mid)
return query(v1,v2,v3,a,b,(ind<<1)+1);
else if(a>mid)
return query(v1,v2,v3,a,b,(ind<<1)+2);
else
return query(v1,v2,v3,a,mid,(ind<<1)+1) + query(v1,v2,v3,1+mid,b,(ind<<1)+2);
}

int main()
{
int n,q,tmp;
scanf("%d%d",&n,&q);
vector<pair<pair<int,int>,int> > line(n+2*q);
vector<int> dist(q),seg1(2200000),seg2(2200000),hyp(2200000),seg3(1100000),seg4(1100000),vert(1100000),qry(q);
for(int i=0;i<n;i++)
{
scanf("%d%d",&line[q+i].first.first,&line[q+i].first.second);
line[q+i].second=q+i;
}
for(int i=0;i<q;i++)
{
scanf("%d%d%d",&line[i].first.first,&line[i].first.second,&dist[i]);
line[i].second=i;
line[n+q+i].first.first=line[i].first.first+dist[i];
line[n+q+i].first.second=line[i].first.second;
line[n+q+i].second=n+q+i;
}
create(seg3,seg4,1,300010,0);
create(seg1,seg2,1,900010,0);
sort(line.begin(),line.end());
for(int i=0;i<n+2*q;i++)
{
if(line[i].second<q)
{
qry[line[i].second]-=query(seg1,seg2,hyp,1,line[i].first.first+line[i].first.second+dist[line[i].second],0);
qry[line[i].second]+=query(seg3,seg4,vert,1,line[i].first.second-1,0);
}
else if(line[i].second<n+q)
{
update(seg1,seg2,hyp,line[i].first.first+line[i].first.second,line[i].first.first+line[i].first.second,0,1);
update(seg3,seg4,vert,line[i].first.second,line[i].first.second,0,1);
}
else
{
qry[line[i].second-n-q]+=query(seg1,seg2,hyp,1,line[i].first.first+line[i].first.second,0);
qry[line[i].second-n-q]-=query(seg3,seg4,vert,1,line[i].first.second-1,0);
}
}
for(int i=0;i<q;i++)
printf("%d\n",qry[i]);
return 0;
}
