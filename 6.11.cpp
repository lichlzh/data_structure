#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<map>
#include<vector>
using namespace std;
int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=xx*10+ch-'0';ch=getchar();}
    return xx*ff;
}
long long READ(){
    long long xx=0,ff=1;char ch=getchar();
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
int N,M;
int dis[5][5];
int path[5][5];
void printD(int n){
	puts("D");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%d ",dis[i][j]);
		puts("");
	}
	puts("");
}
void printP(int n){
	puts("P");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%d ",path[i][j]);
		puts("");
	}
	puts("");
}
int main(){
	freopen("in","r",stdin);
	N=read(),M=read();
	memset(dis,10,sizeof(dis));
	for(int i=1;i<=M;i++){
		int t1=read(),t2=read(),t=read();
		dis[t1][t2]=t;
		path[t1][t2]=t1;
	}
	for(int k=1;k<=N;k++){
		printD(N);
		printP(N);
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				if(dis[i][j]>dis[i][k]+dis[k][j])
					dis[i][j]=dis[i][k]+dis[k][j],path[i][j]=path[k][j];
	}
	printD(N);
	printP(N);
	return 0;
}
