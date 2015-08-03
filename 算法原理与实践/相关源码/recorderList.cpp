/**********************************************************
Recorder List

Given a linked list and value x, write a function to recorder
this list such that all nodes less than x come before the nodes
greater than or equal to x.

***********************************************************/

ListNode *reorderList(ListNode *head, int x) {
	ListNode *newHead = NULL;
	ListNode *aDummy = new ListNode(0);
	ListNode *aCurr = aDummy;
	ListNode *bDummy = new ListNode(0);
	ListNode *bCurr = bDummy;


	while(head) {
		ListNode *next = head->next;
		head->next = NULL;
		if( head->val < x ) {
			aCurr->next = head;
			aCurr = head;
		} else {
			bCurr->next = head;
			bCurr = head;
		}
		head = next;
	}

	aCurr->next = bDummy->next;
	newHead = aDummy->next;

	delete aDummy;
	delete newHead;

}