#include<iostream>
#include<vector>
using namespace std;

char a[50][50],glo,black[50][50],white[50][50],board[2][50][50];
bool color[50][50];
int n;

bool is_flip(int x1,int y1,int x2,int y2)
{
return false;
}

void flip(char board[][50],vector<pair<int,int> > &v1,vector<pair<int,int> > &v2,vector<char> &v3)
{
for(int x=0;x<n;x++)
for(int y=0;y<n;y++)
for(int i=n-x-1;i>=0;i--)
for(int j=n-y-1;j>=0;j--)
if(is_flip(x,y,x+i,y+j))
{
v1.push_back(make_pair(x,y));
v2.push_back(make_pair(x+i,y+j));
v3.push_back('F');
for(int q=x;q<=x+i;q++)
for(int w=y;w<=y+j;w++)
color[i][j]=true;
}
}

int cnt_clr(int x1,int y1,int x2,int y2,char c)
{
int cnt=0;
for(int i=x1;i<=x2;i++)
for(int j=y1;j<=y2;j++)
if(a[i][j]==c)
cnt++;
return cnt;
}

void max_black(int &llx,int &lly,int &urx,int &ury)
{
double tmp,tmp2=-1;
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
for(int k=n-i-1;k>=0;k--)
for(int l=n-j-1;l>=0;l--)
{
tmp=cnt_clr(i,j,i+k,j+l,'B');
if((tmp/((l+1)*(k+1)))>tmp2)
{
tmp2=tmp/((l+1)*(k+1));
llx=i;
lly=j;
urx=i+k;
ury=j+l;
}
}
}

int g(int x1,int y1,int x2,int y2,int u)
{
for(int i=x1;i<=x2;i++)
for(int j=y1;j<=y2;j++)
{
if(a[i][j]==board[u][i][j] || color[i][j])
return -1;
}
return 1;
}

int f(int x,int y,int &llx,int &lly,int &urx,int &ury,int u)
{
int tmp1,x1,y1,x2,y2;
for(int i=n-x-1;i>=0;i--)
for(int j=n-y-1;j>=0;j--)
if(g(x,y,x+i,y+j,u)>0)
{
llx=x;
lly=y;
urx=x+i;
ury=y+j;
return (i+1)*(j+1);
}
}

int main()
{
int tx1,tx2,ty1,ty2,tmp1,tmp2,x1,y1,x2,y2,b=0,w=0;
vector<vector<pair<int,int> > > ans1(2),ans2(2);
vector<vector<char> > clr(2);
cin>>n;
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
{
board[1][i][j]='W';
board[0][i][j]='W';
black[i][j]='B';
white[i][j]='W';
cin>>a[i][j];
}
int bx1=0,by1=0,bx2=n-1,by2=n-1;
//max_black(bx1,by1,bx2,by2);
//char p[2];
//p[0]='W';
//p[1]='B';
for(int i=bx1;i<=bx2;i++)
for(int j=by1;j<=by2;j++)
board[0][i][j]='B';
ans1[0].push_back(make_pair(bx1,by1));
ans2[0].push_back(make_pair(bx2,by2));
clr[0].push_back('B');
bool ck;
for(int u=0;u<2;u++)
{
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
color[i][j]=false;
//glo=p[u];
/*if(glo=='W')
flip(black,ans1[u],ans2[u],clr[u]);
else
flip(white,ans1[u],ans2[u],clr[u]);*/
while(1)
{
tmp1=-1;
ck=false;
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
if(a[i][j]==board[u][i][j] || color[i][j])
continue;
ck=true;
tmp2=f(i,j,tx1,ty1,tx2,ty2,u);
if(tmp2>tmp1)
{
tmp1=tmp2;
x1=tx1;
y1=ty1;
x2=tx2;
y2=ty2;
}
}
}
if(!ck)
break;
ans1[u].push_back(make_pair(x1,y1));
ans2[u].push_back(make_pair(x2,y2));
clr[u].push_back(a[x1][y1]);
for(int i=x1;i<=x2;i++)
for(int j=y1;j<=y2;j++)
color[i][j]=true;
}
}
int h;
if(ans1[0].size()>=ans1[1].size())
h=1;
else
h=0;
cout<<ans1[h].size()<<endl;
for(int i=0;i<ans1[h].size();i++)
cout<<ans1[h][i].first<<" "<<ans1[h][i].second<<" "<<ans2[h][i].first<<" "<<ans2[h][i].second<<" "<<clr[h][i]<<endl;
return 0;
}
