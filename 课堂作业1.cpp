#include<cstdio>
#include<cstdlib>
#include<algorithm>
struct matrix{
	int x,y;
	double v;
	bool friend operator<(const matrix&A,const matrix&B)
	{return A.x<B.x||(A.x==B.x&&A.y<B.y);}
};
matrix* transpose(matrix*A,int n){
	matrix*B=(matrix*)malloc(n*sizeof(matrix));
	for(int i=0;i<n;i++){
		scanf("%d%d%lf",&(A+i)->x,&(A+i)->y,&(A+i)->v);
		(B+i)->x=(A+i)->y,(B+i)->y=(A+i)->x,(B+i)->v=(A+i)->v;
	}
	std::sort(B,B+n);
	return B;
}
int main(){
	freopen("in","r",stdin);
	int n;
	scanf("%d",&n);
	matrix*A=(matrix*)malloc(n*sizeof(matrix));
	for(int i=0;i<n;i++)
		scanf("%d%d%lf",&(A+i)->x,&(A+i)->y,&(A+i)->v);
	matrix*B=transpose(A,n);
	for(int i=0;i<n;i++)
		printf("%d %d %lf\n",(B+i)->x,(B+i)->y,(B+i)->v);
	return 0;
}
