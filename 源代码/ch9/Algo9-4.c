 /* algo9-4.c ����bo9-2.c�ĳ��� */
 #include"c1.h"
 #define N 10 /* ����Ԫ�ظ��� */
 typedef int KeyType; /* ��ؼ�����Ϊ���� */
 typedef struct
 {
   KeyType key;
   int others;
 } ElemType; /* ����Ԫ������ */
 #include"c9.h"
 #include"bo9-2.c"

 void print(ElemType c)
 {
   printf("(%d,%d) ",c.key,c.others);
 }

 void main()
 {
   BiTree dt,p;
   int i;
   KeyType j;
   ElemType r[N]={{45,1},{12,2},{53,3},{3,4},{37,5},{24,6},{100,7},{61,8},{90,9},{78,10}}; /* �Խ̿���ͼ9.7(a)Ϊ�� */
   InitDSTable(&dt); /* ����ձ� */
   for(i=0;i<N;i++)
     InsertBST(&dt,r[i]); /* ���β�������Ԫ�� */
   TraverseDSTable(dt,print);
   printf("\n����������ҵ�ֵ: ");
   scanf("%d",&j);
   p=SearchBST(dt,j);
   if(p)
   {
     printf("���д��ڴ�ֵ��");
     DeleteBST(&dt,j);
     printf("ɾ����ֵ��:\n");
     TraverseDSTable(dt,print);
     printf("\n");
   }
   else
     printf("���в����ڴ�ֵ\n");
   DestroyDSTable(&dt);
 }
