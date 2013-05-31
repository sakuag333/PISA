#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int dec(int x,int k)
{
if(x==0)
return k-1;
return x-1;
}

int main()
{
long long int t,n,k,a,b,c,r;
int max1,max2,val,st;
int cnt,min1,ind,tmp,tmp2;
map<int,bool> ck;
map<int,int> mp;
vector<long long int> v;
set<long long int> z;
vector<vector<long long int> > p(1);
cin>>t;
for(int l=0;l<t;l++)
{
cin>>n>>k;
cin>>a>>b>>c>>r;
v.clear();
mp.clear();
ck.clear();
p[0].clear();
z.clear();

v.push_back(a);
mp[a]=true;
max1=a;
b%=r;
c%=r;
for(int i=1;i<k;i++)
{
tmp=(((v[i-1]*b)%r)+c)%r;
mp[tmp]++;
v.push_back(tmp);
if(tmp>max1)
max1=tmp;
}

/*for(int i=0;i<v.size();i++)
cout<<v[i]<<" ";
cout<<endl<<endl;*/


/*======================*/
cnt=0;
int prev=0;
int value;
while(cnt<k)
{
while(mp[prev]!=0)
prev++;
if(z.size()==0)
{
p[0].push_back(prev);
mp[prev]=1;
ck[prev]=true;
prev++;
}
else
{
value=*(z.begin());
if(value<=prev)
{
p[0].push_back(value);
mp[value]=1;
ck[value]=true;
z.erase(value);
}
else
{
p[0].push_back(prev);
mp[prev]=1;
ck[prev]=true;
prev++;
}
}
mp[v[cnt]]--;
if(mp[v[cnt]]==0)
z.insert(v[cnt]);
cnt++; 
}
/*while(cnt<k)
{
for(int i=0;;i++)
{
if(mp[i]==0)
{
p[0].push_back(i);
mp[i]=1;
ck[i]=true;
break;
}
}
mp[v[cnt]]--;
cnt++; 
}*/

//cout<<"d"<<endl;
//cout<<p[0].size()<<" "<<v.size()<<endl;
/*for(int i=0;i<p[0].size();i++)
cout<<p[0][i]<<" ";
cout<<endl;*/

cnt=0;
while(1)
{
if(!ck[cnt])
{
min1=cnt;
break;
}
cnt++;
}

st=0;
//cout<<min1<<endl;
cnt=2*k;
while(cnt<n)
{
tmp=dec(st,k);
tmp2=p[0][tmp];
p[0][tmp]=min1;
min1=tmp2;
st=tmp;
cnt+=k;
}

//cout<<st<<endl;

for(int i=1;i<n%k;i++)
{
if(st==k-1)
st=0;
else
st++;
}
cout<<"Case #"<<l+1<<": "<<p[0][st]<<endl;
//cout<<"Case #"<<l+1<<": "<<p[0][((st+n%k)%k)-1]<<endl;

}
return 0;
}
