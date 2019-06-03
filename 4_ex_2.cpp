#include<cstdio>
#include<vector>
using namespace std;
const int maxn=1010;
struct edge{
	int y,next;
}e[maxn];
int lin[maxn],len,root;
inline void insert(int xx,int yy){
	e[++len].next=lin[xx];
	lin[xx]=len;
	e[len].y=yy;
	printf("%d %d\n",xx,yy);
}
struct Tree{
	int L,R;
}T[maxn];
void dfs(int x){
	for(int i=lin[x];i;i=e[i].next){
		T[e[i].y].R=T[x].L;
		T[x].L=e[i].y;
		dfs(e[i].y);
	}
}
void print(int x){
	if(!x)
		return;
	printf("%d L->%d R->%d\n",x,T[x].L,T[x].R);
	print(T[x].L);
	print(T[x].R);
}
int main(){
	//freopen("in","r",stdin);
	vector<int>deg,tdeg;
	vector<int>fa,tfa;
	int tmp,siz;
	scanf("%d%d",&root,&tmp);//½Úµã±àºÅºÍ¸Ã½ÚµãµÄ¶È
	deg.push_back(tmp);
	fa.push_back(root);
	while(siz=deg.size()){
		tdeg.clear();tfa.clear();
		for(int i=0;i<siz;i++){
			for(int j=0;j<deg[i];j++){
				int t1,t2;
				scanf("%d%d",&t1,&t2);
				tfa.push_back(t1);
				tdeg.push_back(t2);
				insert(fa[i],t1);
			}
		}
		deg=tdeg;fa=tfa;
	}
	dfs(root);
	print(root);
	return 0;
}

