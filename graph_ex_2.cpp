#include<cstdio>
using namespace std;
const int maxn=110,INF=(1<<30)-1;
void floyd(int N,int dis[][maxn]){
	for(int k=1;k<=N;k++)
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				if(dis[i][j]>dis[i][k]+dis[k][j])
					dis[i][j]=dis[i][k]+dis[k][j];
}
int main(){
	//freopen("in","r",stdin);
	int N,M,dis[maxn][maxn];
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			dis[i][j]=INF;
	for(int i=1;i<=N;i++)
		dis[i][i]=0;
	while(M--){
		int x,y;
		scanf("%d%d",&x,&y);
		dis[x][y]=dis[y][x]=1;
	}
	floyd(N,dis);
	double ans[maxn];
	for(int i=1;i<=N;i++){
		ans[i]=0;
		for(int j=1;j<=N;j++)
			ans[i]+=dis[i][j];
		ans[i]=(N-1)/ans[i];
	}
	int K;
	scanf("%d",&K);
	while(K--){
		int tmp;
		scanf("%d",&tmp);
		printf("Cc(%d)=%.2lf\n",tmp,ans[tmp]);
	}
	return 0;
}
