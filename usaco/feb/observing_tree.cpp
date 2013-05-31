#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

int n,m,root;
vector<vector<int> > adj(100000);
vector<int> chain(100000),skip(100000),par(100000),subtree(100000),depth(100000);

int calc_subtree(int node,int d)
{
int tmp=1;
for(int i=0;i<adj[node].size();i++)
tmp+=calc_subtree(adj[node][i],d+1);
subtree[node]=tmp;
depth[node]=d;
return tmp;
}

bool is_heavy(int u,int v)
{
if(subtree[u]>(subtree[v])/2)
return true;
return false;
}

class node
{
int seg1,seg2;
vector<long long int> lazy,val;
};

class segment
{
public:
int time;
node *seg;
segment(int t,int lo,int hi,bool is_start)
{
time=t;
seg=new seg[3*(hi-lo+1)];
if(is_start)
create(0,lo,hi);
}
void create(int ind,int lo,int hi)
{
seg[ind].seg1=lo;
seg[ind].seg2=hi;
seg[ind].lazy=0;
seg[ind].val=0;
if(lo==hi)
return;
create(lo,(lo+hi)>>1,(ind<<1)+1);
create(1+((lo+hi)>>1),hi,(ind<<1)+2);
}
void update(int ind,int lo,int hi,long long int cnt)
{
if(seg[ind].seg1==lo && seg[ind].seg2==hi)
{
seg[ind].val+=cnt;
seg[ind].lazy+=cnt;
return;
}
seg[ind].val+=cnt;
if(seg[ind].lazy>0)
{
cnt+=seg[ind].lazy;
seg[ind].lazy=0;
}
int mid=(seg[ind].seg1+seg[ind].seg2)>>1;
if(hi<=mid)
update(lo,hi,(ind<<1)+1,cnt);
else if(lo>mid)
update(lo,hi,(ind<<1)+2,cnt);
else
{
update(lo,mid,(ind<<1)+1,cnt);
update(1+mid,hi,(ind<<1)+2,cnt);
}
}
long long int query(int lo,int hi,int ind)
{
if(lo>hi)
return 0;
if(seg[ind].seg1==lo && seg[ind].seg2==hi)
return seg[ind].val;
int mid=(seg[ind].seg1+seg[ind].seg2)>>1;
if(hi<=mid)
return seg[ind].lazy+query(lo,hi,(ind<<1)+1);
else if(lo>mid)
return seg[ind].lazy+query(lo,hi,(ind<<1)+2);
else
return seg[ind].lazy+query(lo,mid,(ind<<1)+1) + query(1+mid,hi,(ind<<1)+2);
}
};

class chain
{
public:
int num;
vector<segment*> v;
chain(int k)
{
num=k;
v.push_back(new segment(0,0,k-1));
}
void update(int q_num,int node1,int node2,long long int a,long long int b)
{
int d=node2-node1+1;
long long int sum=a*d+b*(((d-1)*d)/2)
v.push_back(new segment(q_num,0,k-1));
v[v.size()-1].update(node1,node2,0,sum);
}
};

vector<chain*> chains;

void calc_chain(int node,int cnt_node,int start_node)
{
for(int i=0;i<adj[node].size();i++)
{
if(is_heavy(a[node][i]),node)
{
chain[node]=chains.size();
if(cnt_node==0)
calc_chain(adj[node][i],cnt_node+1,par[node]);
else
calc_chain(adj[node][i],cnt_node+1,start_node);
}
else
{
if(cnt_node>0)
{
chain[node]=chains.size();
skip[node]=start_node;
chains.push_back(new chain(cnt_node+1));
}
calc_chain(adj[node][i],0,-2);
}
}
}

int swap(int &u,int &v)
{
int tmp=v;
v=u;
u=tmp;
}

int lca(int u,int v)
{
int last=root;
int n1,n2;
while(u!=v)
{
if(depth[u]<depth[v])
swap(u,v);
if(is_heavy(u,par[u]))
{
last=u;
u=skip[u];
}
else
{
last=root;
u=par[u];
}
}
if(last==root)
return u;
return last;
}

int main()
{
int u,v;
scanf("%d%d",&n,&m);
root=-1;
for(int i=0;i<n-1;i++)
{
scanf("%d%d",&u,&v);
if(root==-1)
root=u-1;
adj[u-1].push_back(v-1);
par[v-1]=u;
}
par[root]=-1;
for(int i=0;i<n;i++)
chain[i]=-1;
return 0;
}
