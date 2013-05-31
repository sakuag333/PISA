/*
ID: sakuag31
LANG: C++
TASK: packrec
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>
using namespace std;


int glo[4][2];
int ans=100000000;
set<pair<int,int> > v;

int f_max(int a,int b)
{
if(a>=b)
return a;
return b;
}

int f_min(int a,int b)
{
if(a<=b)
return a;
return b;
}

void k(int tmp,int w,int h)
{
if(tmp<ans)
{
ans=tmp;
v.clear();
if(w<=h)
v.insert(make_pair(w,h));
else
v.insert(make_pair(h,w));
}
else if(tmp==ans)
{
if(w<=h)
v.insert(make_pair(w,h));
else
v.insert(make_pair(h,w));
}
}

void print(int b[][2])
{
cout<<"="<<endl;
for(int i=0;i<4;i++)
{
cout<<b[i][0]<<" "<<b[i][1]<<endl;
}
}

void calc1(int b[][2])
{
int width=b[0][0]+b[1][0]+b[2][0]+b[3][0];
int height=f_max(f_max(b[0][1],b[1][1]),f_max(b[2][1],b[3][1]));
//if(width*height==36)
//{cout<<"1"<<endl;print(b);}
k(width*height,width,height);
}

void calc2(int b[][2])
{
int width=f_max(b[0][0]+b[1][0]+b[2][0],b[3][0]);
int height=f_max(b[0][1],f_max(b[1][1],b[2][1]))+b[3][1];
k(width*height,width,height);
//if(width*height==36)
//{cout<<"2"<<endl;print(b);}
}

void calc3(int b[][2])
{
int width=f_max(b[0][0]+b[1][0],b[3][0])+b[2][0];
int height=f_max(f_max(b[0][1],b[1][1])+b[3][1],b[2][1]);
k(width*height,width,height);
//if(width*height==36)
//{cout<<"3"<<endl;print(b);}
}

void calc4(int b[][2])
{
int width=b[0][0]+b[2][0]+f_max(b[1][0],b[3][0]);
int height=f_max(b[1][1]+b[3][1],f_max(b[0][1],b[2][1]));
k(width*height,width,height);
//if(width*height==36)
//{cout<<"4"<<endl;print(b);}
}

void calc5(int b[][2])
{
int width=b[1][0]+b[2][0]+f_max(b[0][0],b[3][0]);
int height=f_max(b[0][1]+b[3][1],f_max(b[1][1],b[2][1]));
k(width*height,width,height);
//if(width*height==36)
//{cout<<"5"<<endl;print(b);}
}

void calc6(int b[][2])
{
int width;
if((b[0][1]>=b[1][1] && b[2][0]>=b[0][0]) || (b[1][1]>=b[0][1] && b[3][0]>=b[1][0]))
width=f_max(b[0][0]+b[1][0],b[2][0]+b[3][0]);
else
width=f_max(b[0][0],b[2][0])+f_max(b[1][0],b[3][0]);
int height=f_max(b[0][1]+b[2][1],b[1][1]+b[3][1]);
k(width*height,width,height);
//if(width*height==36)
//{cout<<"6"<<endl;print(b);}
}

void z(int b[][2])
{
calc1(b);
calc2(b);
calc3(b);
calc4(b);
calc5(b);
calc6(b);
}

void g(int l,bool r[],string s)
{

if(l==0)
{
int b[4][2];
for(int q=0;q<2;q++)
{
for(int w=0;w<2;w++)
{
for(int e=0;e<2;e++)
{
for(int t=0;t<2;t++)
{
b[0][0]=glo[s[0]-'0'][q];
b[0][1]=glo[s[0]-'0'][1-q];

b[1][0]=glo[s[1]-'0'][w];
b[1][1]=glo[s[1]-'0'][1-w];

b[2][0]=glo[s[2]-'0'][e];
b[2][1]=glo[s[2]-'0'][1-e];

b[3][0]=glo[s[3]-'0'][t];
b[3][1]=glo[s[3]-'0'][1-t];

//print(b);
z(b);
}
}
}
}
return;
}

for(int i=0;i<4;i++)
{
if(r[i])
continue;
char x='0'+i;
string t=s;
t+=x;
bool y[4];
for(int j=0;j<4;j++)
y[j]=r[j];
y[i]=true;
g(l-1,y,t);
}
}

int main()
{
FILE *fin  = fopen ("packrec.in", "r");
FILE *fout = fopen ("packrec.out", "w");
for(int i=0;i<4;i++)
for(int j=0;j<2;j++)
fscanf(fin,"%d",&glo[i][j]);
string t="";
bool r[4];
for(int i=0;i<4;i++)
r[i]=false;
g(4,r,t);
fprintf(fout,"%d\n",ans);
for(set<pair<int,int> >::iterator it=v.begin();it!=v.end();it++)
fprintf(fout,"%d %d\n",(*it).first,(*it).second);
return 0;
}
