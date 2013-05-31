/*
ID: sakuag31
LANG: C++
TASK: contact
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
#include<cmath>
using namespace std;

map<pair<long long int,int>,int> mp;
int ind=1;
string s;
long long int t;
vector<pair<int,string> > ans;

int f_min(int a,int b)
{
if(a<=b)
return a;
return b;
}

string to_str(long long int v,int pad)
{
long long int va=v;
string t="";
char x;
int f=0;
while(va>0)
{
f++;
x='0'+(va%2);
t=x+t;
va/=2;
}
while(f<pad)
{
t='0'+t;
f++;
}
return t;
}

void f(int l)
{
long long int val=0;
long long int p=pow(2,l-1);
for(int i=0;i<l;i++)
val=val*2+(s[i]-'0');
mp[make_pair(val,l)]++;
for(int i=l;i<s.length();i++)
{
if(s[i-l]=='1')
val-=p;
val*=2;
val+=(s[i]-'0');
mp[make_pair(val,l)]++;
}
}

int main()
{
FILE *fin  = fopen ("contact.in", "r");
FILE *fout = fopen ("contact.out", "w");
int a1,b1,n;
s="";
fscanf(fin,"%d%d%d",&a1,&b1,&n);
char c;
while(fscanf(fin,"%c",&c)!=EOF)
if(c=='0' || c=='1')
s+=c;
for(int l=a1;l<=f_min(b1,s.length());l++)
f(l);
int y1;
string y2;
for(map<pair<long long int,int>,int>::iterator it=mp.begin();it!=mp.end();it++)
{
y1=(*it).second;
y2=to_str((*it).first.first,(*it).first.second);
//cout<<y1<<" "<<(*it).first.first<<" "<<y2<<endl;
ans.push_back(make_pair(y1,y2));
}
sort(ans.rbegin(),ans.rend());
int cnt=0;
int prev=ans[0].first;
int line;
vector<pair<int,string> > tmp1;
for(int i=0;i<ans.size() && cnt<n;i++)
{
fprintf(fout,"%d\n",ans[i].first);
prev=ans[i].first;
tmp1.clear();
while(i<ans.size() && ans[i].first==prev)
{
//cout<<i<<endl;
tmp1.push_back(make_pair(ans[i].second.length(),ans[i].second));
i++;
}
sort(tmp1.begin(),tmp1.end());
line=0;
for(int j=0;j<tmp1.size();j++)
{
for(int k=0;k<(tmp1[j].second).length();k++)
{
fprintf(fout,"%c",(tmp1[j].second)[k]);
}
line++;
if(j==tmp1.size()-1 || line%6==0)
fprintf(fout,"\n");
else
fprintf(fout," ");
}
i--;
cnt++;
}
return 0;
}
