/*
ID: sakuag31
LANG: C++
TASK: maze1
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
#include<queue>
#include<fstream>
using namespace std;

queue<pair<int,int> > q;
vector<vector<int> > graph(3803);
int r,c,exit1[2],tmp=0;

inline int f(int row,int col)
{
if(row<=0 || col<=0 || row>=2*r || col>=2*c)
{
if(tmp==1)
return r*c;
return 1+r*c;
}
return c*(row/2)+(col/2);
}

inline int bfs(int source,int dest)
{
bool color[r*c+2];
for(int i=0;i<=r*c+1;i++)
color[i]=false;
while(!q.empty())
q.pop();
q.push(make_pair(source,0));
color[source]=true;
pair<int,int> pr;
while(!q.empty())
{
pr=q.front();
q.pop();
if(pr.first==dest)
return pr.second;
for(int i=0;i<graph[pr.first].size();i++)
{
if(color[graph[pr.first][i]])
continue;
color[graph[pr.first][i]]=true;
q.push(make_pair(graph[pr.first][i],1+pr.second));
}
}
}

inline int calc()
{
int val1,val2;
int val=-1,tmp1;
for(int i=0;i<r*c;i++)
{
val1=bfs(i,r*c);
if(val1<=val)
continue;
val2=bfs(i,1+r*c);
if(val1<=val2)
tmp1=val1;
else
tmp1=val2;
if(tmp1>val)
val=tmp1;
}
return val;
}


int main()
{
//ifstream fin ("maze.in");
FILE *fin  = fopen ("maze1.in", "r");
FILE *fout = fopen ("maze1.out", "w");
fscanf(fin,"%d%d",&c,&r);
//string str;
//c=8;
//r=7;
//getline(fin,str);
char tmp1;
fscanf(fin,"%c",&tmp1);
//char a[2*r+1][2*c+2];
//cout<<c<<r<<endl;
char a[202][82];
for(int i=0;i<2*r+1;i++)
{
for(int j=0;j<2*c+2;j++)
fscanf(fin,"%c",&a[i][j]);
//fin.getline(&a[i][0],2*c+3);
}
/*for(int i=0;i<2*r+1;i++)
{
for(int j=0;j<2*c+2;j++)
cout<<a[i][j];
}*/
for(int i=1;i<2*r+1;i+=2)
{
for(int j=1;j<2*c+1;j+=2)
{
if(a[i-1][j]!='-' && i-1==0)
{exit1[tmp]=f(i-1,j);tmp++;}
if(a[i-1][j]!='-')
graph[f(i,j)].push_back(f(i-2,j));

if(a[i+1][j]!='-' && i+1==2*r)
{exit1[tmp]=f(i+1,j);tmp++;}
if(a[i+1][j]!='-')
graph[f(i,j)].push_back(f(i+2,j));

if(a[i][j-1]!='|' && j-1==0)
{exit1[tmp]=f(i,j-1);tmp++;}
if(a[i][j-1]!='|')
graph[f(i,j)].push_back(f(i,j-2));

if(a[i][j+1]!='|' && j+1==2*c)
{exit1[tmp]=f(i,j+1);tmp++;}
if(a[i][j+1]!='|')
graph[f(i,j)].push_back(f(i,j+2));
}
}
/*for(int i=0;i<=1+r*c;i++)
{
cout<<i<<" : ";
for(int j=0;j<graph[i].size();j++)
{
cout<<graph[i][j]<<" ";
}
cout<<endl;
}*/
//int w=calc();
//cout<<w<<endl;
fprintf(fout,"%d\n",calc());
return 0;
}
