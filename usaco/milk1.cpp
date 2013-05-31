/*
ID: sakuag31
LANG: C++
TASK: milk
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

vector<pair<int,int> > v;

int f(int n,int i)
{
if(n==0)
return 0;
if(v[i].second<n)
return ((v[i].first)*(v[i].second)+f(n-v[i].second,i+1));
return n*v[i].first;
}

int main()
{
int n,m,t1,t2;
FILE *fin  = fopen ("milk.in", "r");
FILE *fout = fopen ("milk.out", "w");
fscanf(fin,"%d%d",&n,&m);
for(int i=0;i<m;i++)
{
fscanf(fin,"%d%d",&t1,&t2);
v.push_back(make_pair(t1,t2));
}
sort(v.begin(),v.end());
fprintf(fout,"%d\n",f(n,0));
return 0;
}
