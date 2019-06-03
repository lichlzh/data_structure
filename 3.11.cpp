//中缀表达式转后缀表达式，只支持加减乘除括号
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int level(char c){//运算符优先级
	if(c=='+'||c=='-')
		return 1;
	if(c=='*'||c=='/')
		return 2;
	return 0;
}
int main(){
	char str[101],stack[101];
	scanf("%s",str);
	int len=strlen(str),top=0;
	for(int i=0;i<len;i++){
		if(str[i]=='(')
			stack[++top]='(';
		else if(str[i]==')'){
			while(stack[top]!='(')
				printf("%c ",stack[top--]);
			top--;
		}
		else if(str[i]>='0'&&str[i]<='9'){
			while((str[i]>='0'&&str[i]<='9')||str[i]=='.'){
				printf("%c",str[i]);
				i++;
			}
			printf(" ");
			i--;
		}
		else if(level(str[i])!=0){//过滤无关字符
			while(top&&level(stack[top])>=level(str[i]))
				printf("%c ",stack[top--]);
			stack[++top]=str[i];
		}
	}
	while(top)
		printf("%c ",stack[top--]);
	return 0;
}
