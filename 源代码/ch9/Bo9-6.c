 /* bo9-6.c ��̬���ұ�(Trie����)�Ļ������� */
 Status InitDSTable(TrieTree *T)
 { /* �������: ����һ���յ�Trie����T */
   *T=NULL;
   return OK;
 }

 void DestroyDSTable(TrieTree *T)
 { /* ��ʼ����: Trie��T���ڡ��������: ����Trie��T */
   int i;
   if(*T) /* �ǿ��� */
   {
     for(i=0;i<LENGTH;i++)
       if((*T)->kind==BRANCH&&(*T)->a.bh.ptr[i]) /* ��i����㲻�� */
         if((*T)->a.bh.ptr[i]->kind==BRANCH) /* ������ */
           DestroyDSTable(&(*T)->a.bh.ptr[i]);
         else /* ��Ҷ�� */
         {
           free((*T)->a.bh.ptr[i]);
           (*T)->a.bh.ptr[i]=NULL;
         }
     free(*T); /* �ͷŸ���� */
     *T=NULL; /* ��ָ�븳0 */
   }
 }

 int ord(char c)
 {
   c=toupper(c);
   if(c>='A'&&c<='Z')
     return c-'A'+1; /* Ӣ����ĸ����������ĸ���е���� */
   else
     return 0; /* �����ַ�����0 */
 }

 Record *SearchTrie(TrieTree T,KeysType K)
 { /* �ڼ���T�в��ҹؼ��ֵ���K�ļ�¼���㷨9.16 */
   TrieTree p;
   int i;
   for(p=T,i=0;p&&p->kind==BRANCH&&i<K.num;p=p->a.bh.ptr[ord(K.ch[i])],++i);
   /* ��K��ÿ���ַ��������,*pΪ��֧���,ord()���ַ�����ĸ������� */
   if(p&&p->kind==LEAF&&p->a.lf.K.num==K.num&&EQ(p->a.lf.K.ch,K.ch)) /* ���ҳɹ� */
     return p->a.lf.infoptr;
   else /* ���Ҳ��ɹ� */
     return NULL;
 }

 void InsertTrie(TrieTree *T,Record *r)
 { /* ��ʼ����: Trie����T���ڣ�rΪ�����������Ԫ�ص�ָ�� */
   /* �������: ��T�в�������ؼ��ֵ���(*r).key.ch������Ԫ�أ� */
   /*           �򰴹ؼ���˳���r��T�� */
   TrieTree p,q,ap;
   int i=0,j;
   KeysType K1,K=r->key;
   if(!*T) /* ���� */
   {
     *T=(TrieTree)malloc(sizeof(TrieNode));
     (*T)->kind=BRANCH;
     for(i=0;i<LENGTH;i++) /* ָ��������ֵNULL */
       (*T)->a.bh.ptr[i]=NULL;
     p=(*T)->a.bh.ptr[ord(K.ch[0])]=(TrieTree)malloc(sizeof(TrieNode));
     p->kind=LEAF;
     p->a.lf.K=K;
     p->a.lf.infoptr=r;
   }
   else /* �ǿ��� */
   {
     for(p=*T,i=0;p&&p->kind==BRANCH&&i<K.num;++i)
     {
       q=p;
       p=p->a.bh.ptr[ord(K.ch[i])];
     }
     i--;
     if(p&&p->kind==LEAF&&p->a.lf.K.num==K.num&&EQ(p->a.lf.K.ch,K.ch)) /* T�д��ڸùؼ��� */
       return;
     else /* T�в����ڸùؼ���,����֮ */
     {
       if(!p) /* ��֧�� */
       {
         p=q->a.bh.ptr[ord(K.ch[i])]=(TrieTree)malloc(sizeof(TrieNode));
         p->kind=LEAF;
         p->a.lf.K=K;
         p->a.lf.infoptr=r;
       }
       else if(p->kind==LEAF) /* �в���ȫ��ͬ��Ҷ�� */
       {
         K1=p->a.lf.K;
         do
	 {
           ap=q->a.bh.ptr[ord(K.ch[i])]=(TrieTree)malloc(sizeof(TrieNode));
           ap->kind=BRANCH;
           for(j=0;j<LENGTH;j++) /* ָ��������ֵNULL */
             ap->a.bh.ptr[j]=NULL;
           q=ap;
           i++;
         }while(ord(K.ch[i])==ord(K1.ch[i]));
         q->a.bh.ptr[ord(K1.ch[i])]=p;
         p=q->a.bh.ptr[ord(K.ch[i])]=(TrieTree)malloc(sizeof(TrieNode));
         p->kind=LEAF;
         p->a.lf.K=K;
         p->a.lf.infoptr=r;
       }
     }
   }
 }

 void TraverseDSTable(TrieTree T,Status(*Vi)(Record*))
 { /* ��ʼ����: Trie����T���ڣ�Vi�ǶԼ�¼ָ�������Ӧ�ú��� */
   /* �������: ���ؼ��ֵ�˳������ؼ��ּ����Ӧ�ļ�¼ */
   TrieTree p;
   int i;
   if(T)
   {
     for(i=0;i<LENGTH;i++)
     {
       p=T->a.bh.ptr[i];
       if(p&&p->kind==LEAF)
         Vi(p->a.lf.infoptr);
       else if(p&&p->kind==BRANCH)
         TraverseDSTable(p,Vi);
     }
   }
 }
