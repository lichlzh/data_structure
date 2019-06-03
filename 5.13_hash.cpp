#include<iostream>
#include<cstdio>
using namespace std;
inline bool next_word(char* s){
	int x=0;char ch;
	while((ch=getchar())){
		if(!(ch>='A'&&ch<='Z')&&!(ch>='a'&&ch<='z'))
			break;
		s[x++]=ch;
	}
	if(x==0&&ch==EOF)
		return 0;
	if(x<=3)
		return next_word(s);
	s[x]='\0';
	return 1;
}
inline int trans(char c){
	if(c>='A'&&c<='Z')
		return c-'A';
	return c-'a';
}
inline bool cmp(char *s1,char *s2){
	int x=0;
	for(;s1[x]||s2[x];x++)
		if(s1[x]!=s2[x])
			return 0;
	return 1;
}
const int MOD=20190425;
struct Hash{
	char *str;
	Hash* next;
	int cnt;
	Hash(){
		cnt=0;
		str=NULL;
		next=NULL;
	}
}*H[MOD],*ans;
int calc(char *s){
	int len=strlen(s);
	int mul=1,val=0;
	for(int i=len-1;i>=0;i--){
		val=(val+1LL*(trans(s[i])+1)*mul)%MOD;
		(mul*=2)%=MOD;
	}
	return val;
}
char* get_copy(char *s){
	int len=strlen(s);
	char* str=new char[len+1];
	str[len]='\0';
	for(int i=0;i<len;i++)
		str[i]=s[i];
	return str;
}
void upd_ans(Hash* node){
	if(ans==NULL||node->cnt>ans->cnt){
		while(ans!=NULL){
			Hash* tmp=ans->next;
			delete(ans);
			ans=tmp;
		}
		ans=new Hash();
		ans->str=get_copy(node->str);
		ans->cnt=node->cnt;
	}
	else if(ans!=NULL&&ans->cnt==node->cnt){
		Hash* tmp=new Hash();
		tmp->next=ans;
		tmp->str=get_copy(node->str);
		tmp->cnt=node->cnt;
		ans=tmp;
	}
}
void insert(char *s){
	int val=calc(s);
	if(H[val]==NULL){
		H[val]=new Hash();
		H[val]->str=get_copy(s);
		H[val]->cnt=1;
		upd_ans(H[val]);
		return;
	}
	Hash* node=H[val];
	while(1){
		if(cmp((node->str),s)){
			node->cnt++;
			upd_ans(node);
			return;
		}
		if(node->next==NULL)
			break;
		node=node->next;
	}
	node->next=new Hash();
	node=node->next;
	node->str=get_copy(s);
	node->cnt=1;
	upd_ans(node);
}
void print(Hash* node){
	printf("%d\n",node->cnt);
	while(node!=NULL){
		printf("%s\n",node->str);
		node=node->next;
	}
}
int main(){
	freopen("in","r",stdin);
	char s[110];
	while(next_word(s))
		insert(s);
	print(ans);
	return 0;
}
