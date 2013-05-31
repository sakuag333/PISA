/*
ID: sakuag31
LANG: C++
TASK: cowtour
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
#include<cmath>
using namespace std;

int n;
double coord[152][2];
int adj[152][152];
bool color[152];
int cnt_comp;
vector<vector<int> > comp(152);
double path[152][152];

double dist(int a,int b)
{
long double t1=coord[a][0]-coord[b][0],t2=coord[a][1]-coord[b][1];
long double t3= sqrt(t1*t1+t2*t2);
//cout<<t1*t1+t2*t2<<endl;
return t3;
}

void flood(int node,int comp_num)
{
//cout<<node<<" "<<comp_num<<endl;
comp[comp_num].push_back(node);
color[node]=true;
for(int i=0;i<n;i++)
if(adj[node][i]==1 && !color[i])
flood(i,comp_num);
}

void flood_fill()
{
for(int i=0;i<n;i++)
color[i]=false;
int cnt=0;
for(int i=0;i<n;i++)
if(!color[i])
{flood(i,cnt);cnt++;}
cnt_comp=cnt;
}

void shortest_path(int num)
{
double dp[comp[num].size()][comp[num].size()];
for(int i=0;i<comp[num].size();i++)
for(int j=0;j<comp[num].size();j++)
dp[i][j]=2000000000;
for(int i=0;i<comp[num].size();i++)
dp[i][i]=0;
for(int i=0;i<comp[num].size();i++)
for(int j=0;j<comp[num].size();j++)
if(adj[comp[num][i]][comp[num][j]]==1)
dp[i][j]=dist(comp[num][i],comp[num][j]);
for(int k=0;k<comp[num].size();k++)
for(int i=0;i<comp[num].size();i++)
for(int j=0;j<comp[num].size();j++)
if(dp[i][j]>dp[i][k]+dp[k][j])
dp[i][j]=dp[i][k]+dp[k][j];
for(int i=0;i<comp[num].size();i++)
for(int j=0;j<comp[num].size();j++)
path[comp[num][i]][comp[num][j]]=dp[i][j];
}

double find_max(int f,int node)
{
double t=-1;
for(int i=0;i<comp[f].size();i++)
if(path[node][comp[f][i]]>t)
t=path[node][comp[f][i]];
return t;
}

double diameter(int f1,int f2)
{
double tmp=2000000000,t1,t2,t3;
for(int i=0;i<comp[f1].size();i++)
{
for(int j=0;j<comp[f2].size();j++)
{
t1=find_max(f1,comp[f1][i]);
t2=find_max(f2,comp[f2][j]);
t3=dist(comp[f1][i],comp[f2][j]);
//cout<<comp[f1][i]<<" "<<comp[f2][j]<<" "<<t1<<" "<<t2<<" "<<t3<<" "<<t1+t2+t3<<endl;
if(tmp>t1+t3+t2)
tmp=t1+t3+t2;
}
}
for(int i=0;i<comp[f1].size();i++)
{
t1=find_max(f1,comp[f1][i]);
if(t1>tmp)
tmp=t1;
}
for(int i=0;i<comp[f2].size();i++)
{
t1=find_max(f2,comp[f2][i]);
if(t1>tmp)
tmp=t1;
}
return tmp;
}

double g()
{
flood_fill();
/*for(int i=0;i<cnt_comp;i++)
{
cout<<i<<" : ";
for(int j=0;j<comp[i].size();j++)
{
cout<<comp[i][j]<<" ";
}
cout<<endl;
}*/
//cout<<cnt_comp<<endl;
for(int i=0;i<cnt_comp;i++)
shortest_path(i);
double ans=2000000000,tmp,tmp1;
for(int i=0;i<cnt_comp;i++)
for(int j=i+1;j<cnt_comp;j++)
{
tmp=diameter(i,j);
//cout<<i<<" "<<j<<" "<<tmp<<endl;
if(ans>tmp)
ans=tmp;
} 
return ans;
}


int main()
{
FILE *fin  = fopen ("cowtour.in", "r");
FILE *fout = fopen ("cowtour.out", "w");
fscanf(fin,"%d",&n);
for(int i=0;i<n;i++)
fscanf(fin,"%lf%lf",&coord[i][0],&coord[i][1]);
char x;
fscanf(fin,"%c",&x);
for(int i=0;i<n;i++)
for(int j=0;j<n+1;j++)
{
fscanf(fin,"%c",&x);
if(x=='0')
adj[i][j]=0;
else if(x=='1')
adj[i][j]=1;
}
double h=g();
fprintf(fout,"%0.6lf\n",h);
return 0;
}
