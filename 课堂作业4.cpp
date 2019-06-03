#include<cstdio>
#include<cstdlib>
struct node{
	int v;
	node* next;
};
void init(node*&A){
	node* tmp;
	int n;
	scanf("%d",&n);
	A=(node*)malloc(sizeof(node));
	scanf("%d",&A->v);
	A->next=A;
	while(--n){
		tmp=(node*)malloc(sizeof(node));
		tmp->next=A->next;
		scanf("%d",&tmp->v);
		A->next=tmp;
		A=tmp;
	}
}
void push_back(node*&A,int v){
	if(A==NULL){
		A=(node*)malloc(sizeof(node));
		A->v=v;
		A->next=A;
		return;
	}
	node* tmp=(node*)malloc(sizeof(node));
	tmp->next=A->next;
	tmp->v=v;
	A->next=tmp;
	A=tmp;
}
void pop_front(node*&A){
	if(A==NULL){
		printf("ERROR\n");
		return;
	}
	if(A->next==A){
		free(A);
		A=NULL;
		return;
	}
	node* tmp=A->next;
	A->next=tmp->next;
	free(tmp);
}
void print(node*A){
	if(A!=NULL){
		A=A->next;
		node* end=A;
		do{
			printf("%d ",A->v);
			A=A->next;
		}while(A!=end);
	}
	printf("\n");
}
int main(){
	freopen("in","r",stdin);
	node* rear;
	init(rear);
	print(rear);
	for(int i=1;i<=10;i++){
		if(i&1){
			printf("push_back %d\n",i);
			push_back(rear,i);
			print(rear);
		}
		else{
			printf("pop_front\n");
			pop_front(rear);
			print(rear);
		}
	}
	return 0;
}
