#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<stdio.h>
#include<map>
#include<climits>
using namespace std;
 
char b;
inline void inp(int &u)
{
u=0;
b=getchar_unlocked();
while(b>='0' && b<='9')
{
u=(u<<3)+(u<<1)+(b-'0');
b=getchar_unlocked();
}
}
 
int main()
{
int n,q;
scanf("%d%d",&n,&q);
vector<pair<int,int> > seg;
vector<pair<pair<int,int>,int> > qry(q),line(n+2*q);
set<pair<int,int> > s,s1;
vector<int> sorted,sorted2;
int revsorted[2000000];
 
for(int i=0;i<n;i++)
{
scanf("%d%d",&line[2*q+i].first.first,&line[2*q+i].first.second);
line[2*q+i].second=2*q+i;
}
for(int i=0;i<q;i++)
{
scanf("%d%d%d",&qry[i].first.first,&qry[i].first.second,&qry[i].second);
line[i].first.first=qry[i].first.first;
line[i].first.second=qry[i].first.second;
line[i].second=i;
line[q+i].first.first=qry[i].first.first+qry[i].second;
line[q+i].first.second=qry[i].first.second;
line[q+i].second=q+i;
//sorted[i].first=line[i].first.first+line[i].first.second+qry[line[i].second].second;
//sorted[i].second=i;
//sorted2[i].first=line[i].first.second;
//sorted2[i].second=i;
}
//sort(sorted.begin(),sorted.end());
//sort(sorted2.begin(),sorted2.end());
sort(line.begin(),line.end());
set<pair<int,int> >::iterator it1;
set<pair<int,int> >::reverse_iterator it2;
vector<int> trirect(q),rect(q);
vector<int> ck(q);
 
for(int i=1;i<n+2*q;i++)
{
//cout<<line[i].second<<" "<<line[i-1].second<<" "<<line[i].first.first<<" " <<line[i-1].first.first<<" "<<line[i].first.second<<" "<<line[i-1].first.second<<endl;
if(line[i].second>=2*q && line[i-1].second>=q && line[i].first.first==line[i-1].first.first && line[i].first.second==line[i-1].first.second)
ck[line[i-1].second-q]++;
}
 
int ind=0;
 
//for(int i=0;i<q;i++)
//revsorted[sorted[i].second]=i;
 
for(int i=0;i<n+2*q;i++)
{
if(line[i].second>=2*q)
{
it1=s.lower_bound(make_pair(line[i].first.first+line[i].first.second,-1));
it2=s.rbegin();
if(it1!=s.end())
seg.push_back(make_pair((*it1).second,(*it2).second));
}
else
{
if(line[i].second<q)
{
revsorted[line[i].first.first+line[i].first.second+qry[line[i].second].second]=sorted.size();
s.insert(make_pair(line[i].first.first+line[i].first.second+qry[line[i].second].second,sorted.size()));
sorted.push_back(i);
}
else
s.erase(make_pair(line[i].first.first+line[i].first.second,revsorted[line[i].first.first+line[i].first.second]));
}
}
for(int i=0;i<seg.size();i++)
{
trirect[seg[i].first]++;
if(1+seg[i].second<q)
trirect[1+seg[i].second]--;
}
int cnt=0;
for(int i=0;i<q;i++)
{
cnt+=trirect[i];
trirect[i]=cnt;
}
vector<int> plus(q),minus(q);
for(int i=0;i<q;i++)
plus[sorted[i]]=trirect[i];
 
//for(int i=0;i<q;i++)
//revsorted[sorted2[i].second]=i;
ind=0;
//s.clear();
seg.clear();
for(int i=0;i<n+2*q;i++)
{
if(line[i].second>=2*q)
{
it1=s1.upper_bound(make_pair(line[i].first.second,10000000));
it2=s1.rbegin();
if(it1!=s1.end())
seg.push_back(make_pair((*it1).second,(*it2).second));
}
else
{
if(line[i].second<q)
{
revsorted[line[i].first.second]=sorted2.size();
s1.insert(make_pair(line[i].first.second,sorted2.size()));
sorted2.push_back(i);
}
else
s1.erase(make_pair(line[i].first.second,revsorted[line[i].first.second]));
}
}
for(int i=0;i<seg.size();i++)
{
rect[seg[i].first]++;
if(1+seg[i].second<q)
rect[1+seg[i].second]--;
}
cnt=0;
for(int i=0;i<q;i++)
{
cnt+=rect[i];
rect[i]=cnt;
}
for(int i=0;i<q;i++)
minus[sorted2[i]]=rect[i];
 
for(int i=0;i<q;i++)
printf("%d\n",ck[i]+plus[i]-minus[i]);
 
return 0;
} 
/*
2 3 
2 1
2 2
1 3 1
2 2 1
1 3 2
*/
