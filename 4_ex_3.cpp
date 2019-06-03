#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=xx*10+ch-'0';ch=getchar();}
    return xx*ff;
}
char one(){
	char ch=getchar();
	while(ch==' '||ch=='\n')
		ch=getchar();
	return ch;
}
const int maxn=1010,INF=(1LL<<31)-1;
struct huffman{
	int L,R;
	char id;
}H[maxn*2];
int root,cnt;
int heap[maxn],mark[maxn],siz;
char id[maxn];
void ins(int val,char ch,int mk){
	int i=++siz;
	for(;heap[i/2]>val;i/=2){
		heap[i]=heap[i/2];
		id[i]=id[i/2];
		mark[i]=mark[i/2];
	}
	heap[i]=val;
	id[i]=ch;
	mark[i]=mk;
}
void del(){
	int val=heap[siz],mk=mark[siz],p,c;
	char ch=id[siz];
	siz--;
	for(p=1;p*2<=siz;p=c){
		c=p*2;
		if(c!=siz&&heap[c]>heap[c+1])
			c++;
		if(val<=heap[c])
			break;
		else{
			heap[p]=heap[c];
			id[p]=id[c];
			mark[p]=mark[c];
		}
	}
	heap[p]=val;
	id[p]=ch;
	mark[p]=mk;
}
void build(){
	for(int i=1;i<maxn;i++)
		heap[i]=INF;
	siz=0;cnt=0;
	heap[0]=0;
	int n=read();
	for(int i=1;i<=n;i++){
		char ch=one();
		int tmp=read();
		ins(tmp,ch,++cnt);
		H[cnt].id=ch;
	}
}
void decode(int x,string code){
	if(H[x].id!=0){
		printf("%c ",H[x].id);
		cout<<code<<endl;
		return;
	}
	decode(H[x].L,code+'0');
	decode(H[x].R,code+'1');
}
int main(){
	//freopen("in","r",stdin);
	build();
	while(siz>1){
		char ch1,ch2;
		int val1,val2,mk1,mk2;
		val1=heap[1],ch1=id[1],mk1=mark[1];
		del();
		val2=heap[1],ch2=id[1],mk2=mark[1];
		del();
		ins(val1+val2,0,++cnt);
		H[cnt].id=0,H[cnt].L=mk1,H[cnt].R=mk2;
	}
	root=mark[1];
	decode(root,"");
	return 0;
}
