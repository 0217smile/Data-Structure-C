 /* algo9-2.c ����bo9-1.(�������)�ĳ��� */
 #include"c1.h"
 #define N 11 /* ����Ԫ�ظ��� */
 typedef int KeyType; /* ��ؼ�����Ϊ���� */
 typedef struct /* ����Ԫ������ */
 {
   KeyType key; /* �ؼ����� */
   int others; /* �������� */
 }ElemType;
 ElemType r[N]={{5,1},{13,2},{19,3},{21,4},{37,5},{56,6},{64,7},{75,8},
		{80,9},{88,10},{92,11}}; /* ����Ԫ��(�Խ̿���P.219������Ϊ��),ȫ�ֱ��� */
 #include"c9.h"
 #include"c9-1.h"
 #include"bo9-1.c"

 void print(ElemType c) /* Traverse()���õĺ��� */
 {
   printf("(%d %d) ",c.key,c.others);
 }

 void main()
 {
   SSTable st;
   int i;
   KeyType s;
   Creat_Ord(&st,N); /* ��ȫ����������ǽ���̬���ұ�st */
   Traverse(st,print); /* ˳������ǽ���̬���ұ�st */
   printf("\n");
   printf("�����������ֵ�Ĺؼ���: ");
   scanf("%d",&s);
   i=Search_Bin(st,s); /* �۰��������� */
   if(i)
     printf("(%d %d) %d�ǵ�%d����¼�Ĺؼ���\n",st.elem[i].key,st.elem[i].others,s,i);
   else
     printf("û�ҵ�\n");
   Destroy(&st);
 }
