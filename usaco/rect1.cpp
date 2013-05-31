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
#include<set>
#include<queue>
#include<climits>
using namespace std;

int rect[1001][5];
int a,b,n;
vector<pair<int,int> > area;


inline int f_area(int x1,int y1,int x2,int y2)
{
return (x2-x1+1)*(y2-y1+1);
}

inline int f_tot(vector<pair<pair<int,int>,pair<int,int> > > &v)
{
int val=0;
for(int k=0;k<v.size();k++)
{
val+=f_area(v[k].first.first,v[k].first.second,v[k].second.first,v[k].second.second);
}
return val;
}

inline int f_min(int a,int b)
{
if(a<=b)
return a;
return b;
}

inline int f_max(int a,int b)
{
if(a>=b)
return a;
return b;
}

inline void split(int x1,int y1,int x2,int y2,int a1,int b1,int a2,int b2,vector<pair<pair<int,int>,pair<int,int> > > &v)
{
if(x1<a1)
v.push_back(make_pair(make_pair(x1,y1),make_pair(f_min(a1-1,x2),y2)));
if(x2>a2)
v.push_back(make_pair(make_pair(f_max(a2+1,x1),y1),make_pair(x2,y2)));
if(y1<b1)
v.push_back(make_pair(make_pair(f_max(a1,x1),y1),make_pair(f_min(a2,x2),f_min(b1-1,y2))));
if(y2>b2)
v.push_back(make_pair(make_pair(f_max(a1,x1),f_max(b2+1,y1)),make_pair(f_min(x2,a2),y2)));
}

int main()
{
FILE *fin  = fopen ("rect1.in", "r");
FILE *fout = fopen ("rect1.out", "w");
fscanf(fin,"%d%d%d",&a,&b,&n);
for(int i=0;i<n;i++)
{
fscanf(fin,"%d%d%d%d%d",&rect[i][0],&rect[i][1],&rect[i][2],&rect[i][3],&rect[i][4]);
rect[i][2]--;
rect[i][3]--;
}
int tmp,val=0,ind,tmp_st;
vector<pair<pair<int,int>,pair<int,int> > > v,t;
/*v.push_back(make_pair(make_pair(rect[n-1][0],rect[n-1][1]),make_pair(rect[n-1][2],rect[n-1][3])));
for(int i=n-1;i>=0;i--)
{
if(val==a*b)
break;
ind=v.size();
tmp_st=ind;
for(int k=0;k<ind;k++)
{
split(rect[i][0],rect[i][1],rect[i][2],rect[i][3],v[k].first.first,v[k].first.second,v[k].second.first,v[k].second.second,v);
}
for(int i1=0;i1<v.size();i1++)
{
cout<<v[i1].first.first<<" "<<v[i1].first.second<<" "<<v[i1].second.first<<" "<<v[i1].second.second<<endl;
}
cout<<endl;
tmp=0;
for(int k=0;k<v.size();k++)
tmp+=f_area(v[k].first.first,v[k].first.second,v[k].second.first,v[k].second.second);
area.push_back(make_pair(rect[i][4],tmp-val));
val=tmp;
}
if(a*b-val>0)
area.push_back(make_pair(1,a*b-val));*/



v.push_back(make_pair(make_pair(0,0),make_pair(a-1,b-1)));
int old_area,new_area;

for(int i=n-1;i>=0;i--)
{
t.clear();
old_area=f_tot(v);
for(int k=0;k<v.size();k++)
split(v[k].first.first,v[k].first.second,v[k].second.first,v[k].second.second,rect[i][0],rect[i][1],rect[i][2],rect[i][3],t);
v.clear();
for(int i1=0;i1<t.size();i1++)
{
v.push_back(t[i1]);
cout<<v[i1].first.first<<" "<<v[i1].first.second<<" "<<v[i1].second.first<<" "<<v[i1].second.second<<endl;
}
cout<<endl;
new_area=f_tot(v);
area.push_back(make_pair(rect[i][4],old_area-new_area));
val+=old_area-new_area;
old_area=new_area;
}



if(a*b-val>0)
area.push_back(make_pair(1,a*b-val));
sort(area.begin(),area.end());
for(int i=0;i<area.size();i++)
fprintf(fout,"%d %d\n",area[i].first,area[i].second);
return 0;
}
