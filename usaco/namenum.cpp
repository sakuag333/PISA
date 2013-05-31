/*
ID: sakuag31
LANG: C++
TASK: namenum
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
using namespace std;

int glo_len;
int count1=0;
char a[10][3];
int l[26],ml[26];
map<string,bool> mp;
vector<string> v;

void prepro()
{
char x;
int cnt1=2,cnt2=0;
for(int i=0;i<26;i++)
{
l[i]=0;
ml[i]=30;
}
for(int i=0;i<25;i++)
{
x='A'+i;
//cout<<x<<endl;
if(x=='Q')
continue;
if(cnt2==3)
{cnt2=0;cnt1++;}
a[cnt1][cnt2]=x;
cnt2++;
}
FILE *fin1 = fopen("dict.txt","r");
string s;
char t[20];
int len;
while(fscanf(fin1,"%s",&t[0])!=EOF)
{
s="";
len=0;
for(int i=0;t[i]!='\0';i++)
{len++;s+=t[i];}
if(l[t[0]-'A']<len)
l[t[0]-'A']=len;
if(ml[t[0]-'A']>len)
ml[t[0]-'A']=len;
//cout<<s<<endl;
mp[s]=true;
}
//cout<<"d"<<endl;
}

void f(char num1[],string s,int i)
{
count1++;
//cout<<i<<" "<<num1[i]-'0'<<" "<<len<<endl;
if(l[s[0]-'A']<s.length())
return;
if(num1[i]=='\0')
{
if(mp[s])
v.push_back(s);
return;
}
string t;
for(int j=0;j<3;j++)
{
t=s;
t+=a[num1[i]-'0'][j];
//cout<<i<<endl;
//cout<<num1[i]<<endl;
//cout<<a[num1[i]-'0'][j]<<endl;
f(num1,t,i+1);
}
}

int main()
{
prepro();
FILE *fin  = fopen ("namenum.in", "r");
FILE *fout = fopen ("namenum.out", "w");
char s12[20];
fscanf(fin,"%s",&s12[0]);
int len=0;
while(s12[len]!='\0')
len++;
glo_len=len;
//cout<<len<<endl;
string k="";
f(s12,k,0);
if(v.size()==0)
fprintf(fout,"NONE\n");
for(int i=0;i<v.size();i++)
fprintf(fout,"%s\n",&v[i][0]);
//cout<<count1<<endl;
return 0;
}
