#include<cstdio>
using namespace std;
int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=xx*10+ch-'0';ch=getchar();}
    return xx*ff;
}
const int maxn=100010,maxlongint=(1LL<<31)-1;
int cnt,root;
struct SPLAY{
    int v,sum,ch[2],weight,fa;
    inline void clear()
    {v=sum=weight=0,ch[0]=ch[1]=fa=0;}
    void init(int val)
    {clear();sum=weight=1,v=val;}
}T[maxn];
bool which(const int&x)
{return T[T[x].fa].ch[1]==x;}
inline void push_up(const int&x)
{T[x].sum=T[T[x].ch[0]].sum+T[T[x].ch[1]].sum+T[x].weight;}
void relink(int x,int y,int tt)
{T[x].ch[tt]=y,T[y].fa=x;}
inline void rotate(int x){
    int y=T[x].fa,ffa=T[y].fa,tt=which(x),ttt=which(y);
    relink(ffa,x,ttt);
    relink(y,T[x].ch[tt^1],tt);
    relink(x,y,tt^1);
    push_up(y);
}
void splay(int x,int tar){
    while(T[x].fa!=tar){
        if(T[T[x].fa].fa==tar){
            rotate(x);
            break;
        }
        else if(which(x)==which(T[x].fa)){
            rotate(T[x].fa);
            rotate(x);
        }
        else{
            rotate(x);
            rotate(x);
        }
    }
    push_up(x);
    if(!tar)
        root=x;
}
int get_rank(int x,int val){
    if(val==T[x].v)
        return 1+T[T[x].ch[0]].sum;
    if(val<T[x].v)
        return get_rank(T[x].ch[0],val);
    return get_rank(T[x].ch[1],val)+T[x].weight+T[T[x].ch[0]].sum;
}
int find_rank(int x,int rk){
    if(rk>T[T[x].ch[0]].sum&&rk<=T[T[x].ch[0]].sum+T[x].weight)
        return T[x].v;
    if(rk<=T[T[x].ch[0]].sum)
        return find_rank(T[x].ch[0],rk);
    return find_rank(T[x].ch[1],rk-T[T[x].ch[0]].sum-T[x].weight);
}
int find_element(int x,int val){
    if(val==T[x].v)
        return x;
    if(val<T[x].v)
        return find_element(T[x].ch[0],val);
    return find_element(T[x].ch[1],val);
}
int prev_val(int x,int u,int val){
    if(!x)
        return u;
    if(val>T[x].v)
        return prev_val(T[x].ch[1],x,val);
    return prev_val(T[x].ch[0],u,val);
}
int next_val(int x,int u,int val){
    if(!x)
        return u;
    if(val<T[x].v)
        return next_val(T[x].ch[0],x,val);
    return next_val(T[x].ch[1],u,val);
}
void create(int val){
    int x=prev_val(root,0,val),y=next_val(root,0,val);
    splay(x,0);
    splay(y,x);
    int z=T[y].ch[0];
    if(!z){
        z=++cnt;
        T[z].init(val);
        T[y].ch[0]=z;
        T[z].fa=y;
    }
    else{
        T[z].weight++;
        T[z].sum++;
    }
    push_up(y);
    push_up(x);
}
void del(int val){
    int x=prev_val(root,0,val),y=next_val(root,0,val);
    splay(x,0);
    splay(y,x);
    int z=T[y].ch[0];
    T[z].weight--;
    T[z].sum--;
    if(!T[z].weight){
        T[z].clear();
        T[y].ch[0]=0;
    }
    push_up(y);
    push_up(x);
}
int main(){
    //freopen("in","r",stdin);
    cnt=2;
    root=1;
    T[1].init(maxlongint);
    T[2].init(-maxlongint);
    T[1].ch[0]=2;
    T[2].fa=1;
    push_up(1);
    for(int N=read();N;N--){
        int opt=read(),t=read();
        switch(opt){
            case 1:create(t);break;
            case 2:del(t);break;
            case 3:printf("%d\n",get_rank(root,t)-1);break;
            case 4:printf("%d\n",find_rank(root,t+1));break;
            case 5:printf("%d\n",T[prev_val(root,0,t)].v);break;
            case 6:printf("%d\n",T[next_val(root,0,t)].v);break;
        }
    }
    return 0;
}
