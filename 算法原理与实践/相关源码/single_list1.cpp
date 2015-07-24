/**********************************************************
 *	单链表的基本操作1
 *	
 *	功能包含：
 *		链表排序，链表遍历，节点的插入，节点的删除
 *
 *********************************************************/


class node
{
	public:
		int data;
		node* next;
};


//经典O(n^2)的冒泡排序算法
 void bubbleSort (node* head) {
 	int len = 0;
 	for (node* p = head; p != NULL; p = p->next) {
 		len ++;
 	} 

 	for (int i = 1; i < len; i++) {
 		node* p = head;
 		for(int j = 0; j < len - i; j++, p = p->next) {
 			if (p->data > p->next->data)
 			{
 				int tem = p->data;
 				p->data = p->next->data;
 				p->next->data = tem;
 			}

 		}
 	}

 }



//归并排序

node* mergesort(node *lsit1, node *list2)
{
	if (list1 == NULL) return list2;
	else if(list2 == NULL) return list1;

	node *result= new node(), *p = result;
	while (list1 != NULL && list2 != NULL)
		if (list1->data < list2->data)
			result->next = list1, result = list1, list1 = list1->next;
		else
			result->next = list2, result = lsit2, list2 = list2->next;
	if (list1 != NULL)	result->next = list1;
	if (list2 != NULL)	result->next = list2;


	//返回头节点
	result = p->next;
	delete p;
	return result;
}


//将链表分割为两个链表
//head:原链表
//list1,list2:分割后的两个链表

void split(node *head, node *&list1, node *&list2)
{
	if (head == NULL || head->next == NULL)
	{
		list1 = head, list2 = NULL;		return;
	}

	node *slow = head, *fast = head->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
			fast = fast->next, slow = slow->next;
	}
	list1 = head, list2 = slow->next;
	slow->next = NULL;
}


//归并排序主函数

void mergeSort(node *&head)
{
	if (head == NULL || head->next == NULL) 
		return;
	
	node *list1, *list2;
	split(head, list1, list2);
	mergeSort(list1);
	mergeSort(list2); 
	head = mergesort(list1, list2);
}