#include<cstdio>
using namespace std;
const int maxn=20,INF=1<<30;
int arr[maxn],cnt_swap;
void swap(int &x,int &y)
{cnt_swap++;int t=x;x=y;y=t;}
void bubble_sort(int *a,int L,int R){
	while(1){
		bool flag=0;
		for(int i=L;i<R;i++)
			if(a[i]>a[i+1]){
				flag=1;
				swap(a[i],a[i+1]);
			}
		if(!flag)
			break;
	}
}
int median3(int *a,int L,int R){
	int mid=(L+R)/2;
	if(a[L]>a[mid])
		swap(a[L],a[mid]);//ºöÂÔ´Ë´¦±È½Ï½»»»´ÎÊý
	if(a[L]>a[R])
		swap(a[L],a[R]);
	if(a[mid]>a[R])
		swap(a[mid],a[R]);
	swap(a[mid],a[R-1]);
	return a[R-1];
}
void quick_sort(int *a,int L,int R){
	static int limit=10;
	if(R-L<=limit)
		return bubble_sort(a,L,R);
	int pivot,low=L,high=R-1;
	pivot=median3(a,L,R);
	while(1){
		while(a[++low]<pivot);
		while(a[--high]>pivot);
		if(low<high)
			swap(a[low],a[high]);
		else
			break;
	}
	swap(a[low],a[R-1]);
	quick_sort(a,L,low-1);
	quick_sort(a,low+1,R);
}
struct heap{
	int data[maxn];
	int siz;
	heap(){
		siz=0,data[0]=-INF;
	}
};
void ins(heap* H,int x){
	int p=++H->siz;
	for(;H->data[p/2]>x;p/=2)
		H->data[p]=H->data[p/2];
	H->data[p]=x;
}
int del(heap *H){
	int ret=H->data[1];
	int x=H->data[H->siz--];
	int parent,child;
	for(parent=1;parent*2<=H->siz;parent=child){
		child=parent*2;
		if(child!=H->siz&&H->data[child]>H->data[child+1])
			child++;
		if(x<=H->data[child])
			break;
		else
			H->data[parent]=H->data[child];
	}
	H->data[parent]=x;
	return ret;
}
bool empty(heap* H){
	return H->siz==0;
}
void pile_sort(int *a,int L,int R){
	heap* H=new heap;
	for(int i=L;i<=R;i++)
		ins(H,a[i]);
	for(int i=L;i<=R;i++)
		a[i]=del(H);
	delete(H);
}
void merge_sort(int *a,int L,int R){
	if(L>=R)
		return;
	int mid=(L+R)/2;
	merge_sort(a,L,mid);
	merge_sort(a,mid+1,R);
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
}
void print(int *a,int L,int R){
	for(int i=L;i<=R;i++)
		printf("%d ",a[i]);
	puts("");
}
int main(){
	int N=13,a[maxn]={0,48,27,96,48,25,6,90,17,84,62,49,72,17};
	int b[maxn],c[maxn];
	for(int i=0;i<=N;i++)
		b[i]=c[i]=a[i];
	pile_sort(a,1,N);
	print(a,1,N);
	
	quick_sort(b,1,N);
	print(b,1,N);
	
	merge_sort(c,1,N);
	print(c,1,N);
	return 0;
}
