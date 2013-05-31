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
#include<map>
using namespace std;

string op[10]={"","ABDE","ABC","BCEF","ADG","BDEFH","CFI","DEGH","GHI","EFHI"};
char st[4]={'a','b','c','d'};

string f_update(string s,int o)
{
char x;
int y;
string t=s;
for(int i=0;i<op[o].length();i++)
{
x=op[o][i]-'A';
y=s[x]-'a';
y=(y+1)%4;
t[x]='a'+y;
}
return t;
}

string update(string s,string t)
{
int x;
string tmp=s;
for(int i=0;i<t.length();i++)
{
x=t[i]-'0';
tmp=f_update(tmp,x);
}
return tmp;
}

bool check(string s)
{
for(int i=0;i<s.length();i++)
{
if(s[i]!='d')
return false;
}
return true;
}

int main()
{
FILE *fin  = fopen ("clocks.in", "r");
FILE *fout = fopen ("clocks.out", "w");
string s;
map<string,bool> mp;
char x;
int a[9];
s="";
for(int i=0;i<9;i++)
{
fscanf(fin,"%d",&a[i]);
x='a'+((a[i]/3)-1);
s+=x;
}
queue<string> q;
q.push("");
string ans,tmp;
string pr,str;
int cnt=0;
while(!q.empty())
{
cnt++;
pr=q.front();
q.pop();
str=update(s,pr);
if(mp[str])
continue;
mp[str]=true;
if(check(str))
{
ans=pr;
break;
}
for(int i=1;i<=9;i++)
{
tmp=pr;
x='0'+i;
tmp+=x;
//cout<<tmp<<endl;
q.push(tmp);
}
}
for(int i=0;i<ans.length();i++)
{
fprintf(fout,"%c",ans[i]);
if(i<ans.length()-1)
fprintf(fout," ");
else
fprintf(fout,"\n");
}
//cout<<cnt<<endl;
return 0;
}
