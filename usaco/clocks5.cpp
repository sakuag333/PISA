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

map<pair<string,int>,bool> mp;
string ans;

bool dfs(string s,string t,int d)
{

//cout<<t<<" "<<s<<endl;
//if(d==0)
//{
bool ck1=check(s);
if(ck1)
{ans=t;return true;}
//return ck1;
//}
if(d==0)
return false;
if(mp[make_pair(s,t.length())])
{/*cout<<"="<<endl;*/return false;}
mp[make_pair(s,t.length())]=true;

for(int i=1;i<=9;i++)
{
char x=('0'+i);
string tmp=t;
tmp+=x;
string k=update(s,i);
bool ck=dfs(k,tmp,d-1);
if(ck)
return true;
}
return false;
}
/*1 3 5 7 7 7 8 8 9 9 9*/
int main()
{
FILE *fin  = fopen ("clocks.in", "r");
FILE *fout = fopen ("clocks.out", "w");
string s;
char x;
int a[9];
int c[10];
s="";
for(int i=0;i<9;i++)
{
c[i+1]=0;
fscanf(fin,"%d",&a[i]);
x='a'+((a[i]/3)-1);
s+=x;
}
int depth=40;
bool ck=false;
string t;
while(1)
{
//cout<<depth<<endl;
mp.clear();
t="";
ck=dfs(s,t,depth);
if(ck)
break;
depth+=40;
}
//cout<<ans<<endl;
for(int i=0;i<ans.length();i++)
c[ans[i]-'0']++;
for(int i=0;i<9;i++)
{
c[i]=c[i]%4;
}
char v;
string l="";
for(int i=1;i<=9;i++)
{
for(int j=0;j<c[i];j++)
{
v='0'+i;
l+=v;
}
}
for(int i=0;i<l.length();i++)
{
fprintf(fout,"%c",l[i]);
if(i<l.length()-1)
fprintf(fout," ");
}
fprintf(fout,"\n");
return 0;
}
