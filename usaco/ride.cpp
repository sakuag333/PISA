/*
ID: sakuag31
LANG: C++
TASK: ride
*/
#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
FILE *fin  = fopen ("ride.in", "r");
FILE *fout = fopen ("ride.out", "w");
char s1[100],s2[100];
fscanf (fin, "%s%s", &s1[0], &s2[0]);
int t1=1,t2=1;
for(int i=0;s1[i]!='\0';i++)
{
t1=(t1*(s1[i]-'A'+1))%47;
}
for(int i=0;s2[i]!='\0';i++)
{
t2=(t2*(s2[i]-'A'+1))%47;
}
if(t1==t2)
fprintf (fout, "GO\n");
else
fprintf (fout, "STAY\n");
return 0;
}
