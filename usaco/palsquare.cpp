/*
ID: sakuag31
LANG: C++
TASK: palsquare
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
FILE *fin  = fopen ("palsquare.in", "r");
FILE *fout = fopen ("palsquare.out", "w");
int b;
fscanf(fin,"%d",&b);
string tmp;
for(int i=1;i<=300;i++)
{
tmp=convert(i*i,b);
//cout<<tmp<<endl;
if(is_palin(tmp))
fprintf(fout,"%s %s\n",&(convert(i,b))[0],&tmp[0]);
}
return 0;
}
