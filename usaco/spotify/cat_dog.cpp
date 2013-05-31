#include<stdio.h>
#include<iostream>
using namespace std;

int parse(string s)
{
int k=0;
for(int i=1;i<s.length();i++)
k=10*k+(s[i]-'0');
return k;
}

bool is_satisfied(char animal,int ind,string vote)
{
int number=parse(vote);
if(animal==vote[0] && ind==number)
return true;
return false;
}

bool not_satisfied(char animal,int ind,string vote)
{
int number=parse(vote);
if(animal!=vote[0] || ind!=number)
return true;
return false;
}

int main()
{
int c,d,v,t,num,tmp;
string votes[502][2];
scanf("%d",&t);
for(int i=0;i<t;i++)
{
scanf("%d%d%d",&c,&d,&v);
for(int i=0;i<v;i++)
cin>>votes[i][0]>>votes[i][1];
num=0;
for(int i=1;i<=c;i++)
{
tmp=0;
for(int j=0;j<v;j++)
if(is_satisfied('C',i,votes[j][0]))
tmp++;
if(tmp>num)
num=tmp;
}
for(int i=1;i<=d;i++)
{
tmp=0;
for(int j=0;j<v;j++)
if(is_satisfied('D',i,votes[j][0]))
tmp++;
if(tmp>num)
num=tmp;
}
for(int i=1;i<=c;i++)
{
tmp=0;
for(int j=0;j<v;j++)
if(not_satisfied('C',i,votes[j][1]))
tmp++;
if(tmp>num)
num=tmp;
}
for(int i=1;i<=d;i++)
{
tmp=0;
for(int j=0;j<v;j++)
if(not_satisfied('D',i,votes[j][1]))
tmp++;
if(tmp>num)
num=tmp;
}
printf("%d\n",num);
}
return 0;
}
