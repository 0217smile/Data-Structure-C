 /* main1-1.c �����������bo1-1.c�������� */
 #include"c1.h" /* Ҫ������������#include�������������ļ���������ǰĿ¼�� */
 /* ����2�пɸ�����Ҫѡ��һ������ֻ��ѡ��һ������������ı��������bo1-1.c */
 typedef int ElemType; /* ���������������ElemType�ڱ�������Ϊ���� */
 /*typedef double ElemType; /* ���������������ElemType�ڱ�������Ϊ˫������ */
 #include"c1-1.h" /* �ڴ�����֮ǰҪ����ElemType������ */
 #include"bo1-1.c" /* �ڴ�����֮ǰҪ����c1-1.h�ļ�����Ϊ���ж�����Triplet�� */
 void main()
 {
   Triplet T;
   ElemType m;
   Status i;
   i=InitTriplet(&T,5,7,9);
 /*i=InitTriplet(&T,5.0,7.1,9.3); /* ��ElemTypeΪ˫������ʱ,��ȡ���Ͼ� */
   printf("���ó�ʼ��������i=%d(1:�ɹ�) T������ֵΪ��%d %d %d\n",i,T[0],T[1],T[2]); /* ��ElemType�����ͱ仯ʱ��Ҫ��Ӧ�ı�printf()�ĸ�ʽ���� */
   i=Get(T,2,&m);
   if(i==OK)
     printf("T�ĵ�2��ֵΪ��%d\n",m);
   i=Put(T,2,6);
   if(i==OK)
     printf("��T�ĵ�2��ֵ��Ϊ6��T������ֵΪ��%d %d %d\n",T[0],T[1],T[2]);
   i=IsAscending(T); /* ���ຯ��ʵ����ElemType�������޹�,��ElemType�����ͱ仯ʱ,ʵ�β���ı� */
   printf("���ò�������ĺ�����i=%d(0:�� 1:��)\n",i);
   i=IsDescending(T);
   printf("���ò��Խ���ĺ�����i=%d(0:�� 1:��)\n",i);
   if((i=Max(T,&m))==OK) /* �ȸ�ֵ�ٱȽ� */
     printf("T�е����ֵΪ��%d\n",m);
   if((i=Min(T,&m))==OK)
     printf("T�е���СֵΪ��%d\n",m);
   DestroyTriplet(&T); /* ����Ҳ���Բ����ط���ֵ */
   printf("����T��T=%u(NULL)\n",T);
 }
