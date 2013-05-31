/*
ID: sakuag31
LANG: C++
TASK: butter
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
#include<queue>
#include<climits>
#include<set>
using namespace std;

int n,p,c;
int cow[510];
vector<vector<pair<int,int> > > graph(802);
set<pair<int,int> > s;
int cow_path[510][802];
bool color[802];
int dist[802][802];


void dijkstra(int source)
{
s.clear();
for(int i=1;i<=p;i++)
{color[i]=false;dist[source][i]=INT_MAX;s.insert(make_pair(INT_MAX,i));}
dist[source][source]=0;
s.erase(make_pair(INT_MAX,source));
s.insert(make_pair(0,source));
color[source]=true;
int curr=source;
int min1;
while(1)
{
s.erase(make_pair(dist[source][curr],curr));
for(int i=0;i<graph[curr].size();i++)
if(!color[graph[curr][i].first] && dist[source][graph[curr][i].first]>dist[source][curr]+graph[curr][i].second)
{
s.erase(make_pair(dist[source][graph[curr][i].first],graph[curr][i].first));
dist[source][graph[curr][i].first]=dist[source][curr]+graph[curr][i].second;
s.insert(make_pair(dist[source][graph[curr][i].first],graph[curr][i].first));
}
if(s.size()==0)
{
break;
}
curr=(*(s.begin())).second;
color[curr]=true;
}
}

int f()
{
int min1=INT_MAX;
int tmp;
for(int i=1;i<=n;i++)
dijkstra(cow[i]);
for(int i=1;i<=p;i++)
{
tmp=0;
for(int j=1;j<=n;j++)
{
if(dist[cow[j]][i]==INT_MAX)
{tmp=INT_MAX;break;}
tmp+=dist[cow[j]][i];
}
if(tmp<min1)
min1=tmp;
}
return min1;
}

int main()
{
FILE *fin  = fopen ("butter.in", "r");
FILE *fout = fopen ("butter.out", "w");
int t1,t2,t3;
fscanf(fin,"%d%d%d",&n,&p,&c);
for(int i=1;i<=n;i++)
fscanf(fin,"%d",&cow[i]);
for(int i=0;i<c;i++)
{
fscanf(fin,"%d%d%d",&t1,&t2,&t3);
graph[t1].push_back(make_pair(t2,t3));
graph[t2].push_back(make_pair(t1,t3));
}
int ans=f();
fprintf(fout,"%d\n",ans);
return 0;
}
