/*
ID: sakuag31
LANG: C++
TASK: ariprog
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>
#include<map>
#include<set>
using namespace std;

int main()
{
FILE *fin  = fopen ("ariprog.in", "r");
FILE *fout = fopen ("ariprog.out", "w");
int n,m;
//for(int n=3;n<=20;n++)
//{
fscanf(fin,"%d%d",&n,&m);
//scanf("%d%d",&n,&m);
set<int> v;
for(int i=0;i<=m;i++)
for(int j=0;j<=m;j++)
v.insert(i*i+j*j);
set<int>::iterator it,it1,it2;
int min1;
if(n<=3)
min1=1;
else if(n<=5)
min1=4;
else if(n<=11)
min1=12;
else if(n<=21)
min1=84;
else
min1=2772;
/*set<int> df;
for(it1=v.begin();it1!=v.end();it1++)
{
for(it2=v.begin();it2!=v.end();it2++)
{
if(*it2>*it1)
df.insert((*it2)-(*it1));
}
}
for(it=df.begin();it!=df.end();it++)
fprintf(fout,"%d\n",*it);*/

int cnt,f,next;
map<int,bool> mp;
vector<pair<int,int> > ans;
int diff;
int max1;
for(it=v.begin();it!=v.end();it++)
{max1=*it;mp[*it]=true;}
for(it=v.begin();it!=v.end();it++)
{
//it2=it;
//it2++;
//for(it1=it2;it1!=v.end();it1++)
for(int i=(*it)+min1;i<=max1;i+=min1)
{
if(!mp[i])
continue;
//cout<<*it1<<" ="<<endl;
diff=i-(*it);
f=*it;
next=f+diff;
cnt=1;
while(cnt<n)
{
if(mp[next])
{
//cout<<next<<" ";
cnt++;
next+=diff;
}
else
break;
}
//if(cnt>1)
//cout<<endl;
if(cnt==n)
ans.push_back(make_pair(diff,f));
if(ans.size()>10000)
break;
}
if(ans.size()>10000)
break;
}
sort(ans.begin(),ans.end());
//cout<<ans[0].first<<endl;
for(int i=0;i<ans.size();i++)
fprintf(fout,"%d %d\n",ans[i].second,ans[i].first);
if(ans.size()==0)
fprintf(fout,"NONE\n");
//}
return 0;
}
