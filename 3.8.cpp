#include<iostream>
#include<cstdio>
#define fail return printf("fail\n"),0;
#define success return printf("success\n"),0;
using namespace std;
int main(){
	char str[101],stack[101];
	while(scanf("%s",str)!=EOF){
		int len=strlen(str),top=0;
		for(int i=0;i<len;i++){
			if(str[i]=='(')
				stack[++top]='(';
			else if(str[i]=='[')
				stack[++top]='[';
			else if(str[i]=='{')
				stack[++top]='{';
			else if(str[i]=='/'){
				if(i+1<len&&str[i+1]=='*')
					stack[++top]='*',i++;
			}
			else if(str[i]=='*'){
				if(i+1<len&&str[i+1]=='/'){
					if(stack[top]=='*')
						top--,i++;
					else
						fail
				}
			}
			else if(str[i]==')'){
				if(stack[top]=='(')
					top--;
				else
					fail
			}
			else if(str[i]==']'){
				if(stack[top]=='[')
					top--;
				else
					fail
			}
			else if(str[i]=='}'){
				if(stack[top]=='{')
					top--;
				else 
					fail
			}
		}
		if(top)
			fail
	}
	success
}

