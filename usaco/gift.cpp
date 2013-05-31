/*
ID: sakuag31
LANG: C++
TASK: gift1
*/
#include<stdio.h>
#include<iostream>
#include<map>
using namespace std;

string to_string(char s[])
{
string a="";
for(int i=0;s[i]!='\0';i++)
a+=s[i];
return a;
}

int main()
{
FILE *fin  = fopen ("gift1.in", "r");
FILE *fout = fopen ("gift1.out", "w");
int n,cnt=0,tmp1,tmp2;
char s[20];
char name[20][20];
int initial_money[20],final_money[20];
map<string,int> mp;
fscanf(fin,"%d",&n);
for(int i=0;i<n;i++)
{
final_money[i]=0;
fscanf(fin,"%s",&s[0]);
int j=0;
for(j=0;s[j]!='\0';j++)
{
name[i][j]=s[j];
}
name[i][j]='\0';
//fprintf(fout,"%s\n",name[i]);
mp[to_string(s)]=cnt;
cnt++;
}
for(int i=0;i<n;i++)
{
fscanf(fin,"%s",&s[0]);
fscanf(fin,"%d%d",&tmp1,&tmp2);
initial_money[mp[to_string(s)]]=tmp1;
if(tmp2==0)
continue;
final_money[mp[to_string(s)]]+=(tmp1-(tmp2*(tmp1/tmp2)));
for(int j=0;j<tmp2;j++)
{
fscanf(fin,"%s",&s[0]);
final_money[mp[to_string(s)]]+=(tmp1/tmp2);
}
}
for(int i=0;i<n;i++)
fprintf(fout,"%s %d\n",name[i],final_money[i]-initial_money[i]);
return 0;
}
