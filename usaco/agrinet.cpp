/*
ID: sakuag31
LANG: C++
TASK: agrinet
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
#include<cstdlib>
#include<climits>
using namespace std;

int n,a[101][101];

int prims()
{
int val=0;
bool color[n];
int dist[n];
for(int i=0;i<n;i++)
{
dist[i]=INT_MAX;
color[i]=false;
}
int curr=0;
dist[0]=0;
color[0]=true;
int tmp1,tmp2;
while(1)
{
for(int i=0;i<n;i++)
if(!color[i] && dist[i]>a[curr][i])
dist[i]=a[curr][i];
tmp1=INT_MAX;
for(int i=0;i<n;i++)
if(!color[i] && dist[i]<tmp1)
{tmp2=i;tmp1=dist[i];}
if(tmp1==INT_MAX)
break;
curr=tmp2;
val+=tmp1;
color[curr]=true;
}
return val;
}

int main()
{
FILE *fin  = fopen ("agrinet.in", "r");
FILE *fout = fopen ("agrinet.out", "w");
fscanf(fin,"%d",&n);
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
fscanf(fin,"%d",&a[i][j]);
fprintf(fout,"%d\n",prims());
return 0;
}
