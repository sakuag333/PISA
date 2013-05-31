#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;

int main()
{
int m,ans;
char s[1000];
cin>>m;
getchar();
vector<int> v(26);
for(int i=0;i<m;i++)
{
cin.getline(&s[0],900);
//cout<<i<<" "<<s<<endl;
for(int j=0;j<26;j++)
v[j]=0;
for(int j=0;s[j]!='\0';j++)
{
if(isalpha(s[j]))
{
v[tolower(s[j])-'a']++;
}
}
sort(v.rbegin(),v.rend());
ans=0;
for(int j=0;j<26;j++)
ans=ans+v[j]*(26-j);
cout<<"Case #"<<i+1<<": "<<ans<<endl;
}
return 0;
}
