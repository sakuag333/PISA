#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;

int t;
char s[300];
map<pair<int,int>,bool> ck,mp;

bool f(int i,int par)
{
if(par<0)
{return false;}
if(s[i]=='\0')
{
if(par==0)
return true;
return false;
}

if(ck[make_pair(i,par)])
return mp[make_pair(i,par)];
ck[make_pair(i,par)]=true;

if(s[i]!='(' && s[i]!=')')
{
mp[make_pair(i,par)]=f(i+1,par);
return mp[make_pair(i,par)];
}
if(s[i]=='(')
{
if(i==0 || s[i-1]!=':')
mp[make_pair(i,par)]=f(i+1,par+1);
else
mp[make_pair(i,par)]=f(i+1,par+1)|f(i+1,par);
return mp[make_pair(i,par)];
}
else
{
if(i==0)
{return false;}
if(s[i-1]!=':')
mp[make_pair(i,par)]=f(i+1,par-1);
else
mp[make_pair(i,par)]=f(i+1,par-1)|f(i+1,par);
return mp[make_pair(i,par)];
}
}

int main()
{
cin>>t;
getchar();
bool ck1;
for(int i=0;i<t;i++)
{
cin.getline(&s[0],200);
mp.clear();
ck.clear();
ck1=f(0,0);
if(ck1)
cout<<"Case #"<<i+1<<": YES"<<endl;
else
cout<<"Case #"<<i+1<<": NO"<<endl;
}
return 0;
}
