/*
ID: sakuag31
LANG: C++
TASK: shopping
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
#include<stack>
#include<climits>
using namespace std;

map<pair<int,int>,int> mp;
int quant[1001],cost[1001];
vector<int> code;
int s,offer[101][5][2],num[101],b,prod,number,price,offer_price[101],product;

int f(int ofr)
{
if(ofr==s)
{
int val=0;
for(int i=0;i<code.size();i++)
val+=(cost[code[i]]*quant[code[i]]);
return val;
}


int k=0;
for(int i=0;i<code.size();i++)
k=10*k+quant[code[i]];
if(mp[make_pair(ofr,k)]>0)
return mp[make_pair(ofr,k)];



int pro;
bool ck=true;
for(int i=0;i<num[ofr];i++)
{
pro=offer[ofr][i][0];
if(quant[pro]<offer[ofr][i][1])
{ck=false;break;}
}
int tmp1=INT_MAX,tmp2=INT_MAX;
if(ck)
{
for(int i=0;i<num[ofr];i++)
{
pro=offer[ofr][i][0];
quant[pro]-=offer[ofr][i][1];
}
tmp1=offer_price[ofr]+f(ofr);
}
if(ck)
{
for(int i=0;i<num[ofr];i++)
{
pro=offer[ofr][i][0];
quant[pro]+=offer[ofr][i][1];
}
}
tmp2=f(ofr+1);
if(tmp1<=tmp2)
mp[make_pair(ofr,k)]=tmp1;
else
mp[make_pair(ofr,k)]=tmp2;
return mp[make_pair(ofr,k)];
}

int main()
{
FILE *fin  = fopen ("shopping.in", "r");
FILE *fout = fopen ("shopping.out", "w");
fscanf(fin,"%d",&s);
for(int i=0;i<s;i++)
{
fscanf(fin,"%d",&num[i]);
for(int j=0;j<num[i];j++)
fscanf(fin,"%d%d",&offer[i][j][0],&offer[i][j][1]);
fscanf(fin,"%d",&offer_price[i]);
}
fscanf(fin,"%d",&b);
for(int i=0;i<b;i++)
{
fscanf(fin,"%d%d%d",&product,&number,&price);
quant[product]=number;
cost[product]=price;
code.push_back(product);
}
fprintf(fout,"%d\n",f(0));
return 0;
}
