#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n,a[100],ans=1,pre=0,mark;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
		if(a[i]>a[i-1]){
			if(i-pre+1>ans)
				ans=i-pre+1,mark=pre;//标记最长序列的起始位置
		}
		else
			pre=i;
	printf("%d\n",ans);
	for(int i=mark;i<=mark+ans-1;i++)
		printf("%d ",a[i]);
	return 0;
}