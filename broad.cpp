#include<cstdio>
#include<malloc.h>
using namespace std;
struct node{
	char data;
	int L,R;
	void init(int* d){
		scanf("%d %c %d",&L,&data,&R);
		d[L]++,d[R]++;
	}
};
void get_depth(int x,node* T,int *d){
	if(T[x].L){
		d[T[x].L]=d[x]+1;
		get_depth(T[x].L,T,d);
	}
	if(T[x].R){
		d[T[x].R]=d[x]+1;
		get_depth(T[x].R,T,d);
	}
}
int main(){
	freopen("in","r",stdin);
	int N;
	scanf("%d",&N);
	node *tree=(node*)malloc(sizeof(node)*(N+1));
	int root,*deg=(int*)malloc(sizeof(int)*(N+1)),*depth=(int*)malloc(sizeof(int)*(N+1)),*sum=(int*)malloc(sizeof(int)*(N+1));
	for(int i=0;i<=N;i++)
		deg[i]=depth[i]=sum[i]=0;
	for(int i=1;i<=N;i++)
		tree[i].init(deg);
	for(int i=1;i<=N;i++)
		if(!deg[i]){
			root=i;
			break;
		}
	get_depth(root,tree,depth);
	for(int i=1;i<=N;i++)
		sum[depth[i]]++;
	int mx=sum[0],id=0;
	for(int i=1;i<N;i++)
		if(sum[i]>mx)
			mx=sum[i],id=i;
	printf("depth:%d  number:%d\n",id,mx);
	return 0;
}
