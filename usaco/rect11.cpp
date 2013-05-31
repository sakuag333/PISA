/*
ID: sakuag31
LANG: C++
TASK: rect1
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
using namespace std;

int f_min(int a,int b)
{
if(a<=b)
return a;
return b;
}

int f_max(int a,int b)
{
if(a>=b)
return a;
return b;
}

int f_area(int x1,int y1,int x2,int y2)
{
return (x2-x1+1)*(y2-y1+1);
}

int f_split(int x1,int y1,int x2,int y2,int a1,int b1,int a2,int b2,vector<pair<int,int> > &lole,vector<pair<int,int> > &upri)
{
if(a1>x2 || a2<x1 || b1>y2 || b2<y1)
{
lole.push_back(make_pair(x1,y1));
upri.push_back(make_pair(x2,y2));
return f_area(x1,y1,x2,y2);
}

a1=f_max(a1,x1);
b1=f_max(b1,y1);
a2=f_min(a2,x2);
b2=f_min(b2,y2);

int area=0;

if(x1<a1)
{lole.push_back(make_pair(x1,y1));upri.push_back(make_pair(a1-1,y2));area+=f_area(x1,y1,a1-1,y2);}
if(x2>a2)
{lole.push_back(make_pair(a2+1,y1));upri.push_back(make_pair(x2,y2));area+=f_area(a2+1,y1,x2,y2);}
if(y1<b1)
{lole.push_back(make_pair(a1,y1));upri.push_back(make_pair(a2,b1-1));area+=f_area(a1,y1,a2,b1-1);}
if(y2>b2)
{lole.push_back(make_pair(a1,b2+1));upri.push_back(make_pair(a2,y2));area+=f_area(a1,b2+1,a2,y2);}

return area;
}

int main()
{
FILE *fin  = fopen ("rect1.in", "r");
FILE *fout = fopen ("rect1.out", "w");
int a,b,n;
int rect[1002][5];
fscanf(fin,"%d%d%d",&a,&b,&n);
for(int i=0;i<n;i++)
{
fscanf(fin,"%d%d%d%d%d",&rect[i][0],&rect[i][1],&rect[i][2],&rect[i][3],&rect[i][4]);
rect[i][2]--;
rect[i][3]--;
}

int ans[2501];
for(int i=1;i<=2500;i++)
ans[i]=0;

vector<pair<int,int> > lo,up,tlo,tup;

lo.push_back(make_pair(0,0));
up.push_back(make_pair(a-1,b-1));
int old_area=a*b,new_area;
int color_white=0;

for(int i=n-1;i>=0;i--)
{
tlo.clear();
tup.clear();
new_area=0;
for(int j=0;j<lo.size();j++)
new_area+=f_split(lo[j].first,lo[j].second,up[j].first,up[j].second,rect[i][0],rect[i][1],rect[i][2],rect[i][3],tlo,tup);
ans[rect[i][4]]+=(old_area-new_area);
//ans.push_back(make_pair(rect[i][4],old_area-new_area));
old_area=new_area;
lo.clear();
up.clear();
//cout<<i<<endl;
for(int i=0;i<tlo.size();i++)
{
//cout<<tlo[i].first<<" "<<tlo[i].second<<" "<<tup[i].first<<" "<<tup[i].second<<endl;
lo.push_back(tlo[i]);
up.push_back(tup[i]);
}
}

//color_white+=old_area;
//if(color_white>0)
//ans.push_back(make_pair(1,color_white));

ans[1]+=old_area;

//sort(ans.begin(),ans.end());

for(int i=1;i<=2500;i++)
if(ans[i]>0)
fprintf(fout,"%d %d\n",i,ans[i]);

return 0;
}
