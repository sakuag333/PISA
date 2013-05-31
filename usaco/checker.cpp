/*
ID: sakuag31
LANG: C++
TASK: checker
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>
#include<set>
using namespace std;

vector<string> ans2;
set<string> ans;
int n,cnt=0;

FILE *fin  = fopen ("checker.in", "r");
FILE *fout = fopen ("checker.out", "w");

inline string g(int y)
{
string h="";
char x;
while(y>0)
{
x='0'+(y%10);
h=x+h;
y/=10;
}
return h;
}

inline string convert(int p[])
{
string k="",t;
int tmp;
char x;
for(int i=0;i<n;i++)
{
tmp=p[i];
/*while(tmp>0)
{
x='0'+(tmp%10);
k+=x;
tmp/=10;
}*/
t=g(tmp);
k+=t;
k+=" ";
}
return k;
}

void f(int col,int row[],bool r[],bool d1[],bool d2[])
{
if(col==n)
{
cnt++;
if(ans2.size()==3)
return;
string k=convert(row);
//if(k=="01 1 4 6 3 9 2 8 5 7 ")
//for(int i=0;i<n;i++)
//cout<<row[i]<<endl;
//ans.insert(k);
ans2.push_back(k);
return;
}
for(int i=0;i<n;i++)
{
if(r[i] || d1[n-1+col-i] || d2[col+i])
continue;
//if(row[0]==4)
//cout<<col<<" "<<i<<" "<<n<<endl;
row[col]=i+1;
r[i]=true;
d1[n-1+col-i]=true;
d2[col+i]=true;
f(col+1,row,r,d1,d2);
r[i]=false;
d1[n-1+col-i]=false;
d2[col+i]=false;
/*int trow[n];
bool td1[2*n-1],td2[2*n-1],tr[n];
for(int i1=0;i1<n;i1++)
{
trow[i1]=row[i1];
tr[i1]=r[i1];
}
for(int i1=0;i1<2*n-1;i1++)
{
td1[i1]=d1[i1];
td2[i1]=d2[i1];
}
trow[col]=i+1;
tr[i]=true;
td1[n-1+col-i]=true;
td2[col+i]=true;
f(col+1,trow,tr,td1,td2);*/
}
//cout<<"===="<<endl;
}

int main()
{
fscanf(fin,"%d",&n);
int row[n];
bool r[n],d1[2*n-1],d2[2*n-1];
for(int i=0;i<n;i++)
{
row[i]=-1;
r[i]=false;
d1[i]=false;
d2[i]=false;
}
for(int i=0;i<n-1;i++)
{
d1[n+i]=false;
d2[n+i]=false;
}
f(0,row,r,d1,d2);
//sort(ans.begin(),ans.end());
/*set<string>::iterator it=ans.begin();
for(int i=0;i<3;i++)
{
for(int j=0;j<(*it).length();j++)
{
while((*it)[j]!=' ')
{
fprintf(fout,"%c",(*it)[j]);
j++;
}
if(j<(*it).length()-2)
fprintf(fout," ");
}
fprintf(fout,"\n");
it++;
}*/
//cout<<ans2[0]<<" "<<ans2[1]<<" "<<ans2[2]<<endl;
for(int i=0;i<3;i++)
{
for(int j=0;j<ans2[i].length();j++)
{
while(ans2[i][j]!=' ')
{
fprintf(fout,"%c",ans2[i][j]);
j++;
}
if(j<ans2[i].length()-2)
fprintf(fout," ");
}
fprintf(fout,"\n");
}
fprintf(fout,"%d\n",cnt);
return 0;
}
