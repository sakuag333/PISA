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

bool f(int a,int b)
{
while(a<b)
{
if(k[a]!=k[b])
return false;
a++;
b--;
}
return true;
}

int f_min(int a,int b)
{
if(a<=b)
return a;
return b;
}

int main()
{
//FILE *fin  = fopen ("calfflac.in", "r");
ifstream fin("calfflac.in");
//fin.open();
FILE *fout = fopen ("calfflac.out", "w");
char s[100];
int a[20010];
int cnt=0,co=0;

k="";
string full="";
while(fin.getline(&s[0],20001))
{
for(int i=0;s[i]!='\0';i++)
{
full+=s[i];
if(isalpha(s[i]))
{
a[cnt]=co;
cnt++;
k+=(tolower(s[i]));
}
co++;
}
full+='\n';
co++;
}
//cout<<k<<endl;
//cout<<full<<endl;

bool ck;
int tmp,ans=-1,st,ed;
int lim=f_min(2000,k.length()-1);
for(int i=lim;i>=1;i--)
{
for(int j=0;j<k.length()-i+1;j++)
{
ck=f(j,j+i-1);
if(ck)
{ans=i;st=j;ed=j+i-1;break;}
}
if(ck)
break;
}

fprintf(fout,"%d\n",ans);
for(int k1=a[st];k1<=a[ed];k1++)
fprintf(fout,"%c",full[k1]);

fprintf(fout,"\n");

return 0;
}
