//algo1-4.cpp ˵��exit()�������õĳ���
#include"c1.h"
int a(int i){
	if(i==1){
		printf("�˳����������\n");
		exit(1);
	}
	return i;
}

void main(){
	int i;
	printf("������i��ֵ��");
	scanf("%d",&i);
	printf("a(i)=%d\n",a(i));
}