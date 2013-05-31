/*
ID: sakuag31
LANG: C++
TASK: zerosum
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
#include<cstdlib>
using namespace std;

int n;
vector<string> ans;

int h(string s)
{
s='+'+s;
s='0'+s;
//cout<<s<<endl;
int val=0;
int next;
for(int i=1;i<s.length();i+=2)
{
if(s[i]==' ')
continue;
next=0;
for(int j=i+1;j<s.length();j+=2)
{
next=10*next+(s[j]-'0');
if(j+1==s.length() || s[j+1]!=' ')
break;
}
//cout<<val<<" "<<next<<endl;
if(s[i]=='+')
val+=next;
else if(s[i]=='-')
val-=next;
}
return val;
}


void f(int l,string s)
{
if(l==n-1)
{
int val=h(s);
if(val==0)
ans.push_back(s);
return;
}
string t;
char x;
t=s+'+';
x='0'+(l+2);
t+=x;
f(l+1,t);
t=s+'-';
x='0'+(l+2);
t+=x;
f(l+1,t);
t=s+' ';
x='0'+(l+2);
t+=x;
f(l+1,t);
}


int main()
{
FILE *fin  = fopen ("zerosum.in", "r");
FILE *fout = fopen ("zerosum.out", "w");
fscanf(fin,"%d",&n);
string s="";
s+='1';
//int y=h("1 2 3-4-5-6+7");
//cout<<y<<endl;
f(0,s);
sort(ans.begin(),ans.end());
for(int i=0;i<ans.size();i++)
{
for(int j=0;j<ans[i].length();j++)
fprintf(fout,"%c",ans[i][j]);
fprintf(fout,"\n");
}
return 0;
}
