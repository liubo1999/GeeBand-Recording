/**********************************************************
 *	单链表的基本操作
 *	
 *	功能包含：
 *		节点的数据结构，链表遍历，节点的插入，节点的删除
 *
 *********************************************************/

//数据结构
class node
{
	public:
		int data;
		node* next;
};


//链表遍历
void print (node* head) {
	for (node* p = head; p != NULL; p = p->next)
		cout << p->data;
	cout << endl;
}

int getLength (node* head) {
	int len = 0;
	while (head != NULL) {
		head = head->nex;
		len ++;
	}

	return len;
}


//插入节点

//插入到头部
void insertBegin (node*& head, int val) {
	node* newNode = new node();
	newNode->data = val;
	newNode->next = head;

	head = newNode;
}

//插入到尾部
void insertEnd (node*& head, int val) {
	node* newNode = new node();
	newNode->data = val;
	newNode->next = NULL;

	if (head == NULL) {
		head = newNode;
	}

	else {
		node* p = head;
		while (p->next != NULL)
			p = p->next;
		p->next = newNode;
	}
}

//在有序表中插入到指定位置
void insert (node*& head, int num) {
	node *cur = head, *pre = NULL;
	while (cur->data < num && pre->next != NULL)
		pre = cur, cur = cur->next;

	node* p = new node();
	p->data = num;

	//链表中的数据全部小于num
	if (cur->data < num) {
		cur->next = p;
		p->next = NULL;
	} 

	//链表中的数据全部大于num
	else if (cur == head) {
		p->next = cur;
		head = p;
	}

	//第三种情况：位于首尾之间,插入到previous和current中间
	else {
		pre->next = p;
		p->next = cur;
	} 
}


//删除节点
void remove (node*& head, int num) {
	node *cur = head, *pre = NULL;
	while (cur->data != num && cur->next != NULL) {
		pre = cur;
		cur = cur->next;
	}

	if (cur->data != num)
		cout << "Can't Found " << num <<endl;

	else {
		//删除头节点
		if (cur == head) {
			head = cur->next;
			delete cur;
		}
		
		//删除非头节点
		else {
			pre->next = cur->next;
			delete cur;
		}
	}

}