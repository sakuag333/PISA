#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

map<vector<int>,bool> mp,ck;

class node
{
public:
bool is_end;
node *a[26];
node()
{
is_end=false;
for(int i=0;i<26;i++)
a[i]=0;
}
};

class trie
{
public:
node *root;
trie()
{
root=new node();
}
void create(string word,node *curr,int k)
{
if(word.length()==k)
{curr->is_end=true;return;}
if(curr->a[word[k]-'A']==0)
{
node *temp=new node();
curr->a[word[k]-'A']=temp;
}
create(word,curr->a[word[k]-'A'],k+1);
}
void search(vector<int> &cnt,node *k,vector<vector<int> > &v)
{
if(k->is_end)
v.push_back(cnt);
for(int i=0;i<26;i++)
{
if(k->a[i]!=0 && cnt[i]>0)
{
cnt[i]--;
search(cnt,k->a[i],v);
cnt[i]++;
}
}
}
void print(node *k,string y)
{
if(k->is_end)
cout<<y<<endl;
for(int i=0;i<26;i++)
{
if(k->a[i]!=0)
{
char x='A'+i;
print(k->a[i],y+x);
}
}
}
};

bool game(trie &t,vector<int> &cnt)
{
if(ck[cnt])
return !mp[cnt];
ck[cnt]=true;
vector<vector<int> > k;
t.search(cnt,t.root,k);
bool ck=false;
for(int i=0;i<k.size();i++)
{
ck=game(t,k[i]);
if(ck)
break;
}
mp[cnt]=ck;
return !ck;
}

int main()
{
string word;
int d,r,c,board;
char x;
trie t;
scanf("%d",&d);
getchar_unlocked();
for(int i=0;i<d;i++)
{
word="";
while((x=getchar_unlocked())!='\n')
word+=x;
if(word.length()<=16)
{
sort(word.begin(),word.end());
t.create(word,t.root,0);
}
}
scanf("%d%d",&r,&c);
scanf("%d",&board);
getchar_unlocked();
char tmp;
vector<int> bcnt(26);
for(int l=0;l<board;l++)
{
for(int i=0;i<26;i++)
bcnt[i]=0;
for(int i=0;i<r;i++)
{
for(int j=0;j<=c;j++)
{
tmp=getchar_unlocked();
if(j<c)
bcnt[tmp-'A']++;
}
}
if(!game(t,bcnt))
printf("Alice\n");
else
printf("Bob\n");
}
return 0;
}
