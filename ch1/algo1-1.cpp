// algo1-1.cpp 计算1-1/x+1/x*x...
#include<stdio.h>
#include<sys/timeb.h>

void main(){
	timeb t1,t2;
	long t;
	double x,sum=1,temp;
	int i,j,n;
	printf("请输入x，n：");
	scanf("%lf%d",&x,&n);
	ftime(&t1); //求得当前时间,计算前时间
	for(i=1;i<=n;i++){
		temp = 1;
		for(j=1;j<=i;j++){
			temp*=(-1.0)/x;
		}
		sum += temp;
	}
	ftime(&t2); // 求得当前时间，即计算后时间
	t = (t2.time-t1.time)*1000 + (t2.millitm - t1.millitm); //耗时
	printf("sum = %lf 用时%ld毫秒\n",sum,t);
}