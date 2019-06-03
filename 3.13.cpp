#include<iostream>
#include<cstdio>
using namespace std;
struct node{
	int elem;
	node*next,*prev;
};
struct deque{
	node*head,*tail;
};
void push_back(deque*q,int x){//inject
	node* tmp=(node*)malloc(sizeof(node));
	tmp->next=NULL,tmp->prev=q->tail,tmp->elem=x;
	if(q->tail!=NULL)
		q->tail->next=tmp;
	q->tail=tmp;
	if(q->head==NULL)
		q->head=tmp;
}
void push_front(deque*q,int x){//push
	node* tmp=(node*)malloc(sizeof(node));
	tmp->next=q->head,tmp->prev=NULL,tmp->elem=x;
	if(q->head!=NULL)
		q->head->prev=tmp;
	q->head=tmp;
	if(q->tail==NULL)
		q->tail=tmp;
}
void pop_back(deque*q){//eject
	node* tmp=q->tail->prev;
	free(q->tail);
	q->tail=tmp;
	if(q->tail==NULL)
		q->head=NULL;
	else
		q->tail->next=NULL;
}
void pop_front(deque*q){//push
	node* tmp=q->head->next;
	free(q->head);
	q->head=tmp;
	if(q->head==NULL)
		q->tail=NULL;
	else
		q->head->prev=NULL;
}
void print(deque*q){
	node* tmp=q->head;
	if(tmp!=NULL)
		while(1){
			printf("%d ",tmp->elem);
			if(tmp==q->tail)
				break;
			tmp=tmp->next;
		}
	printf("\n");
}
int main(){
	freopen("in","r",stdin);
	/*
	调用函数进行测试
	*/
	deque* q=(deque*)malloc(sizeof(deque));
	q->head=q->tail=NULL;
	for(int i=1;i<=10;i++){
		if(i%2==0){
			printf("push_back %d\n",i);
			push_back(q,i);
		}
		else {
			printf("push_front %d\n",i);
			push_front(q,i);
		}
		print(q);
	}
	for(int i=1;i<=10;i++){
		if(i%2==0){
			printf("pop_back\n",i);
			pop_back(q);
		}
		else {
			printf("pop_front\n",i);
			pop_front(q);
		}
		print(q);
	}
	return 0;
}
