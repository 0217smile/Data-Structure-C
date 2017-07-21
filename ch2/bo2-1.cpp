//bo2-1.cpp 顺序表示的线性表(存储结构由c2-1.h定义)的基本操作(12个),包括算法2.3,2.4,2.5,2.6
void InitList(SqList &L){
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElesType));
	if(!L.elem)
		exit(OVERFLOW);//存储分配失败
	L.length = 0; //空表长度为0
	L.listsize = LIST_INIT_SIZE; //初始存储容量
}

void DestoryList(SqList &L){
	//初始条件：顺序线性表L已存在。操作结果：销毁顺序线性表L
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
}
void ClearList(SqList &L){
	//初始条件：顺序线性表L已存在。操作结果：将L重置为空表
	L.length = 0;
}
Status ListEmpty(SqList L){
	// 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE；否则返回FALSE
	if(L.length == 0)
		return TRUE;
	else
		return FALSE;
}
int ListLength(SqList L){
	 // 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素的个数
	return L.length;
}