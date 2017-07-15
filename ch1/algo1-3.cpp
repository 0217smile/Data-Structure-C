//algo1-3.cpp 变量的引用类型与非引用类型的区别
#include<stdio.h>

void fa(int a){ //非引用类型，在函数中改变a的值，将不会影响主函数中的a值
	a++;
	printf("在函数fa中，a=%d\n",a);
}
void fb(int &a){
	a++;
	printf("在函数fb中，a=%d\n",a);
}

void main(){
	int n = 1;
	printf("在主程序中，调用函数fa之前：n=%d\n",n);
	fa(n);
	printf("在主程序中，调用函数fa之后，调用函数fb之前：n=%d\n",n);
	fb(n);
	printf("在主程序中，调用函数fb之后：n=%d\n",n);
}