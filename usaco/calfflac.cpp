/*
ID: sakuag31
LANG: C++
TASK: calfflac
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<iostream>
#include<fstream>
using namespace std;

string k;

int f_min(int a,int b)
{
if(a<=b)
return a;
return b;
}

int palin(int s,int e)
{
int st=s,ed=e,len=0;
bool ck=true;
while(s<e)
{
if(!isalpha(k[s]))
{s++;continue;}
if(k[s]!=k[e])
{ck=false;break;}
s++;
e--;
len++;
}
if(s==e)
len=1;
if(!ck)
return -1;
return len;
}

int f(int l,int &ind)
{
int len;
for(int i=0;i<k.length()-l+1;i++)
{
len=palin(i,i+l-1);
if(len!=-1)
{ind=i;return len;}
}
return -2;
}

int main()
{
//FILE *fin  = fopen ("calfflac.in", "r");
FILE *fout = fopen ("calfflac.out", "w");
char s[100];

k="";
ifstream fin("calfflac.in")
fin.open()
//cin.getline(&s[0],20001);
while(1)
{
fin.getline(&s[0],20001);
if(s[0]==EOF)
break;
for(int i=0;s[i]!='\0';i++)
k+=s[i];
}
cout<<k<<endl;

int len=-1,tmp,ind1,ind2,tmp1;
for(int i=f_min(2000,k.length());i>=1;i--)
{
//cout<<i<<endl;
tmp=f(i,tmp1);
//cout<<i<<" "<<tmp<<endl;
if(tmp>len)
{len=tmp;ind1=tmp1;ind2=tmp1+i-1;}
}
fprintf(fout,"%d\n",len);
for(int i=ind1;i<=ind2;i++)
{
fprintf(fout,"%c",k[i]);
}
fprintf(fout,"\n");
return 0;
}
