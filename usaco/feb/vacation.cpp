#include<iostream>
#include<map>
#include<algorithm>
#include<set>
#include<vector>
#include<stdio.h>
using namespace std;

vector<int> seg1(1200000),seg2(1200000),val(1200000),lazy(1200000),node(300000);
vector<vector<int> > edge(300000);
vector<bool> is_beauty(300000);
int diff[300000][2];
vector<int> mapping(600001),fact(300000);
vector<pair<int,int> > post_num(300000);
int cnt_diff[600100][2];

void create(vector<int> &v1,vector<int> &v2,int a,int b,int ind)
{
v1[ind]=a;
v2[ind]=b;
if(a==b)
return;
create(v1,v2,a,(a+b)>>1,(ind<<1)+1);
create(v1,v2,1+((a+b)>>1),b,(ind<<1)+2);
}

void update(vector<int> &v1,vector<int> &v2,vector<int> &v3,vector<int> &v4,int a,int b,int ind,int cnt)
{
if(v1[ind]==a && v2[ind]==b)
{
v3[ind]+=cnt;
v4[ind]+=cnt;
return;
}
v3[ind]+=cnt;
if(v4[ind]>0)
{
cnt+=v4[ind];
v4[ind]=0;
}
int mid=(v1[ind]+v2[ind])>>1;
if(b<=mid)
update(v1,v2,v3,v4,a,b,(ind<<1)+1,cnt);
else if(a>mid)
update(v1,v2,v3,v4,a,b,(ind<<1)+2,cnt);
else
{
update(v1,v2,v3,v4,a,mid,(ind<<1)+1,cnt);
update(v1,v2,v3,v4,1+mid,b,(ind<<1)+2,cnt);
}
}

int query(vector<int> &v1,vector<int> &v2,vector<int> &v3,vector<int> &v4,int a,int b,int ind)
{
if(a>b)
return 0;
if(v1[ind]==a && v2[ind]==b)
return v3[ind]+v4[ind];
int mid=(v1[ind]+v2[ind])>>1;
if(b<=mid)
return v4[ind]+query(v1,v2,v3,a,b,(ind<<1)+1);
else if(a>mid)
return v4[ind]+query(v1,v2,v3,a,b,(ind<<1)+2);
else
return v4[ind]+query(v1,v2,v3,a,mid,(ind<<1)+1) + query(v1,v2,v3,1+mid,b,(ind<<1)+2);
}

/*Assign values(difference of number of B and U) corresponding to each path starting from root of the tree(chosen arbitrarily to 0th node)*/
int tree_assign(int curr_node,int &curr_max)
{
int min1=1000000,tmp;
for(int i=0;i<edge[curr_node].size();i++)
{
tmp=tree_assign(edge[curr_node][i],curr_max);
if(tmp<min1)
min1=tmp;
}
if(min1==1000000)
min1=curr_max;
int k;
if(is_beauty[curr_node])
k=1;
else
k=-1;
update(seg1,seg2,val,lazy,min1,curr_max,0,k);
post_num[curr_node].first=min1;
post_num[curr_node].second=curr_max;
curr_max++;
return curr_max-1;
}

/*Assign factor to each node , which needs to be added to the values assigned by "tree_assign" to get the right value of path for each node*/
void factor(int curr_node,int &ind,int value)
{
int tmp=value;
if(is_beauty[curr_node])
value-=1;
else
value+=1;
for(int i=0;i<edge[curr_node].size();i++)
factor(curr_node,ind,value);
fact[ind]=value;
ind++;
}

int check(int a,int b)
{
if(a==b)
return 1;
return 0;
}

/*Get the number of paths with given difference*/
int tree_query(int node,int diff)
{
ind d=diff-fact[post_num[node].second]+n;
return cnt_diff[d][post_num[node].second]-cnt_diff[d][post_num[node].first]+check(val[post_num[node].first],diff);
}

/*----*/
int assign_cnt()
{
cnt_diff[0][0]=check(val[0],-1);
cnt_diff[1][0]=check(val[0],1);
for(int i=1;i<n;i++)
{
cnt_diff[0][i]=cnt_diff[0][i-1]+check(val[i],-1);
cnt_diff[1][i]=cnt_diff[0][i-1]+check(val[i],1);
}
}

int main()
{
int n,v1,v2;
scanf("%d",&n);
for(int i=0;i<n-1;i++)
{
scanf("%d%d",&v1,&v2);
edge[v1-1].push_back(v2-1);
edge[v2-1].push_back(v1-1);
}
for(int i=0;i<n;i++)
scanf("%d",&node[i]);
create(seg1,seg2,0,n-1,0);
tree_assign(0,0);
return 0;
factor(0,0,0);
}
