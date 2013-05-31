#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<stdio.h>
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
inp(n);
inp(q);
vector<pair<pair<int,int>,int> > line(n+q),query(q);
vector<pair<int,int> > pts(n);
int tmp;
set<pair<int,int> > s;
vector<int> qry(q);
set<pair<int,int> >::iterator it1,it2,it;
for(int i=0;i<n;i++)
{
inp(line[i].first.first);
inp(line[i].first.second);
line[i].second=i;
pts[i].first=line[i].first.first;
pts[i].second=line[i].first.second;
}
for(int i=0;i<q;i++)
{
inp(line[n+i].first.first);
inp(line[n+i].first.second);
inp(tmp);
query[i].first.first=line[n+i].first.first;
query[i].first.second=line[n+i].first.second;
query[i].second=tmp;
/**/line[n+i].first.first+=tmp;
line[n+i].second=n+i;
//line[n+q+i].first.first=line[n+i].first.first+tmp;
//line[n+q+i].first.second=line[n+i].first.second;
//line[n+q+i].second=n+q+i;
}
sort(line.begin(),line.end());
for(int i=0;i<n+q;i++)
{
if(line[i].second<n)
s.insert(make_pair(line[i].first.first+line[i].first.second,line[i].second));
else/**/
{
it1=s.begin();
it2=s.upper_bound(make_pair(line[i].first.first+line[i].first.second,10000000));
while(it1!=it2)
{
if(pts[(*it1).second].first>=query[line[i].second-n].first.first && pts[(*it1).second].second>=query[line[i].second-n].first.second)
qry[line[i].second-n]++;
it1++;
}
}
}
for(int i=0;i<q;i++)
printf("%d\n",qry[i]);
return 0;
}
