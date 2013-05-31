/*
ID: sakuag31
LANG: C++
TASK: dualpal
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

bool is_palin(string s)
{
int len=s.length();
for(int i=0;i<len/2;i++)
{
if(s[i]!=s[len-1-i])
return false;
}
return true;
}

string convert(int x,int b)
{
string y="";
char k;
long long int mul=1;
while(x>0)
{
if(x%b>=10)
k=('A'+((x%b)-10));
else
k='0'+(x%b);
y=k+y;
x/=b;
}
return y;
}

int main()
{
int n,s;
FILE *fin  = fopen ("dualpal.in", "r");
FILE *fout = fopen ("dualpal.out", "w");
fscanf(fin,"%d%d",&n,&s);
int cnt=0;
int num=s+1;
int tmp;
while(cnt<n)
{
tmp=0;
for(int i=2;i<=10;i++)
{
if(is_palin(convert(num,i)))
{/*cout<<convert(num,i)<<endl;*/tmp++;}
if(tmp==2)
{
cnt++;
fprintf(fout,"%d\n",num);
break;
}
}
num++;
}
return 0;
}
