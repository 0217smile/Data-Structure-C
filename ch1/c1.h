/*c1.h后续程序多会用的头文件调用整合*/
#include<stdio.h>
#include<ctype.h>
#include<malloc.h> // malloc()等
#include<limits.h> //INT_MAX等
#include<stdio.h> //EOF,NULL
#include<io.h> //eof()
#include<math.h> //float(),ceil(),abs()
#include<process.h> //exit()
#include<iostream.h> //cout,cin
// 函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1

typedef int Status; //Status是函数的类型，其值是函数结果状态代码，如OK 等
typedef int Boolean; //Boolean是布尔类型，其值是TRUE或FALSE