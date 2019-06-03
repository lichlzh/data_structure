#include<cstdio>
using namespace std;
const int maxn=105;
int lin[maxn],len,deg[maxn];
struct edge{
	int y,next;
}e[maxn*maxn/2];
inline void insert(int xx,int yy){
	e[++len].next=lin[xx];
	lin[xx]=len;
	e[len].y=yy;
	deg[yy]++;
}
bool bfs(int N){
	int q[maxn],head,tail;
	head=1,tail=0;
	for(int i=1;i<=N;i++)
		if(!deg[i])
			q[++tail]=i;
	for(;head<=tail;head++){
		for(int i=lin[q[head]];i;i=e[i].next)
			if(!--deg[e[i].y])
				q[++tail]=e[i].y;
	}
	for(int i=1;i<=N;i++)
		if(deg[i])
			return 0;
	return 1;
}
int main(){
	//freopen("in","r",stdin);
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		int K;
		scanf("%d",&K);
		while(K--){
			int tmp;
			scanf("%d",&tmp);
			insert(i,tmp);
		}
	}
	printf("%d\n",bfs(N));
	return 0;
}
