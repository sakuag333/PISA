#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
string s1,s2;
cin>>s1>>s2;
int t1=1,t2=1;
for(int i=0;i<s1.length();i++)
{
t1=(t1*(s1[i]-'A'+1))%47;
}
for(int i=0;i<s2.length();i++)
{
t2=(t2*(s2[i]-'A'+1))%47;
}
if(t1==t2)
printf("GO\n");
else
printf("STAY\n");
return 0;
}
