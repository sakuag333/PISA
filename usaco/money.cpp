/*
ID: sakuag31
LANG: C++
TASK: money
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
#include<cstdlib>
using namespace std;

int main()
{
FILE *fin  = fopen ("money.in", "r");
FILE *fout = fopen ("money.out", "w");
int n,v;
fscanf(fin,"%d%d",&v,&n);
long long int dp[n+1][v+1];
int coins[v+1];
for(int i=1;i<=v;i++)
fscanf(fin,"%d",&coins[i]);
sort(coins+1,coins+v+1);
//for(int i=1;i<=v;i++)
//cout<<coins[i]<<endl;
for(int i=0;i<=v;i++)
dp[0][i]=1;
for(int i=1;i<=n;i++)
dp[i][0]=0;
for(int i=1;i<=n;i++)
{
for(int j=1;j<=v;j++)
{
if(coins[j]<=i)
dp[i][j]=dp[i-coins[j]][j]+dp[i][j-1];
else
dp[i][j]=dp[i][j-1];
}
}
fprintf(fout,"%lld\n",dp[n][v]);
return 0;
}
