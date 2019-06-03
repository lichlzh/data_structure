#include<iostream>
#include<cstdio>
using namespace std;
struct node{
	double coe,ind;//coeffcient and index
	node* next;
};
node* init(){
	/*
	����һ������ʽ�������ʽ��
	nΪ����ʽ����������n�����ֱַ��ʾÿһ���ϵ��coeffcient��ָ��index����Ҫ����ָ������˳�����
	*/
	node* head=(node*)malloc(sizeof(node)),*now=head,*tmp;
	head->next=NULL;
	int n;
	scanf("%d",&n);
	while(n--){
		tmp=(node*)malloc(sizeof(node));
		tmp->next=NULL;
		now->next=tmp;
		scanf("%lf%lf",&tmp->coe,&tmp->ind);
		now=tmp;
	}
	return head;
}
void filter(node*A){
	//���˵�ϵ��Ϊ0����
	while(A!=NULL&&A->next!=NULL){
		if(A->coe==0){
			node* tmp=A->next->next;
			free(A->next);
			A->next=tmp;
		}
		A=A->next;
	}
}
node* add(node*A,node*B){
	/*
	����ʽ�ӷ�
	������д�ģ��뱾���ϵ����
	*/
	node* head=(node*)malloc(sizeof(node)),*now=head,*tmp;
	head->next=NULL;
	A=A->next,B=B->next;
	while(A!=NULL&&B!=NULL){
		if(A->ind<=B->ind){
			if(now==head||A->ind!=now->ind){
				tmp=(node*)malloc(sizeof(node));
				tmp->next=NULL;
				now->next=tmp;
				tmp->coe=A->coe,tmp->ind=A->ind;
				now=tmp;
			}
			else
				now->coe+=A->coe;
			A=A->next;
		}
		else{
			if(now==head||B->ind!=now->ind){
				tmp=(node*)malloc(sizeof(node));
				tmp->next=NULL;
				now->next=tmp;
				tmp->coe=B->coe,tmp->ind=B->ind;
				now=tmp;
			}
			else
				now->coe+=B->coe;
			B=B->next;
		}
	}
	while(A!=NULL){
		if(now==head||A->ind!=now->ind){
			tmp=(node*)malloc(sizeof(node));
			tmp->next=NULL;
			now->next=tmp;
			tmp->coe=A->coe,tmp->ind=A->ind;
			now=tmp;
		}
		else
			now->coe+=A->coe;
		A=A->next;
	}
	while(B!=NULL){
		if(now==head||B->ind!=now->ind){
			tmp=(node*)malloc(sizeof(node));
			tmp->next=NULL;
			now->next=tmp;
			tmp->coe=B->coe,tmp->ind=B->ind;
			now=tmp;
		}
		else
			now->coe+=B->coe;
		B=B->next;
	}
	filter(head);
	return head;
}
node*mul(node*A,node*B){
	//����ʽ�˷�������ֵΪ�������ͷ
	node* head=(node*)malloc(sizeof(node)),*now,*tmp,*tmpA,*tmpB;
	head->next=NULL;
	tmpA=A->next;
	while(tmpA!=NULL){
		now=head,tmpB=B->next;
		while(tmpB!=NULL){
			double coe=tmpA->coe*tmpB->coe,ind=tmpA->ind+tmpB->ind;
			while(now->next!=NULL&&now->next->ind<=ind)
				now=now->next;
			if(now->ind==ind)
				now->coe+=coe;
			else{
				tmp=(node*)malloc(sizeof(node));
				tmp->next=NULL,tmp->coe=coe,tmp->ind=ind;
				tmp->next=now->next;
				now->next=tmp;
			}
			tmpB=tmpB->next;
		}
		tmpA=tmpA->next;
	}
	filter(head);
	return head;
}
void print(node*A){
	A=A->next;
	while(A!=NULL){
		printf("%lf %lf\n",A->coe,A->ind);
		A=A->next;
	}
}
int main(){
	freopen("in","r",stdin);
	node*A=init();
	node*B=init();
	node*C=mul(A,B);
	print(C);
	return 0;
}
//����ÿһ���ϵ����ָ������������ʽ���ȷֱ�Ϊn��m���ӷ�ʱ�临�Ӷ�O(n+m),�˷�O(n^2*m)
