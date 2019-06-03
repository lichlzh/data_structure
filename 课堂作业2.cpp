#include<cstdio>
#include<cstdlib>
struct node{
	int v;
	node* next;
};
void init(node* A){
	node* tmp,*now=A;
	int n;
	scanf("%d",&n);
	while(n--){
		tmp=(node*)malloc(sizeof(node));
		tmp->next=NULL;
		now->next=tmp;
		scanf("%d",&tmp->v);
		now=tmp;
	}
}
void del(node* A,int L,int R){
	node* tmp;
	while(A->next!=NULL){
		if(A->next->v>L&&A->next->v<R){
			tmp=A->next;
			A->next=tmp->next;
			free(tmp);
		}
		else
			A=A->next;
	}
}
void print(node* A){
	A=A->next;
	while(A!=NULL){
		printf("%d ",A->v);
		A=A->next;
	}
	printf("\n");
}
int main(){
	freopen("in","r",stdin);
	node* head=(node*)malloc(sizeof(node));
	init(head);
	print(head);
	int mx,mn;
	scanf("%d%d",&mn,&mx);
	del(head,mn,mx);
	print(head);
	return 0;
}
