//main1-1.cpp �����������bo1-1.cpp��������
#include"c1.h"/*Ҫ������������#include�������������ļ���������ǰĿ¼��*/
typedef int ElemType;/*���������������ElemType�ڱ�������Ϊ����*/
//typedef double ElemType/*���������������ElemType�ڱ�������Ϊ˫������*/
#include"c1-1.h"/*�ڴ�����֮ǰҪ����ElemType������*/
#include"bo1-1.cpp" //�ڴ�����֮ǰҪ����c1-1.h�ļ�����Ϊ���ж�����Triplet��

void main(){
	Triplet T;
	ElemType m;
	Status i;
	
	i = InitTriplet(T,5,7,9);//��ʼ����Ԫ��T��������Ԫ���Դ�Ϊ5��7��9
	//i = InitTriplet(T,5,7,9);//��ElemTypeΪ˫������ʱ
	printf("���ó�ʼ��������i=%d(1���ɹ�) T������ֵΪ",i);
	cout<<T[0]<<' '<<T[1]<<' '<<T[2]<<endl;//Ϊ����ElemType���ͱ仯��Ӱ�죬��countȡ��printf��ע���βҪ�Ӹ�endl
	
	i = Get(T,2,m); //����Ԫ��T�ĵ�2��ֵ����m
	if(i==OK)
		cout<<"T�ĵ�2��ֵΪ"<<m<<endl;

	i = Put(T,2,6); //����Ԫ��T�ĵ�2��ֵ��Ϊ6
	if(i==OK)
		cout<<"��T�ĵ�2��ֵ��Ϊ6��T��3��ֵΪ"<<T[0]<<' '<<T[1]<<' '<<T[2]<<endl;

	i = IsAscending(T); //���ຯ��ʵ����ElemType�������޹أ���ElemType�����ͱ仯ʱ��ʵ�β���仯��
	printf("���ò�������ĺ�����i=%d(0:��1����)\n",i);

	i = IsDescending(T); 
	printf("���ò��Խ���ĺ�����i=%d(0:��1����)\n",i);

	if((i=Max(T,m))==OK) //�ȸ�ֵ�ٱȽ�
		cout<<"T������ֵΪ"<<m<<endl;

	if((i=Min(T,m))==OK)
		cout<<"T����С��ֵΪ"<<m<<endl;

	DestroyTriplet(T); //����Ҳ���Բ�������ֵ
	cout<<"����T��T="<<"(NULL)"<<endl;
}