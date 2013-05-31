/*
ID: sakuag31
LANG: C++
TASK: clocks
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>
using namespace std;

string op[10]={"","ABDE","ABC","BCEF","ADG","BDEFH","CFI","DEGH","GHI","EFHI"};

void update(int b[],int o)
{
cout<<op[o]<<endl;
int x;
for(int i=0;i<op[o].length();i++)
{
x=op[o][i]-'A';
b[x]=1+(b[x]+3-1)%12;
}
}

bool check(int b[])
{
//for(int i=0;i<9;i++)
//cout<<b[i]<<" ";
//cout<<endl;
for(int i=0;i<9;i++)
{
if(b[i]!=12)
return false;
}
return true;
}

int main()
{
FILE *fin  = fopen ("clocks.in", "r");
FILE *fout = fopen ("clocks.out", "w");
int a[9];
for(int i=0;i<9;i++)
fscanf(fin,"%d",&a[i]);

string s;
char x;
queue<pair<int *,string> > q;
q.push(make_pair(a,""));
string ans;
pair<int *,string> p;
while(!q.empty())
{
p=q.front();
q.pop();
/*if((p.second)=="4589")
{
for(int j=0;j<9;j++)
cout<<b[j]<<" ";
cout<<endl;
break;
}*/
if((p.second).length()>1)
break;
/*cout<<p.second<<endl;
for(int i=0;i<9;i++)
cout<<(p.first)[i]<<" ";
cout<<endl;*/
if(check(p.first))
{ans=p.second;break;}
for(int i=1;i<=9;i++)
{
int b[9];
for(int j=0;j<9;j++)
b[j]=(p.first)[j];
s=p.second;
x='0'+i;
s+=x;
cout<<"Update------"<<endl;
for(int i1=0;i1<9;i1++)
cout<<b[i1]<<" ";
update(b,i);
cout<<s<<" "<<i<<endl;
for(int i1=0;i1<9;i1++)
cout<<b[i1]<<" ";
cout<<endl;
q.push(make_pair(b,s));
}
}
for(int j=0;j<9;j++)
cout<<a[j]<<" ";
cout<<endl;
update(a,4);
for(int j=0;j<9;j++)
cout<<a[j]<<" ";
cout<<endl;
update(a,5);
for(int j=0;j<9;j++)
cout<<a[j]<<" ";
cout<<endl;
update(a,8);
for(int j=0;j<9;j++)
cout<<a[j]<<" ";
cout<<endl;
update(a,9);
for(int j=0;j<9;j++)
cout<<a[j]<<" ";
cout<<endl;
cout<<check(a)<<endl;
return 0;
}
