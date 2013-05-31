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


inline string update(string s,int o)
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

inline string f_update(string m,string s)
{
string tmp=m;
for(int i=0;i<s.length();i++)
{
for(int j=0;j<(s[i]-'0');j++)
{
//if(s=="000110011")
//cout<<tmp<<endl;
tmp=update(tmp,i+1);
//if(s=="000110011")
//cout<<tmp<<endl;
//if(s=="000110011")
//cout<<"-"<<endl;
}
}
return tmp;
}

inline bool check(string s)
{
for(int i=0;i<s.length();i++)
{
if(s[i]!='d')
return false;
}
return true;
}

inline string g_update(string s,int o,int l)
{
string tmp=s;
for(int i=0;i<l;i++)
tmp=update(tmp,o);
return tmp;
}

string ans;
map<string,bool> mp;

bool f(string m,string s,int l)
{
//if(s=="320100021")
//cout<<s<<" "<<m<<endl;
if(l==0)
{
//string m1=f_update(m,s);
//if(s=="000110011")
//cout<<m1<<endl;
bool ck=check(m);
if(ck)
{
ans=s;
}
return ck;
}
for(int i=0;i<=3;i++)
{
string k=s;
char x='0'+i;
k+=x;
string y=g_update(m,k.length(),i);
bool ck=f(y,k,l-1);
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
int c[10];
s="";
for(int i=0;i<9;i++)
{
c[i+1]=0;
fscanf(fin,"%d",&a[i]);
x='a'+((a[i]/3)-1);
s+=x;
}
//s=update(s,1);s=update(s,1);s=update(s,1);s=update(s,2);s=update(s,2);s=update(s,4);s=update(s,8);s=update(s,8);s=update(s,9);cout<<s<<endl;
string t="";
mp.clear();
f(s,t,9);
string k="";
for(int i=0;i<ans.length();i++)
{
for(int j=0;j<(ans[i]-'0');j++)
{
x='1'+i;
k=k+x;
}
}
for(int i=0;i<k.length();i++)
{
fprintf(fout,"%c",k[i]);
if(i<k.length()-1)
fprintf(fout," ");
}
fprintf(fout,"\n");
return 0;
}
