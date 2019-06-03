#include<cstdio>
#include<malloc.h>
using namespace std;
const int maxn=110;
struct node{
	node *L,*R,*thread;
	char id;
};
node* build(char* s,int k){
	if(s[k]=='#')
		return NULL;
	node* t=(node*)malloc(sizeof(node));
	t->id=s[k];
	t->L=build(s,k+1);
	t->R=build(s,k+1);
	return t;
}
void get_thread(node* t,node*&pre){
	if(!t)
		return;
	get_thread(t->L,pre);
	if(pre!=NULL)
		pre->thread=t;
	pre=t;
	get_thread(t->R,pre);
}
node* find(node* t,char c){
	if(t==NULL)
		return NULL;
	if(t->id==c)
		return t;
	node* findl=find(t->L,c);
	node* findr=find(t->R,c);
	if(findl!=NULL)
		return findl;
	if(findr!=NULL)
		return findr;
	return NULL;
}
void merge(node* p,node* x){
	x->R=p->L;
	p->L=x;
}
int main(){
	freopen("in","r",stdin);
	int N,M;
	char p,x,*s=(char*)malloc(sizeof(char));
	node *tn,*tm,*tp,*tx,*tmp;
	scanf("%d%d %c %c",&N,&M,&p,&x);
	scanf("%s",s);
	tn=build(s,NULL);
	get_thread(tn,tmp=NULL);
	scanf("%s",s);
	tm=build(s,NULL);
	get_thread(tm,tmp=NULL);
	
	tp=find(tn,p);
	tx=find(tm,x);
	
	merge(tp,tx);
	
	get_thread(tn,tmp=NULL);
	return 0;
}
