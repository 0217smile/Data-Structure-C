 /* c4-3.h ���Ŀ����洢��ʾ */
 #define CHUNKSIZE 4 /* �����û�����Ŀ��С */
 typedef struct Chunk
 {
   char ch[CHUNKSIZE];
   struct Chunk *next;
 }Chunk;
 typedef struct
 {
   Chunk *head,*tail; /* ����ͷ��βָ�� */
   int curlen; /* ���ĵ�ǰ���� */
 }LString;