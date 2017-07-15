// algo1-2.cpp 计算1-1/x+1/x*x...另一种快捷方式
#include<stdio.h>
#include<sys/timeb.h>

void main(){
	timeb t1,t2;
	long t;
	double x,sum=1,suml=1;
	int i,n;
	printf("请输入x n:");
	scanf("%lf%d",&x,&n);
	ftime(&t1);
	for(i=1;i<=n;i++){
		suml*=-1.0/x;
		sum += suml;
	}
	ftime(&t2);
	t = (t2.time - t1.time) + (t2.millitm - t1.millitm);
	printf("sum = %lf 用时%ld毫秒\n",sum,t);

}