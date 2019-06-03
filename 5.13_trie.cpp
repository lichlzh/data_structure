#include<cstdio>
#include<cstring>
#include<iostream>
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
struct Trie{
	Trie* ch[26],*fa;
	int cnt,val;
	Trie(){
		cnt=val=0;fa=NULL;
		for(int i=0;i<26;i++)
			ch[i]=NULL;
	}
};
void insert(int x,char *s,Trie* node){
	if(!s[x]){
		node->cnt++;
		return;
	}
	if(node->ch[trans(s[x])]==NULL){
		node->ch[trans(s[x])]=new Trie();
		node->ch[trans(s[x])]->fa=node;
		node->ch[trans(s[x])]->val=trans(s[x]);
	}
	insert(x+1,s,node->ch[trans(s[x])]);
}
int get_max(Trie* node){
	int ret=node->cnt;
	for(int i=0;i<26;i++)
		if(node->ch[i]!=NULL)
			ret=max(ret,get_max(node->ch[i]));
	return ret;
}
void print_word(Trie* node){
	if(node->fa!=NULL){
		print_word(node->fa);
		printf("%c",node->val+'a');
	}
}
void print(Trie* node,int mx){
	if(node->cnt==mx){
		print_word(node);
		printf("\n");
	}
	for(int i=0;i<26;i++)
		if(node->ch[i]!=NULL)
			print(node->ch[i],mx);
}
int main(){
	freopen("in","r",stdin);
	char s[110];
	Trie* root=new Trie();
	while(next_word(s))
		insert(0,s,root);
	int mx=get_max(root);
	printf("%d\n",mx);
	print(root,mx);
	return 0;
}
