/*
ID: sakuag31
LANG: C++
TASK: fracdec
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
#include<cstdlib>
#include<climits>
using namespace std;

int limit=104000;
string str;

int num_char=0;

string to_str(int x)
{
if(x==0)
{
string s="0";
return s;
}
char y;
string s="";
while(x>0)
{
y='0'+(x%10);
s+=y;
x/=10;
}
return s;
}

void divide(int num,int den,bool &ck)
{
str="";
int tmp,cnt=0;
while(num!=0 && cnt<limit)
{
num*=10;
while(num<den)
{
str+='0';
num*=10;
}
tmp=num/den;
str=str+to_str(tmp);
num%=den;
cnt++;
}
if(num==0)
ck=true;
}

int dec(int ind,int l)
{
if(ind==0)
return l-1;
return ind-1;
}

bool check(int ind1,int ind2)
{
int p1=ind1,p2=ind2;
while(p1<ind2)
{
if(str[p1]!=str[p2])
return false;
p1++;
p2++;
}
p1=ind1;//p2=ind2+(ind2-ind1);
for(int i=0;i<100;i++)
{
if(str[p1]!=str[p2])
return false;
p1++;
p2++;
//ind1++;
//ind2++;
}
return true;
}

string find_recur()
{
//for(int i=0;i<=100;i++)
//cout<<str[i];
//cout<<endl;
string k1="",k2="";
int found;
int st,ed;
k1+=str[0];
for(int i=1;i<str.length();i++)
{
k2="";
k2+=str[i];
found=k1.find(k2);
if(found!=-1)
{
//cout<<k2<<" "<<found<<" "<<i<<endl;
if(check(i,found))
{st=found;ed=i-1;break;}
}
k1+=str[i];
}
k1="";
for(int i=0;i<st;i++)
k1+=str[i];
k1+='(';
for(int i=st;i<=ed;i++)
k1+=str[i];
k1+=')';
return k1;
}


int main()
{
FILE *fin  = fopen ("fracdec.in", "r");
FILE *fout = fopen ("fracdec.out", "w");
int num,den;
fscanf(fin,"%d%d",&num,&den);
//cin>>num>>den;
bool ck=false;
divide(num%den,den,ck);
//cout<<num/den<<".";
fprintf(fout,"%d.",num/den);
string u=to_str(num/den);
num_char=1+u.length();
if(ck)
{
if(str.length()==0)
fprintf(fout,"0\n");
else
{
for(int i=0;i<str.length();i++)
{
if((num_char)%76==0)
{num_char=0;fprintf(fout,"\n");}
fprintf(fout,"%c",str[i]);
num_char++;
}
fprintf(fout,"\n");
}
}
else
{
string y=find_recur();
for(int i=0;i<y.length();i++)
{
if((num_char)%76==0)
{num_char=0;fprintf(fout,"\n");}
fprintf(fout,"%c",y[i]);
num_char++;
}
fprintf(fout,"\n");
}
return 0;
}
