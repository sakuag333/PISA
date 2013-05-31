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
int p1=0;
while(a[p1]==1 && p1<n)
p1++;
int p2=n-1;
while(a[p2]!=1 && p2>=0)
p2--;
while(p1<p2)
{
a[p2]=a[p1];
a[p1]=1;
while(a[p1]==1 && p1<n)
p1++;
while(a[p2]!=1 && p2>=0)
p2--;
ans++;
}
p1=n-1;
p2=0;
while(a[p1]==3 && p1>=0)
p1--;
while(a[p2]!=3 && p2<n)
p2++;
while(p1>p2)
{
a[p2]=a[p1];
a[p1]=3;
while(a[p1]==3 && p1>=0)
p1--;
while(a[p2]!=3 && p2<n)
p2++;
ans++;
}
for(int i=0;i<n;i++)
cout<<a[i]<<" ";
cout<<endl;
fprintf(fout,"%d\n",ans);
return 0;
}
