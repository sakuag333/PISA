/*
ID: sakuag31
LANG: C++
TASK: transform
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;


bool is_same(char b[][11],char c[][11],int n)
{
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
if(b[i][j]!=c[i][j])
return false;
}
}
return true;
}

void print(char a[][11],int n)
{
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
cout<<a[i][j];
}
cout<<endl;
}
}

void rot_90(char b[][11],char c[][11],int n)
{
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
c[j][n-i-1]=b[i][j];
//print(c,n);
}

void rot_180(char b[][11],char c[][11],int n)
{
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
c[n-i-1][n-j-1]=b[i][j];
}

void rot_270(char b[][11],char c[][11],int n)
{
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
c[n-j-1][i]=b[i][j];
}

void ref(char b[][11],char c[][11],int n)
{
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
c[i][n-j-1]=b[i][j];
}

int f_123(char a[][11],char c[][11],int n)
{
char b[11][11];
rot_90(a,b,n);
if(is_same(b,c,n))
return 1;
rot_180(a,b,n);
if(is_same(b,c,n))
return 2;
rot_270(a,b,n);
if(is_same(b,c,n))
return 3;
return -1;
}

int f(char a[][11],char c[][11],int n)
{
int ret=f_123(a,c,n);
if(ret!=-1)
return ret;
char b[11][11];
ref(a,b,n);
if(is_same(b,c,n))
return 4;
ret=f_123(b,c,n);
if(ret!=-1)
return 5;
if(is_same(a,c,n))
return 6;
return 7;
}

int main()
{
int n;
char tmp[20];
char a[11][11],c[11][11];
FILE *fin  = fopen ("transform.in", "r");
FILE *fout = fopen ("transform.out", "w");
fscanf(fin,"%d",&n);
//cin>>n;
for(int i=0;i<n;i++) 
{
fscanf(fin,"%s",&tmp[0]);
for(int j=0;j<n;j++)
{
a[i][j]=tmp[j];
}
}
//print(a,n);
for(int i=0;i<n;i++) 
{
fscanf(fin,"%s",&tmp[0]);
for(int j=0;j<n;j++)
{
c[i][j]=tmp[j];
}
}
//print(c,n);
//fscanf(fin,"%c",&c[i][j]);
fprintf(fout,"%d\n",f(a,c,n));
//cout<<f(a,c,n)<<endl;
return 0;
}
