/*
ID: sakuag31
LANG: C++
TASK: sort3
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
using namespace std;

int main()
{
FILE *fin  = fopen ("sort3.in", "r");
FILE *fout = fopen ("sort3.out", "w");
int n,a[1001],ans=0;
fscanf(fin,"%d",&n);
for(int i=0;i<n;i++)
fscanf(fin,"%d",&a[i]);
int st=0,num=1;
while(num<=2)
{
int cnt=0;
for(int i=st;i<n;i++)
if(a[i]==num)
cnt++;
int b[1001];
int ind=0;
for(int i=st;i<st+cnt;i++)
{
if(a[i]==num)
continue;
b[ind]=a[i];
ind++;
a[i]=num;
ans++;
}
sort(b,b+ind);
int k=0;
for(int i=st+cnt;i<n;i++)
{
if(a[i]==num)
{
a[i]=b[k];
k++;
}
}
st=cnt;
num++;
}
fprintf(fout,"%d\n",ans);
//for(int i=0;i<n;i++)
//cout<<a[i]<<" ";
//cout<<endl;
return 0;
}
