 /* c10-1.h ���ż�¼���������� */
 #define MAXSIZE 20 /* һ������ʾ����С˳������󳤶� */
 typedef int KeyType; /* ����ؼ�������Ϊ���� */
 typedef struct
 {
   KeyType key; /* �ؼ����� */
   InfoType otherinfo; /* ������������������������ж��� */
 }RedType; /* ��¼���� */

 typedef struct
 {
   RedType r[MAXSIZE+1]; /* r[0]���û������ڱ���Ԫ */
   int length; /* ˳����� */
 }SqList; /* ˳������� */
