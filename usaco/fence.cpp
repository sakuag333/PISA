/*
ID: sakuag31
LANG: C++
TASK: fence
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
#include<stack>
using namespace std;

int a[501][501];
bool v[501];
int deg[501];
vector<int> path;

int euler(stack<int> &st)
{
int curr;
bool ck;
while(!st.empty())
{
curr=st.top();
ck=true;
for(int i=1;i<=500;i++)
if(a[curr][i]>0)
{a[curr][i]--;a[i][curr]--;st.push(i);ck=false;break;}
if(ck)
{path.push_back(curr);st.pop();}
}
}

int f_euler()
{
stack<int> s;
int ind=-1;
for(int i=1;i<=500;i++)
if(deg[i]%2==1)
{ind=i;break;}
if(ind!=-1)
{
s.push(ind);
euler(s);
}
else
{
for(int i=1;i<=500;i++)
{
if(!v[i])
continue;
s.push(i);
euler(s);
break;
}
}
}

int main()
{
FILE *fin  = fopen ("fence.in", "r");
FILE *fout = fopen ("fence.out", "w");
for(int i=1;i<=500;i++)
for(int j=1;j<=500;j++)
a[i][j]=0;
for(int i=1;i<=500;i++)
{
deg[i]=0;
v[i]=false;
}
int f,t1,t2;
fscanf(fin,"%d",&f);
for(int i=0;i<f;i++)
{
fscanf(fin,"%d%d",&t1,&t2);
deg[t1]++;
deg[t2]++;
a[t1][t2]++;
a[t2][t1]++;
v[t1]=true;
v[t2]=true;
}
f_euler();
for(int i=path.size()-1;i>=0;i--)
fprintf(fout,"%d\n",path[i]);
return 0;
}
