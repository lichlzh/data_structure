#include<iostream>
#include<cstdio>
using namespace std;
int f(int x,int n){
	if(n==1)
		return x;
	return -1*x*(f(x,n-1)-1);
}
int main(){
	int x,n;
	scanf("%d%d",&x,&n);
	printf("%d\n",f(x,n));
	return 0;
}