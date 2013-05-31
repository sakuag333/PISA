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

string update(string s,int o)
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
queue<pair<string,string> > q;
q.push(make_pair(s,""));
string ans,tmp;
pair<string,string> pr;
int cnt=0;
while(!q.empty())
{
cnt++;
pr=q.front();
q.pop();
if(mp[pr.first])
continue;
mp[pr.first]=true;
if(check(pr.first))
{
ans=pr.second;
break;
}
for(int i=1;i<=9;i++)
{
tmp=pr.second;
x='0'+i;
tmp+=x;
//cout<<pr.first<<" "<<i<<" "<<update(pr.first,i)<<endl;
q.push(make_pair(update(pr.first,i),tmp));
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
cout<<cnt<<endl;
return 0;
}
