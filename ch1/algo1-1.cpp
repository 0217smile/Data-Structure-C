// algo1-1.cpp ����1-1/x+1/x*x...
#include<stdio.h>
#include<sys/timeb.h>

void main(){
	timeb t1,t2;
	long t;
	double x,sum=1,temp;
	int i,j,n;
	printf("������x��n��");
	scanf("%lf%d",&x,&n);
	ftime(&t1); //��õ�ǰʱ��,����ǰʱ��
	for(i=1;i<=n;i++){
		temp = 1;
		for(j=1;j<=i;j++){
			temp*=(-1.0)/x;
		}
		sum += temp;
	}
	ftime(&t2); // ��õ�ǰʱ�䣬�������ʱ��
	t = (t2.time-t1.time)*1000 + (t2.millitm - t1.millitm); //��ʱ
	printf("sum = %lf ��ʱ%ld����\n",sum,t);
}