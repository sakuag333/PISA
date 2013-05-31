#include<iostream>
#include<vector>
#include<cstdlib>
#include<map>
#include<stdio.h>
using namespace std;

char a[2501][2501];
int n,sz;
vector<double> path;
vector<double> sum_path;

inline double f_max(double x,double y)
{
if(x>=y)
return x;
return y;
}

inline int decr(int x)
{
if(x==0)
return (path.size()/2)-1;
return x-1;
}
 
inline int incr(int x)
{
if(x==(path.size()/2)-1)
return 0;
return x+1;
}
 
inline int f_diff(int beg,int end)
{
if(beg<=end)
return end-beg;
return path.size()-beg+end;
}
 
 inline double f_clock2(int beg,int end)
{
double t1,t2,tmp,diff=1000000009,tmp1,tmp2;
int st=beg,ed=decr(end);
if(st==ed)
{
//diff=path[st];
//diff/=2;
//return diff;
return path[st]/2;
}
t1=0;
t2=0;
for(int i=incr(st);;i=incr(i))
{
//tmp2=path[i];
t2+=path[i];
if(i==ed)
break;
}
for(int i=st;;i=incr(i))
{
//tmp1=path[i]/2;
//tmp1/=2;
tmp2=(path[i]/2)+f_max(t1,t2);
//tmp=tmp1+tmp2;
if(tmp2<diff)
diff=tmp2;
if(i==ed)
break;
//tmp2=path[i];
t1+=path[i];
//tmp2=path[incr(i)];
t2-=path[incr(i)];
}
return diff;
}
inline double f_min(double x,double y)
{
if(x<=y)
return x;
return y;
}

inline double f_abs(double x,double y)
{
if(x-y>=0)
return x-y;
return y-x;
}


inline int f_num(string &str)
{
int k=0;
for(int i=1;i<str.length();i++)
k=k*10+(str[i]-'0');
return k;
}

double f_sum(int x,int y)
{
if(x>y)
return 0;
if(x==0)
return sum_path[y];
return sum_path[y]-sum_path[x-1];
}

int b_search1(int x,int y,int st,int ed)
{
//cout<<x<<" "<<y<<endl;
if(x==y)
return x;
if(y-x==1)
{
int t1=f_abs(f_sum(st,x),f_sum(y,ed));
int t2=f_abs(f_sum(st,x-1),f_sum(x,ed));
int t3=f_abs(f_sum(st,y),f_sum(y+1,ed));
if(t1<=t2 && t1<=t3)
return x;
else if(t2<=t1 && t2<=t3)
return x-1;
else
return y;
}
int mid=(x+y)/2;
int t1=f_sum(st,mid),t2=f_sum(mid+1,ed);
if(t1==t2)
return mid;
if(t1<t2)
return b_search1(mid,y,st,ed);
return b_search1(x,mid,st,ed);
}

int b_search2(int x,int y,int st,int ed)
{
//cout<<x<<" "<<y<<endl;
if(x==y)
return x;
if(y-x==1)
{
int t1=f_abs(f_sum(st,x),f_sum(y,ed));
int t2=f_abs(f_sum(st,x-1),f_sum(x,ed));
int t3=f_abs(f_sum(st,y),f_sum(y+1,ed));
if(t1<=t2 && t1<=t3)
return y;
else if(t2<=t1 && t2<=t3)
return x;
else
return y+1;
}
int mid=(x+y)/2;
int t1=f_sum(st,mid-1),t2=f_sum(mid,ed);
if(t1==t2)
return mid;
if(t1<t2)
return b_search2(mid,y,st,ed);
return b_search2(x,mid,st,ed);
}

double f_clock(int beg,int end)
{
if(beg>end)
end+=sz;
int st=beg,ed=end-1;
//cout<<st<<ed<<endl;
if(st==ed)
return path[st]/2;
if(ed-st==1)
{
return f_min((path[st]+(path[ed]/2)),(path[ed]+(path[st]/2)));
}
int pivot1=b_search1(st,ed,st,ed);
//return f_max(f_sum(st,pivot1-1),f_sum(pivot1+1,ed))+(path[pivot1]/2);
int pivot2=b_search2(st,ed,st,ed);
return f_min(f_max(f_sum(st,pivot1-1),f_sum(pivot1+1,ed))+(path[pivot1]/2),f_max(f_sum(st,pivot2-2),f_sum(pivot2,ed))+(path[pivot2-1]/2));
}

void move(int &r,int &c,char dir)
{
if(dir=='e')
c++;
else if(dir=='s')
r++;
else if(dir=='w')
c--;
else if(dir=='n')
r--;
}

void change_dir(int r,int c,char &dir)
{
if(dir=='e' || dir=='w')
{
if(r-1>=0 && (a[r-1][c]=='|' || a[r-1][c]=='+'))
dir='n';
else
dir='s';
}
else
{
if(c-1>=0 && (a[r][c-1]=='-' || a[r][c-1]=='+'))
dir='w';
else
dir='e';
}
}

bool check_alp1ha(int r,int c,char prev_dir,char dir,char &alp1,int &loc1,int &loc2)
{
if(prev_dir=='n')
{
if(dir=='e')
{
loc1=r+1;
loc2=c+1;
alp1=a[r+1][c+1];
return isalpha(a[r+1][c+1]);
}
else
{
loc1=r+1;
loc2=c-1;
alp1=a[r+1][c-1];
return isalpha(a[r+1][c-1]);
}
}
if(prev_dir=='e')
{
if(dir=='s')
{
loc1=r+1;
loc2=c-1;
alp1=a[r+1][c-1];
return (c-1>=0) && isalpha(a[r+1][c-1]);
}
else
{
loc1=r-1;
loc2=c-1;
alp1=a[r-1][c-1];
return (r-1>=0) && (c-1>=0) && isalpha(a[r-1][c-1]);
}
}
if(prev_dir=='s')
{
if(dir=='w')
{
loc1=r-1;
loc2=c-1;
alp1=a[r-1][c-1];
return (r-1>=0) && (c-1>=0) && isalpha(a[r-1][c-1]);
}
else
{
loc1=r-1;
loc2=c+1;
alp1=a[r-1][c+1];
return (r-1>=0) && isalpha(a[r-1][c+1]);
}
}
else
{
if(dir=='n')
{
loc1=r-1;
loc2=c+1;
alp1=a[r-1][c+1];
return (r-1>=0) && isalpha(a[r-1][c+1]);
}
else
{
loc1=r+1;
loc2=c+1;
alp1=a[r+1][c+1];
return isalpha(a[r+1][c+1]);
}
}
}

int main()
{
int r,c,t;
string p1,p2;
bool ck=true;
scanf("%d",&n);
int b[26];
bool coord1[2501][2501];
for(int i=0;i<2501;i++)
for(int j=0;j<2501;j++)
{
a[i][j]='#';
coord1[i][j]=false;
}
int cnt_alp1ha=0,mapping1[26][2501];
int mp2[26][2501];
for(int i=0;i<26;i++)
b[i]=1;
getchar();
for(int i=0;i<n;i++)
{
int j=0;
while(1)
{
a[i][j]=getchar_unlocked();
//scanf("%c",&a[i][j]);
if(a[i][j]=='\n' || a[i][j]=='\0')
break;
if(ck && a[i][j]=='+')
{ck=false;r=i;c=j;}
j++;
}
}

/*for(int i=0;i<n;i++)
{
int j=0;
while(1)
{
printf("%c",a[i][j]);
if(a[i][j]=='\n')
break;
j++;
}
}*/


double steps1;
int st1=r,st2=c,curr1,curr2,loc1,loc2,st_alpha1,st_alpha2,index1=0;
char dir='e',alp1;
check_alp1ha(r,c,'n','e',alp1,loc1,loc2);
st_alpha1=loc1;
st_alpha2=loc2;
curr1=r;
curr2=c;
coord1[loc1][loc2]=true;
mp2[alp1-'A'][loc1]=cnt_alp1ha;
cnt_alp1ha++;
steps1=0;
char prev_dir;
bool fck=false;
while(1)
{
move(curr1,curr2,dir);
if(curr1==st1 && curr2==st2)
{
path.push_back(steps1-1);
break;
}
//cout<<a[curr1][curr2];
if(a[curr1][curr2]=='+')
{
//cout<<endl;
prev_dir=dir;
change_dir(curr1,curr2,dir);
if(check_alp1ha(curr1,curr2,prev_dir,dir,alp1,loc1,loc2))
{
if(!coord1[loc1][loc2])
{
coord1[loc1][loc2]=true;
mp2[alp1-'A'][loc1]=cnt_alp1ha;
cnt_alp1ha++;
path.push_back(steps1-1);
steps1=0;
}
else
{
if(loc1==st_alpha1 && loc2==st_alpha2)
{
if(curr2!=st2+2)
{
path.push_back(steps1-1);
break;
}
}
steps1=0;
}
}
else
steps1+=3;
}
else
steps1++;
}

for(int i=0;i<n;i++)
{
int j=0;
while(1)
{
if(a[i][j]=='\n' || a[i][j]=='\0')
break;
if(isalpha(a[i][j]))
{
mapping1[a[i][j]-'A'][b[a[i][j]-'A']]=mp2[a[i][j]-'A'][i];
b[a[i][j]-'A']++;
}
j++;
}
}

sz=path.size();

for(int i=0;i<sz;i++)
path.push_back(path[i]);

sum_path.push_back(path[0]);
for(int i=1;i<path.size();i++)
sum_path.push_back(path[i]+sum_path[i-1]);

/*
cout<<cnt_alp1ha<<endl;
for(int i=0;i<path.size();i++)
{
cout<<path[i]<<" ";
}
cout<<endl;
*/

scanf("%d",&t);
getchar();
char s,d;
int ns,nd,beg,end;
double ans1,ans2;
char g;
for(int i=0;i<t;i++)
{
p1="";
p2="";
while(1)
{
g=getchar_unlocked();
if(g==' ' || g=='\n' || g=='\0')
break;
p1+=g;
}
while(1)
{
scanf("%c",&g);
if(g==' ' || g=='\n' || g=='\0')
break;
p2+=g;
}
s=p1[0];
d=p2[0];
ns=f_num(p1);
nd=f_num(p2);
beg=mapping1[s-'A'][ns];
end=mapping1[d-'A'][nd];
if(cnt_alp1ha<=-1)
{
ans1=f_clock2(beg,end);
ans2=f_clock2(end,beg);
}
else
{
ans1=f_clock(beg,end);
ans2=f_clock(end,beg);
}
//cout<<ans1<<" "<<ans2<<endl;
if(ans1<=ans2)
printf("%0.2lf\n",ans1);
else
printf("%0.2lf\n",ans2);
}

return 0;
}
