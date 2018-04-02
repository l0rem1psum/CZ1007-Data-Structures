#include <stdio.h>
#include <stdlib.h>

typedef struct _listNode{
    int item;
    struct _listNode* next;
} ListNode;

typedef struct _linkedList{
    ListNode* head;
    //ListNode* tail;
    int size;
} LinkedList;

typedef struct _queue{
    LinkedList ll;
} Queue;

void printList(LinkedList *ll);
ListNode * findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);
void enqueue(Queue *q, int item);
int dequeue(Queue *q);
int peek(Queue *q);
int isEmptyQueue(Queue *q);

int main()
{
    int i;
    Queue q;
    q.ll.size = 0;//REMEMBER TO INITIALIZE
    q.ll.head = NULL;//REMEMBER TO INITIALIZE
    for (i = 1; i < 10; i++){
        enqueue(&q, i);
    }
    printList(&(q.ll));
    printf("%d\n", dequeue(&q));
    printList(&(q.ll));

}

void enqueue(Queue *q, int item){

    insertNode(&(q -> ll), (q -> ll).size, item);
}

int dequeue(Queue *q){
    int item;
    item = ((q -> ll).head) -> item;
    removeNode(&(q -> ll), 0);
    return item;
}

int peek(Queue *q){
    return ((q -> ll).head) -> item;
}

int isEmptyQueue(Queue *q){
    if ((q -> ll).size == 0){return 1;}
    return 0;
}

void printList(LinkedList *ll){

	ListNode *cur;
	if (ll == NULL)
		return;
	cur = ll->head;
	if (cur == NULL)
		printf("Empty");
	while (cur != NULL)
	{
		printf("%d ", cur->item);
		cur = cur->next;
	}
	printf("\n");
}

ListNode * findNode(LinkedList *ll, int index){

	ListNode *temp;

	if (ll == NULL || index < 0 || index >= ll->size)
		return NULL;

	temp = ll->head;

	while (index > 0){
		temp = temp->next;
		if (temp == NULL)
			return NULL;
		index--;
	}

	return temp;
}

int insertNode(LinkedList *ll, int index, int value){

	ListNode *pre, *cur;

	if (ll == NULL || index < 0 || index > ll->size + 1)
		return -1;

	if (ll->head == NULL || index == 0){
		cur = ll->head;
		ll->head = malloc(sizeof(ListNode));
		ll->head->item = value;
		ll->head->next = cur;
		ll->size++;
		return 0;
	}

	if ((pre = findNode(ll, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->item = value;
		pre->next->next = cur;
		ll->size++;
		return 0;
	}

	return -1;
}


int removeNode(LinkedList *ll, int index){

	ListNode *pre, *cur;

	if (ll == NULL || index < 0 || index >= ll->size)
		return -1;

	if (index == 0){
		cur = ll->head->next;
		free(ll->head);
		ll->head = cur;
		ll->size--;

		return 0;
	}


	if ((pre = findNode(ll, index - 1)) != NULL){

		if (pre->next == NULL)
			return -1;

		cur = pre->next;
		pre->next = cur->next;
		free(cur);
		ll->size--;
		return 0;
	}

	return -1;
}
