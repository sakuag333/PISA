/*
ID: sakuag31
LANG: C++
TASK: msquare
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
#include<queue>
using namespace std;

string ans,targ,start;
char t[8];
map<string,bool> ck1;
map<pair<string,int>,bool> mp;

bool f(string s,char s1,char s2,char s3,char s4,char s5, char s6,char s7,char s8,int l)
{
if(s1==t[0] && s2==t[1] && s3==t[2] && s4==t[3] && s5==t[4] && s6==t[5] && s7==t[6] && s8==t[7])
{ans=s;return true;}
if(s.length()==l)
return false;
string k="";
k=k+s1+s2+s3+s4+s5+s6+s7+s8;
//if(k=="41236785")
//cout<<s<<" "<<l<<endl;
if(mp[make_pair(k,s.length())])
{/*cout<<k<<" "<<s<<" "<<l<<endl;*/return false;}
mp[make_pair(k,s.length())]=true;
bool ck;
ck=f(s+'A',s8,s7,s6,s5,s4,s3,s2,s1,l);
if(ck)
return true;
ck=f(s+'B',s4,s1,s2,s3,s6,s7,s8,s5,l);
if(ck)
return true;
ck=f(s+'C',s1,s7,s2,s4,s5,s3,s6,s8,l);
if(ck)
return true;
return false;
}

string h1(string str)
{
string p="";
for(int i=7;i>=0;i--)
p+=str[i];
return p;
}

string h2(string str)
{
string p="";
p+=str[3];
for(int i=0;i<=2;i++)
p+=str[i];
for(int i=5;i<=7;i++)
p+=str[i];
p+=str[4];
return p;
}

string h3(string str)
{
string p="";
p+=str[0];
p+=str[6];
p+=str[1];
p+=str[3];
p+=str[4];
p+=str[2];
p+=str[5];
p+=str[7];
return p;
}

bool check(string str)
{
for(int i=0;i<8;i++)
if(str[i]!=targ[i])
return false;
return true;
}

string g()
{
string ans_str;
queue<pair<string,string> > q;
q.push(make_pair(start,""));
bool ck;
pair<string,string> pr;
while(!q.empty())
{
pr=q.front();
q.pop();
if(check(pr.first))
{ans_str=pr.second;break;}
if(ck1[(pr.first)])
continue;
ck1[(pr.first)]=true;
q.push(make_pair(h1(pr.first),(pr.second)+'A'));
q.push(make_pair(h2(pr.first),(pr.second)+'B'));
q.push(make_pair(h3(pr.first),(pr.second)+'C'));
}
return ans_str;
}

int main()
{
FILE *fin  = fopen ("msquare.in", "r");
FILE *fout = fopen ("msquare.out", "w");
int a;
char st[8];
targ="";
for(int i=0;i<8;i++)
{
//st[i]='0'+(i+1);
fscanf(fin,"%d",&a);
//t[i]='0'+a;
targ+=('0'+a);
start+=('0'+(i+1));
}
/*int l=0;
bool ck=false;
string d;
while(!ck)
{
mp.clear();
//cout<<l<<endl;
d="";
ck=f(d,st[0],st[1],st[2],st[3],st[4],st[5],st[6],st[7],l);
l++;
}*/

ans=g();
fprintf(fout,"%d\n",ans.length());
for(int i=0;i<ans.length();i++)
fprintf(fout,"%c",ans[i]);
fprintf(fout,"\n");
return 0;
}
