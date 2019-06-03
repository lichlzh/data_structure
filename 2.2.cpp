#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int n,m;
    int a[100],b[100];
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	for(int i=0;i<n;i++)
		b[(i-m+n)%n]=a[i];
	for(int i=0;i<n;i++)
		a[i]=b[i];
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
    return 0;
}
