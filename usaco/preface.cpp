/*
ID: sakuag31
LANG: C++
TASK: preface
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
using namespace std;

map<char,int> mp1;
map<int,string> mp2;
map<int,char> mp3;
map<int,bool> mp4;
int a[7];

void f(int x,int mul)
{
if(x==0)
return;
//cout<<x<<" "<<mul<<endl;
string k;
if(mp4[x*mul])
{k=mp2[x*mul];x=0;}
else
k=mp2[mul*(x%10)];
mul*=10;
//cout<<k;
for(int i=0;i<k.length();i++)
a[mp1[k[i]]]++;
f(x/10,mul);
}

int main()
{
mp2[1]="I";
mp2[2]="II";
mp2[3]="III";
mp2[4]="IV";
mp2[5]="V";
mp2[6]="VI";
mp2[7]="VII";
mp2[8]="VIII";
mp2[9]="IX";
mp2[10]="X";
mp2[20]="XX";
mp2[30]="XXX";
mp2[40]="XL";
mp2[50]="L";
mp2[60]="LX";
mp2[70]="LXX";
mp2[80]="LXXX";
mp2[90]="XC";
mp2[100]="C";
mp2[200]="CC";
mp2[300]="CCC";
mp2[400]="CD";
mp2[500]="D";
mp2[600]="DC";
mp2[700]="DCC";
mp2[800]="DCCC";
mp2[900]="CM";
mp2[1000]="M";
mp2[2000]="MM";
mp2[3000]="MMM";
mp4[1]=true;
mp4[2]=true;
mp4[3]=true;
mp4[4]=true;
mp4[5]=true;
mp4[6]=true;
mp4[7]=true;
mp4[8]=true;
mp4[9]=true;
mp4[10]=true;
mp4[20]=true;
mp4[30]=true;
mp4[40]=true;
mp4[50]=true;
mp4[60]=true;
mp4[70]=true;
mp4[80]=true;
mp4[90]=true;
mp4[100]=true;
mp4[200]=true;
mp4[300]=true;
mp4[400]=true;
mp4[500]=true;
mp4[600]=true;
mp4[700]=true;
mp4[800]=true;
mp4[900]=true;
mp4[1000]=true;
mp4[2000]=true;
mp4[3000]=true;
mp1['I']=0;
mp1['V']=1;
mp1['X']=2;
mp1['L']=3;
mp1['C']=4;
mp1['D']=5;
mp1['M']=6;
mp3[0]='I';
mp3[1]='V';
mp3[2]='X';
mp3[3]='L';
mp3[4]='C';
mp3[5]='D';
mp3[6]='M';

FILE *fin  = fopen ("preface.in", "r");
FILE *fout = fopen ("preface.out", "w");
for(int i=0;i<7;i++)
a[i]=0;
int n;
fscanf(fin,"%d",&n);
//cout<<mp2[67]<<endl;
for(int i=1;i<=n;i++)
{
f(i,1);
//cout<<endl;
//cout<<i<<endl;
}
//f(268,1);
//cout<<endl;
for(int i=0;i<7;i++)
if(a[i]>0)
fprintf(fout,"%c %d\n",mp3[i],a[i]);
return 0;
}
