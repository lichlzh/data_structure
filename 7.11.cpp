#include<cstdio>
#include<vector>
using namespace std;
int main(){
	//freopen("in","r",stdin);
	int n;
	scanf("%d",&n);
	int* a=new int[n];
	vector<int> bucket[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		bucket[a[i]%n].push_back(a[i]);
	int t=0;
	for(int i=0;i<n;i++){
		int siz=bucket[i].size();
		for(int j=0;j<siz;j++)
			a[t++]=bucket[i][j];
		bucket[i].clear();
	}
	for(int i=0;i<n;i++)
		bucket[a[i]/n].push_back(a[i]);
	t=0;
	for(int i=0;i<n;i++){
		int siz=bucket[i].size();
		for(int j=0;j<siz;j++)
			a[t++]=bucket[i][j];
	}
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
