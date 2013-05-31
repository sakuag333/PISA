/*
ID: sakuag31
LANG: C++
TASK: numtri
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
using namespace std;

int r,a[1001][1001];
bool ck[1001][1001];
int mp[1001][1001];
//map<pair<int,int>,bool> ck;
//map<pair<int,int>,int> mp;

int f_max(int a,int b)
{
if(a>=b)
return a;
return b;
}

int f(int d,int h)
{
if(d==r)
return 0;
if(ck[d][h])
return mp[d][h];
ck[d][h]=true;
mp[d][h]=a[d][h]+f_max(f(d+1,h+1),f(d+1,h));
return mp[d][h];
}

int main()
{
FILE *fin  = fopen ("numtri.in", "r");
FILE *fout = fopen ("numtri.out", "w");
fscanf(fin,"%d",&r);
for(int i=0;i<r;i++)
{
for(int j=0;j<=i;j++)
{
ck[i][j]=false;
fscanf(fin,"%d",&a[i][j]);
}
}
fprintf(fout,"%d\n",f(0,0));
return 0;
}
