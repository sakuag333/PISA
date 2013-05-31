/*
ID: sakuag31
LANG: C++
TASK: friday
*/
#include<stdio.h>
#include<iostream>
using namespace std;

int mon[13];

int is_leap(int y)
{
if(y%400==0)
return true;
if(y%100==0)
return false;
if(y%4==0)
return true;
return false;
}

int days(int m,int y)
{
if(m==2 && is_leap(y))
return 29;
return mon[m];
}

int first_day(int prev,int m,int y)
{
int d=days(m,y);
return 1+((prev-1+d)%7);
}

int fri_day(int first,int m,int y)
{
return 1+((first-1+12)%7);
}

int main()
{
FILE *fin  = fopen ("friday.in", "r");
FILE *fout = fopen ("friday.out", "w");
mon[1]=31;
mon[2]=28;
mon[3]=31;
mon[4]=30;
mon[5]=31;
mon[6]=30;
mon[7]=31;
mon[8]=31;
mon[9]=30;
mon[10]=31;
mon[11]=30;
mon[12]=31;
int n;
fscanf(fin,"%d",&n);
int ans[8];
for(int i=1;i<=7;i++)
ans[i]=0;
int first=3;
for(int i=1900;i<1900+n;i++)
{
for(int j=1;j<=12;j++)
{
ans[fri_day(first,j,i)]++;
first=first_day(first,j,i);
}
}
for(int i=1;i<=7;i++)
{
fprintf(fout,"%d",ans[i]);
if(i<7)
fprintf(fout," ");
else
fprintf(fout,"\n");
}
return 0;
}
