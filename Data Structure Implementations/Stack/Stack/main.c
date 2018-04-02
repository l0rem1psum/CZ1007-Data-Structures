#include <stdio.h>
#include <stdlib.h>

typedef struct _listNode{
    int item;
    struct _listNode* next;
} ListNode;

typedef struct _linkedList{
    ListNode* head;
    int size;
} LinkedList;

typedef struct _stack{
    LinkedList ll;
} Stack;

int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);
ListNode * findNode(LinkedList *ll, int index);
void printList(LinkedList *ll);
void push(Stack *s, int item);
int pop(Stack *s);
int peek(Stack *s);
int isEmptyStack(Stack *s);

int main()
{
    int i;
    Stack s;
    for (i = 0; i < 10; i++){
        push(&s, i);
    }
    printList(&(s.ll));
    printf("\n%d\n", pop(&s));
    printf("\n%d\n", peek(&s));
    printList(&(s.ll));
}


void push(Stack *s, int item){
    insertNode(&(s -> ll), 0, item);
}

int pop(Stack *s){
    int item;
    item = ((s -> ll).head) -> item;
    removeNode(&(s -> ll), 0);
    return item;
}

int peek(Stack *s){
    return ((s -> ll).head) -> item;
}

int isEmptyStack(Stack *s){
    if ((s -> ll).size == 0) return 1;
    return 0;
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


ListNode * findNode(LinkedList *ll, int index){

	ListNode *temp;

	if (ll == NULL || index < 0 || index >= ll->size)
		return NULL;

	temp = ll->head;

	if (temp == NULL || index < 0)
		return NULL;

	while (index > 0){
		temp = temp->next;
		if (temp == NULL)
			return NULL;
		index--;
	}

	return temp;
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

