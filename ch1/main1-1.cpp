//main1-1.cpp 检验基本操作bo1-1.cpp的主函数
#include"c1.h"/*要将程序中所有#include命令所包含的文件拷贝到当前目录下*/
typedef int ElemType;/*定义抽象数据类型ElemType在本程序中为整形*/
//typedef double ElemType/*定义抽象数据类型ElemType在本程序中为双精度型*/
#include"c1-1.h"/*在此命令之前要定义ElemType的类型*/
#include"bo1-1.cpp" //在此命令之前要包括c1-1.h文件（因为其中定义了Triplet）

void main(){
	Triplet T;
	ElemType m;
	Status i;
	
	i = InitTriplet(T,5,7,9);//初始化三元组T，其三个元素以此为5，7，9
	//i = InitTriplet(T,5,7,9);//当ElemType为双精度型时
	printf("调用初始化函数后，i=%d(1：成功) T的三个值为",i);
	cout<<T[0]<<' '<<T[1]<<' '<<T[2]<<endl;//为避免ElemType类型变化的影响，用count取代printf，注意结尾要加个endl
	
	i = Get(T,2,m); //将三元组T的第2个值赋给m
	if(i==OK)
		cout<<"T的第2个值为"<<m<<endl;

	i = Put(T,2,6); //将三元组T的第2个值改为6
	if(i==OK)
		cout<<"将T的第2个值改为6后，T的3个值为"<<T[0]<<' '<<T[1]<<' '<<T[2]<<endl;

	i = IsAscending(T); //此类函数实参与ElemType的类型无关，当ElemType的类型变化时，实参不需变化。
	printf("调用测试升序的函数后，i=%d(0:否，1：是)\n",i);

	i = IsDescending(T); 
	printf("调用测试降序的函数后，i=%d(0:否，1：是)\n",i);

	if((i=Max(T,m))==OK) //先赋值再比较
		cout<<"T中最大的值为"<<m<<endl;

	if((i=Min(T,m))==OK)
		cout<<"T中最小的值为"<<m<<endl;

	DestroyTriplet(T); //函数也可以不带返回值
	cout<<"销毁T后，T="<<"(NULL)"<<endl;
}