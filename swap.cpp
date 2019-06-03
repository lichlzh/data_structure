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
void predfs(int x,node* T){
	if(!x)
		return;
	printf("%c",T[x].data);
	predfs(T[x].L,T);
	predfs(T[x].R,T);
}
void middfs(int x,node* T){
	if(!x)
		return;
	middfs(T[x].L,T);
	printf("%c",T[x].data);
	middfs(T[x].R,T);
}
void postdfs(int x,node* T){
	if(!x)
		return;
	postdfs(T[x].L,T);
	postdfs(T[x].R,T);
	printf("%c",T[x].data);
}
void tree_swap(int x,node* T){
	if(!x)
		return;
	tree_swap(T[x].L,T);
	tree_swap(T[x].R,T);
	int temp=T[x].L;
	T[x].L=T[x].R;
	T[x].R=temp;
}
int main(){
	freopen("in","r",stdin);
	int N;
	scanf("%d",&N);
	node *tree=(node*)malloc(sizeof(node)*(N+1));
	int root,*deg=(int*)malloc(sizeof(int)*(N+1));
	for(int i=0;i<=N;i++)
		deg[i]=0;
	for(int i=1;i<=N;i++)
		tree[i].init(deg);
	for(int i=1;i<=N;i++)
		if(!deg[i]){
			root=i;
			break;
		}
	printf("before swap\n");
	predfs(root,tree);
	printf("\n");
	middfs(root,tree);
	printf("\n");
	postdfs(root,tree);
	printf("\n");
	
	tree_swap(root,tree);
	
	printf("after swap\n");
	predfs(root,tree);
	printf("\n");
	middfs(root,tree);
	printf("\n");
	postdfs(root,tree);
	printf("\n");
	return 0;
}
