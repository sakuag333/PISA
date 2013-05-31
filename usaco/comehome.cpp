/*
ID: sakuag31
LANG: C++
TASK: comehome
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
#include<cstdlib>
#include<climits>
using namespace std;

map<pair<char,char>,int> graph;
vector<char> node;

void dijkstra(map<char,int> &dist)
{
map<char,bool> color;
for(int i=0;i<node.size();i++)
{
color[node[i]]=false;
dist[node[i]]=INT_MAX;
}
char curr='Z';
dist[curr]=0;
color[curr]=true;
char min1;
int val1;
while(1)
{
for(int i=0;i<node.size();i++)
if(!color[node[i]] && graph[make_pair(curr,node[i])]>0)
if(dist[node[i]]>dist[curr]+graph[make_pair(curr,node[i])])
dist[node[i]]=dist[curr]+graph[make_pair(curr,node[i])];
min1='#';
val1=INT_MAX;
for(int i=0;i<node.size();i++)
if(!color[node[i]] && dist[node[i]]<val1)
{min1=node[i];val1=dist[node[i]];}
if(min1=='#')
break;
curr=min1;
color[curr]=true;
}
}

void f(int &ret,char &cow)
{
map<char,int> dist;
dijkstra(dist);
for(int i=0;i<node.size();i++)
{
if(isupper(node[i]) && node[i]!='Z')
if(dist[node[i]]<ret)
{ret=dist[node[i]];cow=node[i];}
}
}

int main()
{
FILE *fin  = fopen ("comehome.in", "r");
FILE *fout = fopen ("comehome.out", "w");
int n;
fscanf(fin,"%d",&n);
bool a[26],b[26];
for(int i=0;i<26;i++)
{
a[i]=false;
b[i]=false;
}
char x,y,t;
int z;
for(int i=0;i<n;i++)
{
fscanf(fin,"%c",&x);
fscanf(fin,"%c%c%c%c%d",&x,&t,&y,&t,&z);
//cout<<x<<" "<<y<<" "<<z<<endl;
if(isupper(x))
a[x-'A']=true;
else
b[x-'a']=true;
if(isupper(y))
a[y-'A']=true;
else
b[y-'a']=true;
if(graph[make_pair(x,y)]==0 || z<graph[make_pair(x,y)])
{
graph[make_pair(x,y)]=z;
graph[make_pair(y,x)]=z;
}
}
for(int i=0;i<26;i++)
{
if(a[i])
node.push_back('A'+i);
if(b[i])
node.push_back('a'+i);
}
char cow;
int value=INT_MAX;
f(value,cow);
fprintf(fout,"%c %d\n",cow,value);
return 0;
}
