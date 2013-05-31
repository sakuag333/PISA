#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

int main()
{
int n,m,q;
double frequency,f0;
cin>>n>>m;
vector<pair<double,int> > quality(n);
vector<string> song_list(n); 
for(double i=0;i<n;i++)
{
cin>>frequency>>song_list[i];
if(i==0)
f0=frequency;
quality[i]=make_pair(-1*((i+1)*frequency)/f0,i);
}
sort(quality.begin(),quality.end());
for(int i=0;i<m;i++)
cout<<song_list[quality[i].second]<<endl;
return 0;
}
