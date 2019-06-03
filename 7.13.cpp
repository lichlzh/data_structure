#include<cstdio>
using namespace std;
void count_sort(int n,int *a){
	if(!n)
		return;
	int mx=-1000000000,mn=1000000000;
	for(int i=0;i<n;i++){
		if(a[i]>mx)
			mx=a[i];
		if(a[i]<mn)
			mn=a[i];
	}
	for(int i=0;i<n;i++)
		a[i]-=mn;
	int* cnt=new int[mx-mn+1];
	for(int i=0;i<mx-mn+1;i++)
		cnt[i]=0;
	for(int i=0;i<n;i++)
		cnt[a[i]]++;
	int sum=0;
	for(int i=0;i<mx-mn+1;i++){
		for(int j=sum;j<sum+cnt[i];j++)
			a[j]=i;
		sum+=cnt[i];
	}
	for(int i=0;i<n;i++)
		a[i]+=mn;
}
int main(){
	freopen("in","r",stdin);
	int n,*a;
	scanf("%d",&n);
	a=new int[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	count_sort(n,a);
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	delete a;
	return 0;
}
/*
计数排序
时间复杂度：稳定O(n+k)	n是个数，k是极差
基数排序
时间复杂度：O(d(n+r))，n是个数，d是关键码个数，r是关键码取值范围。其中，一趟分配时间复杂度为O(n)，一趟收集时间复杂度为O(radix)，共进行d趟分配和收集。
*/
