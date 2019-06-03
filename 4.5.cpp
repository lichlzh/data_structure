#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
#include<utility>
#include<stdio.h>
#include<cstdlib>
#include<iomanip>	//cout<<setiosflags(ios::fixed)<<setprecision(2);
#include<ctime> //double a=(double)clock();	cout<<a<<endl;
#include<vector>
#include<queue>
using namespace std;
int read(){
    long long x=0;int ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return ff*x;
}
const int maxn=500010;
inline void myswap(int&xx,int&yy)
{xx^=yy,yy^=xx,xx^=yy;}
int N,M,S,t1,t2;
int lin[maxn],len,depth[maxn];
struct edge{
    int y,next;
    bool use;
}e[maxn*2];
inline void insert(int xx,int yy){
    e[++len].next=lin[xx];
    lin[xx]=len;
    e[len].y=yy;
}
int q[maxn],head,tail;
bool vis[maxn];
int f[maxn][20];
void bfs(int x){
    head=tail=0;
    q[head]=x;vis[x]=1;
    f[x][0]=x;depth[x]=0;
    for(;head<=tail;head++)
        for(int i=lin[q[head]];i;i=e[i].next)
            if(!vis[e[i].y]){
                vis[e[i].y]=1;
                e[i].use=1;
                q[++tail]=e[i].y;
                f[e[i].y][0]=q[head];
                depth[e[i].y]=depth[q[head]]+1;
            }
}
int query(int x,int y){
    if(depth[x]<depth[y])
        myswap(x,y);
    int temp=depth[x]-depth[y];
    if(temp)
        for(int i=19;i>=0;i--)
            if(temp&(1<<i))
                x=f[x][i];
    if(x==y)
        return x;
    for(int i=19;i>=0;i--)
        if(f[x][i]!=f[y][i])
            x=f[x][i],y=f[y][i];
    return f[x][0];
}
int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    N=read(),M=read(),S=read();//N个点 M条边 S个询问
    for(int i=1;i<=N-1;i++){
        t1=read(),t2=read();
        insert(t1,t2),insert(t2,t1);
    }
    bfs(S);
    for(int j=1;j<=19;j++)
        for(int i=1;i<=N;i++)
            f[i][j]=f[f[i][j-1]][j-1];
    while(M--){
        t1=read(),t2=read();
        printf("%d\n",query(t1,t2));
    }
    return 0;
}
