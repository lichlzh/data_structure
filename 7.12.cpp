#include<cstdio>
#include<vector>
using namespace std;
const int maxn=20,INF=1<<30,maxdigit=3;
void LSDradix_sort(int *a,int L,int R){
	vector<int>bucket[10];
	int mul=10;
	for(int i=1;i<=maxdigit;i++){
		for(int j=L;j<=R;j++){
			int key=a[j]/mul%10;
			bucket[key].push_back(a[j]);
		}
		int now=L;
		for(int j=0;j<=9;j++){
			int siz=bucket[j].size();
			for(int k=0;k<siz;k++)
				a[now++]=bucket[j][k];
			bucket[j].clear();
		}
		mul*=10;
	}
}
vector<int> MSDradix_sort(vector<int>&a,int mul){
	if(!mul)
		return a;
	vector<int>v[10],now,tmp;
	int siz=a.size();
	for(int i=0;i<siz;i++){
		int key=a[i]/mul%10;
		v[key].push_back(a[i]);
	}
	for(int i=0;i<=9;i++){
		siz=v[i].size();
		if(siz<=1)
			for(int j=0;j<siz;j++)
				now.push_back(v[i][j]);
		else{
			tmp=MSDradix_sort(v[i],mul/10);
			for(int j=0;j<siz;j++)
				now.push_back(tmp[j]);
		}
	}
	return now;
}
void MSDradix_sort(int *a,int L,int R){
	vector<int> tmp;
	int mul=1,mx=0;
	for(int i=L;i<=R;i++){
		tmp.push_back(a[i]);
		if(a[i]>mx)
			mx=a[i];
	}
	while(mul<=mx)
		mul*=10;
	tmp=MSDradix_sort(tmp,mul/10);
	for(int i=L;i<=R;i++)
		a[i]=tmp[i-L];
}
void print(int *a,int L,int R){
	for(int i=L;i<=R;i++)
		printf("%d ",a[i]);
	puts("");
}
int main(){
	int N=13,a[maxn]={0,48,27,96,48,25,6,90,17,84,62,49,72,17};
	MSDradix_sort(a,1,N);
	print(a,1,N);
	return 0;
}
