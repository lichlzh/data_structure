#include<cstdio>
#include<cstdlib>
void dfs(){
	char ch;
	scanf("%c",&ch);
	if(ch!='\n'){
		dfs();
		printf("%c",ch);
	}
}
int main(){
	dfs();
	return 0;
}
