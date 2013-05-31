/*
ID: sakuag31
LANG: C++
TASK: subset
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
using namespace std;

int n,lim;
map<pair<pair<int,int>,int>,bool> ck;
map<pair<pair<int,int>,int>,long long int> mp;

long long int f(int x,int y,int i)
{
if(i==0)
{
if(x==y)
return 1;
return 0;
}
if(x>lim || y>lim)
return 0;
if(ck[make_pair(make_pair(x,y),i)])
return mp[make_pair(make_pair(x,y),i)];
ck[make_pair(make_pair(x,y),i)]=true;
mp[make_pair(make_pair(x,y),i)]=f(x+i,y,i-1)+f(x,y+i,i-1);
return mp[make_pair(make_pair(x,y),i)];
}

int main()
{
FILE *fin  = fopen ("subset.in", "r");
FILE *fout = fopen ("subset.out", "w");
fscanf(fin,"%d",&n);
if(((n*(n+1))/2)%2!=0)
{
fprintf(fout,"0\n");
return 0;
}
lim=(n*(n+1))/4;
fprintf(fout,"%lld\n",(f(0,0,n))/2);
return 0;
}
