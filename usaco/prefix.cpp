/*
ID: sakuag31
LANG: C++
TASK: prefix
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
#include<cstdlib>
using namespace std;

inline int f_max(int a,int b)
{
if(a>=b)
return a;
return b;
}

int main()
{
FILE *fin  = fopen ("prefix.in", "r");
FILE *fout = fopen ("prefix.out", "w");
map<string,bool> mp;
string s="";
char x;
while(1)
{
fscanf(fin,"%c",&x);
if(x=='.')
{
if(s.length()>0)
mp[s]=true;
break;
}
if(!isalpha(x))
{
mp[s]=true;
s="";
}
else
s+=x;
}
string seq="";
char t[100];
int ind;
//bool p=false;
while(fscanf(fin,"%s",&t[0])!=EOF)
{
//fscanf(fin,"%s",&t[0]);
ind=0;
while(1)
{
//if(t[ind]=='\0')
//p=true;
if(t[ind]=='\0' || t[ind]=='\n')
break;
seq+=t[ind];
ind++;
}
}
cout<<seq<<endl;
int dp[seq.length()+1];
dp[seq.length()]=0;
string tmp;
for(int i=seq.length()-1;i>=0;i--)
{
dp[i]=0;
tmp="";
for(int j=0;j<10;j++)
{
if(i+j>=seq.length())
break;
tmp+=seq[i+j];
if(mp[tmp])
dp[i]=f_max(dp[i],j+1+dp[i+j+1]);
}
}
fprintf(fout,"%d\n",dp[0]);
return 0;
}
