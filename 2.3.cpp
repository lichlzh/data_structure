#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n,a,sum=0;
	scanf("%d%d",&n,&a);
	for(int i=1;i<=n;i++){
		sum+=(n-i+1)*a;
		a*=10;
	}
	printf("%d\n",sum);
	return 0;
}