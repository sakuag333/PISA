#include<iostream>
#include<map>
using namespace std;

int main()
{
int t,ans;
map<char,int> mp;
string s;
cin>>t;
for(int i=0;i<t;i++)
{
cin>>s;
mp.clear();
for(int j=0;j<s.length();j++)
mp[s[j]]++;
ans=0;
for(char x='a';x<='z';x++)
ans=ans+((1+mp[x])/2);
for(char x='A';x<='Z';x++)
ans=ans+((1+mp[x])/2);
cout<<ans<<endl;
}
return 0;
}
