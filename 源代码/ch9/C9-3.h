 /* c9-3.h B���Ľ������ */
 typedef struct
 {
   KeyType key; /* �ؼ��� */
   Others others; /* ��������(�����̶���) */
 }Record; /* ��¼���� */

 typedef struct BTNode
 {
   int keynum; /* ����йؼ��ָ����������Ĵ�С */
   struct BTNode *parent; /* ָ��˫�׽�� */
   struct Node /* ����������� */
   {
     KeyType key; /* �ؼ������� */
     struct BTNode *ptr; /* ����ָ������ */
     Record *recptr; /* ��¼ָ������ */
   }node[m+1]; /* key,recptr��0�ŵ�Ԫδ�� */
 }BTNode,*BTree; /* B������B�������� */

 typedef struct
 {
   BTNode *pt; /* ָ���ҵ��Ľ�� */
   int i; /* 1..m���ڽ���еĹؼ������ */
   int tag; /* 1:���ҳɹ���O:����ʧ�� */
 }Result; /* B���Ĳ��ҽ������ */
