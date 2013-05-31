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
map<string,bool> mp,ck1;

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

long long int to_value(string s)
{
long long int ret=0;
for(int i=0;i<s.length();i++)
{
ret=ret*10+(s[i]-'0');
}
}

string ans;

bool dfs(string s,string t,int i)
{
if(i==0)
{
//cout<<t<<endl;
bool ck=check(s);
if(ck)
ans=t;
return ck;
}
if(mp[s])
return false;
mp[s]=true;
for(int j=1;j<=9;j++)
{
string tmp=t;
char x='0'+j;
tmp+=x;
bool ck=dfs(update(s,j),tmp,i-1);
if(ck)
return true;
}
return false;
}

int main()
{
FILE *fin  = fopen ("clocks.in", "r");
FILE *fout = fopen ("clocks.out", "w");
string s;
char x;
int a[9];
s="";
for(int i=0;i<9;i++)
{
fscanf(fin,"%d",&a[i]);
x='a'+((a[i]/3)-1);
s+=x;
}
int depth=1;
string t;
bool ck=false;
while(!ck)
{
mp.clear();
cout<<depth<<endl;
t="";
ck=dfs(s,t,depth);
depth++;
}
vector<char> v;
for(int i=0;i<ans.length();i++)
v.push_back(ans[i]);
sort(v.begin(),v.end());
for(int i=0;i<v.size();i++)
{
fprintf(fout,"%c",v[i]);
if(i<ans.length()-1)
fprintf(fout," ");
else
fprintf(fout,"\n");
}
return 0;
}
