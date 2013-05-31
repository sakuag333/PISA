/*
ID: sakuag31
LANG: C++
TASK: kimbits
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
#include<cmath>
using namespace std;


int g(long long int n,long long int r)
{
if(n<r)
return 0;
long long int tmp=1;
for(long long int i=1;i<=r;i++)
{
tmp*=(n-i+1);
tmp/=i;
}
return tmp;
}

int f(long long int len,long long int dig)
{
long long int ret=0;
for(long long int i=0;i<=dig;i++)
ret+=g(len,i);
return ret;
}

string h(long long int len,long long int one,long long int rank)
{
string s="";
bool ck=false;
long long int tmp,dig=one,r=rank;
for(long long int i=len;i>=1;i--)
{
tmp=f(i-1,dig);
if(tmp<r)
{
r-=tmp;
s+='1';
dig--;
}
else
s+='0';
}
for(int i=s.length();i<len;i++)
s+='1';
return s;
}

int main()
{
FILE *fin  = fopen ("kimbits.in", "r");
FILE *fout = fopen ("kimbits.out", "w");
long long int n,l,rank;
fscanf(fin,"%lld%lld%lld",&n,&l,&rank);
//cin>>rank;
//cout<<rank<<endl;
string ans=h(n,l,rank);
cout<<ans<<" "<<rank<<endl;
for(int i=0;i<ans.length();i++)
fprintf(fout,"%c",ans[i]);
fprintf(fout,"\n");
return 0;
}
