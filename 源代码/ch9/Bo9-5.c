 /* bo9-5.c ��̬���ұ�(˫������)�Ļ������� */
 Status InitDSTable(DLTree *DT)
 { /* �������: ����һ���յ�˫������DT */
   *DT=NULL;
   return OK;
 }

 void DestroyDSTable(DLTree *DT)
 { /* ��ʼ����: ˫������DT���ڡ��������: ����˫������DT */
   if(*DT) /* �ǿ��� */
   {
     if((*DT)->kind==BRANCH&&(*DT)->a.first) /* *DT�Ƿ�֧������к��� */
       DestroyDSTable(&(*DT)->a.first); /* ���ٺ������� */
     if((*DT)->next) /* ���ֵ� */
       DestroyDSTable(&(*DT)->next); /* �����ֵ����� */
     free(*DT); /* �ͷŸ���� */
     *DT=NULL; /* ��ָ�븳0 */
   }
 }

 Record *SearchDLTree(DLTree T,KeysType K)
 { /* �ڷǿ�˫������T�в��ҹؼ��ֵ���K�ļ�¼�������ڣ� */
   /* �򷵻�ָ��ü�¼��ָ�룬���򷵻ؿ�ָ�롣�㷨9.15���иĶ� */
   DLTree p;
   int i;
   if(T)
   {
     p=T; /* ��ʼ�� */
     i=0;
     while(p&&i<K.num)
     {
       while(p&&p->symbol!=K.ch[i]) /* ���ҹؼ��ֵĵ�iλ */
         p=p->next;
       if(p&&i<K.num) /* ׼��������һλ */
         p=p->a.first;
       ++i;
     } /* ���ҽ��� */
     if(!p) /* ���Ҳ��ɹ� */
       return NULL;
     else /* ���ҳɹ� */
       return p->a.infoptr;
   }
   else
     return NULL; /* ���� */
 }

 void InsertDSTable(DLTree *DT,Record *r)
 { /* ��ʼ����: ˫������DT���ڣ�rΪ�����������Ԫ�ص�ָ�� */
   /* �������: ��DT�в�������ؼ��ֵ���(*r).key.ch������Ԫ�أ� */
   /*           �򰴹ؼ���˳���r��DT�� */
   DLTree p=NULL,q,ap;
   int i=0;
   KeysType K=r->key;
   if(!*DT&&K.num) /* �����ҹؼ��ַ����ǿ� */
   {
     *DT=ap=(DLTree)malloc(sizeof(DLTNode));
     for(;i<K.num;i++) /* �����֧��� */
     {
       if(p)
         p->a.first=ap;
       ap->next=NULL;
       ap->symbol=K.ch[i];
       ap->kind=BRANCH;
       p=ap;
       ap=(DLTree)malloc(sizeof(DLTNode));
     }
     p->a.first=ap; /* ����Ҷ�ӽ�� */
     ap->next=NULL;
     ap->symbol=Nil;
     ap->kind=LEAF;
     ap->a.infoptr=r;
   }
   else /* �ǿ��� */
   {
     p=*DT; /* ָ������ */
     while(p&&i<K.num)
     {
       while(p&&p->symbol<K.ch[i]) /* ���ֵܽ����� */
       {
         q=p;
         p=p->next;
       }
       if(p&&p->symbol==K.ch[i]) /* �ҵ���K.ch[i]����Ľ�� */
       {
         q=p;
         p=p->a.first; /* pָ����K.ch[i+1]�ȽϵĽ�� */
         ++i;
       }
       else /* û�ҵ�,����ؼ��� */
       {
         ap=(DLTree)malloc(sizeof(DLTNode));
         if(q->a.first==p)
           q->a.first=ap; /* �ڳ��ӵ�λ�ò��� */
         else /* q->next==p */
           q->next=ap; /* ���ֵܵ�λ�ò��� */
         ap->next=p;
         ap->symbol=K.ch[i];
         ap->kind=BRANCH;
         p=ap;
         ap=(DLTree)malloc(sizeof(DLTNode));
         i++;
         for(;i<K.num;i++) /* �����֧��� */
         {
           p->a.first=ap;
           ap->next=NULL;
           ap->symbol=K.ch[i];
           ap->kind=BRANCH;
	   p=ap;
           ap=(DLTree)malloc(sizeof(DLTNode));
         }
         p->a.first=ap; /* ����Ҷ�ӽ�� */
         ap->next=NULL;
         ap->symbol=Nil;
         ap->kind=LEAF;
         ap->a.infoptr=r;
       }
     }
   }
 }

 typedef struct
 {
   char ch;
   DLTree p;
 }SElemType; /* ����ջԪ������ */
 #include"c3-1.h"
 #include"bo3-1.c"
 void TraverseDSTable(DLTree DT,void(*Vi)(Record))
 { /* ��ʼ����: ˫������DT���ڣ�Vi�ǶԽ�������Ӧ�ú����� */
   /*           ViR�ǶԼ�¼������Ӧ�ú��� */
   /* �������: ���ؼ��ֵ�˳������ؼ��ּ����Ӧ�ļ�¼ */
   SqStack s;
   SElemType e;
   DLTree p;
   int i=0,n=8;
   if(DT)
   {
     InitStack(&s);
     e.p=DT;
     e.ch=DT->symbol;
     Push(&s,e);
     p=DT->a.first;
     while(p->kind==BRANCH) /* ��֧��� */
     {
       e.p=p;
       e.ch=p->symbol;
       Push(&s,e);
       p=p->a.first;
     }
     e.p=p;
     e.ch=p->symbol;
     Push(&s,e);
     Vi(*(p->a.infoptr));
     i++;
     while(!StackEmpty(s))
     {
       Pop(&s,&e);
       p=e.p;
       if(p->next) /* ���ֵܽ�� */
       {
         p=p->next;
         while(p->kind==BRANCH) /* ��֧��� */
         {
           e.p=p;
           e.ch=p->symbol;
           Push(&s,e);
           p=p->a.first;
         }
         e.p=p;
         e.ch=p->symbol;
         Push(&s,e);
         Vi(*(p->a.infoptr));
         i++;
         if(i%n==0)
           printf("\n"); /* ���n��Ԫ�غ��� */
       }
     }
   }
 }
