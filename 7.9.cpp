#include<cstdio>
using namespace std;
const int maxn=20,INF=1<<30;
int arr[maxn];
struct stack{
	int *a,L,R,status;
	stack(int* q=NULL,int w=0,int e=0,int r=0)
	{a=q,L=w,R=e,status=r;}
}s[110];
int top=0;
void merge_sort(int *a,int L,int R){
	int status,mid;
	s[top=1]=stack(a,L,R,0);
	while(top){
		a=s[top].a,L=s[top].L,R=s[top].R,status=s[top].status;
		if(L>=R){
			top--;
			continue;
		}
		mid=(L+R)/2;
		if(status==0){
			s[top].status=1;
			s[++top]=stack(a,L,mid,0);
			continue;
		}
		else if(status==1){
			s[top].status=2;
			s[++top]=stack(a,mid+1,R,0);
			continue;
		}
		else{
			int i=L,j=mid+1,k=L;
			while(i<=mid&&j<=R)
				if(a[i]<=a[j])
					arr[k++]=a[i++];
				else
					arr[k++]=a[j++];
			while(i<=mid)
				arr[k++]=a[i++];
			while(j<=R)
				arr[k++]=a[j++];
			for(i=L;i<=R;i++)
				a[i]=arr[i];
			top--;
		}
	}
}
void print(int *a,int L,int R){
	for(int i=L;i<=R;i++)
		printf("%d ",a[i]);
	puts("");
}
int main(){
	int N=13,a[maxn]={0,48,27,96,48,25,6,90,17,84,62,49,72,17};
	merge_sort(a,1,N);
	print(a,1,N);
	return 0;
}
