 /* algo9-5.c ����bo9-3.c�ĳ��� */
 #include"c1.h"
 #define N 5 /* ����Ԫ�ظ��� */
 typedef char KeyType; /* ��ؼ�����Ϊ�ַ��� */
 typedef struct
 {
   KeyType key;
   int order;
 }ElemType; /* ����Ԫ������ */

 #include"c9.h"
 #include"c9-2.h"
 #include"bo9-3.c"

 void print(ElemType c)
 {
   printf("(%d,%d)",c.key,c.order);
 }

 void main()
 {
   BSTree dt,p;
   Status k;
   int i;
   KeyType j;
   ElemType r[N]={{13,1},{24,2},{37,3},{90,4},{53,5}}; /* (�Խ̿���ͼ9.12Ϊ��) */
   InitDSTable(&dt); /* ��ʼ������ */
   for(i=0;i<N;i++)
     InsertAVL(&dt,r[i],&k); /* ��ƽ������� */
   TraverseDSTable(dt,print); /* ���ؼ���˳����������� */
   printf("\n����������ҵĹؼ���: ");
   scanf("%d",&j);
   p=SearchBST(dt,j); /* ���Ҹ����ؼ��ֵļ�¼ */
   if(p)
     print(p->data);
   else
     printf("���в����ڴ�ֵ");
   printf("\n");
   DestroyDSTable(&dt);
 }
