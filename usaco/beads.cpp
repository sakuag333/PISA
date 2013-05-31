/*
ID: sakuag31
LANG: C++
TASK: beads
*/
#include<stdio.h>
#include<iostream>
#include<map>
using namespace std;

map<int,bool> mp;

int calc(int i,int l,char s[])
{
int ind,cnt;
char color;
ind=i;
cnt=0;
color='z';
while(1)
{
if(mp[ind])
break;
mp[ind]=true;
//cout<<s[ind]<<" ";
if(s[ind]=='w')
cnt++;
else if(color=='z')
{cnt++;color=s[ind];}
else if(color==s[ind])
cnt++;
else
{mp[ind]=false;break;}
if(ind==0)
ind=l-1;
else
ind--;
}
//cout<<endl;
ind=(i+1)%l;
color='z';
while(1)
{
if(mp[ind])
break;
mp[ind]=true;
//cout<<s[ind]<<" ";
if(s[ind]=='w')
cnt++;
else if(color=='z')
{cnt++;color=s[ind];}
else if(color==s[ind])
cnt++;
else
break;
ind=(ind+1)%l;
}
//cout<<endl;
return cnt;
}

int main()
{
FILE *fin  = fopen ("beads.in", "r");
FILE *fout = fopen ("beads.out", "w");
int n;
char s[1000];
fscanf(fin,"%d",&n);
fscanf(fin,"%s",&s[0]);
int l=0,ans=-1,tmp;
for(int i=0;s[i]!='\0';i++)
l++;
for(int i=0;i<l;i++)
{
mp.clear();
tmp=calc(i,l,s);
//fprintf(fout,"%d %d\n",i,tmp);
if(ans<tmp)
ans=tmp;
}
fprintf(fout,"%d\n",ans);
return 0;
}
