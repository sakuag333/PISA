/*
ID: sakuag31
LANG: C++
TASK: ttwo
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
using namespace std;

char a[10][11];

inline void move(int b[],char &dir)
{
int r=b[0],c=b[1];
if(dir=='N')
{
if(r-1<0 || a[r-1][c]=='*')
dir='E';
else
b[0]--;
}
else if(dir=='S')
{
if(r+1>=10 || a[r+1][c]=='*')
dir='W';
else
b[0]++;
}
else if(dir=='E')
{
if(c+1>=10 || a[r][c+1]=='*')
dir='S';
else
b[1]++;
}
else
{
if(c-1<0 || a[r][c-1]=='*')
dir='N';
else
b[1]--;
}
}

int main()
{
FILE *fin  = fopen ("ttwo.in", "r");
FILE *fout = fopen ("ttwo.out", "w");
int f[2],c[2];
bool mp[10][10][10][10][4][4];
map<char,int> con;
con['N']=0;
con['S']=1;
con['E']=2;
con['W']=3;
int ans=0;
char dc='N',df='N';
bool meet=false;
for(int i=0;i<10;i++)
{
for(int j=0;j<11;j++)
{

//cin>>a[i][j];
fscanf(fin,"%c",&a[i][j]);
//cout<<a[i][j];
if(a[i][j]=='F')
{f[0]=i;f[1]=j;}
else if(a[i][j]=='C')
{c[0]=i;c[1]=j;}
}
}

/*for(int i=0;i<10;i++)
{
for(int j=0;j<10;j++)
{
cout<<a[i][j];
}
cout<<endl;
}*/

for(int i=0;i<10;i++)
{
for(int j=0;j<10;j++)
{
for(int k=0;k<10;k++)
{
for(int l=0;l<10;l++)
{
for(int q=0;q<4;q++)
{
for(int w=0;w<4;w++)
{
mp[i][j][k][l][q][w]=false;
}
}
}
}
}
}

while(1)
{
//cout<<f[0]<<" "<<f[1]<<" "<<c[0]<<" "<<c[1]<<endl;
if(f[0]==c[0] && f[1]==c[1])
{
meet=true;
break;
}
if(mp[f[0]][f[1]][c[0]][c[1]][con[df]][con[dc]])
break;
mp[f[0]][f[1]][c[0]][c[1]][con[df]][con[dc]]=true;
move(f,df);
move(c,dc);
ans++;
}
if(!meet)
ans=0;
fprintf(fout,"%d\n",ans);
return 0;
}
