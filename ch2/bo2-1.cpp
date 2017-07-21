//bo2-1.cpp ˳���ʾ�����Ա�(�洢�ṹ��c2-1.h����)�Ļ�������(12��),�����㷨2.3,2.4,2.5,2.6
void InitList(SqList &L){
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElesType));
	if(!L.elem)
		exit(OVERFLOW);//�洢����ʧ��
	L.length = 0; //�ձ���Ϊ0
	L.listsize = LIST_INIT_SIZE; //��ʼ�洢����
}

void DestoryList(SqList &L){
	//��ʼ������˳�����Ա�L�Ѵ��ڡ��������������˳�����Ա�L
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
}
void ClearList(SqList &L){
	//��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ�
	L.length = 0;
}
Status ListEmpty(SqList L){
	// ��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE
	if(L.length == 0)
		return TRUE;
	else
		return FALSE;
}
int ListLength(SqList L){
	 // ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�صĸ���
	return L.length;
}