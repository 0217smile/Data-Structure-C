 /* c9-2.h ƽ������������� */
 typedef struct BSTNode
 {
   ElemType data;
   int bf; /* ����ƽ������ */
   struct BSTNode *lchild,*rchild; /* ���Һ���ָ�� */
 }BSTNode,*BSTree;
