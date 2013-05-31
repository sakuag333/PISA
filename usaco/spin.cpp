/*
ID: sakuag31
LANG: C++
TASK: spin
*/
#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>
#include<climits>
using namespace std;

int wheel[5][5][2];
int speed[5];
int wedge[5];
bool mark[5][360];
int round;

bool mark_wedge()
{
for(int i=0;i<5;i++)
for(int j=0;j<360;j++)
mark[i][j]=false;
int pos1,pos2;
for(int i=0;i<5;i++)
{
for(int j=0;j<wedge[i];j++)
{
pos1=(wheel[i][j][0]+speed[i]*round)%360;
pos2=wheel[i][j][1];
for(int k=0;k<=pos2;k++)
mark[i][(pos1+k)%360]=true;
}
}
bool ret;
for(int i=0;i<360;i++)
{
ret=true;
for(int j=0;j<5;j++)
{
if(!mark[j][i])
{ret=false;break;}
}
if(ret)
return true;
}
return false;
}

int main()
{
FILE *fin = fopen("spin.in", "r");
FILE *fout = fopen("spin.out", "w");
int tmp,extent;
for(int i=0;i<5;i++)
{
fscanf(fin,"%d%d",&speed[i],&wedge[i]);
for(int j=0;j<wedge[i];j++)
fscanf(fin,"%d%d",&wheel[i][j][0],&wheel[i][j][1]);
}
bool ck;
round=0;
while(round<360)
{
ck=mark_wedge();
if(ck)
{fprintf(fout,"%d\n",round);return 0;}
round++;
}
fprintf(fout,"none\n");
return 0;
}
