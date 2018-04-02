#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define NULL_VALUE -1
typedef struct _listNode{
    int item;
    struct _listNode* next;
} ListNode;

typedef struct _linkedList{
    ListNode* head;
    int size;
} LinkedList;

typedef struct _stack{
    int num[MAX];
    int top;
} Stack;

void push(Stack *s, int item);
int pop(Stack *s);
int peek(Stack *s);
int isEmptyStack(Stack *s);
int isFullStack(Stack *s);
void printList(Stack* s);

int main()
{
    int i;
    Stack s;
    s.top = -1;
    for (i = 0; i < 10; i++){
        push(&s, i);
    }
    printList(&s);
    printf("\n%d\n", pop(&s));
    printf("\n%d\n", peek(&s));
    printList(&s);
}


void push(Stack *s, int item){
    if (!isFullStack(s)){
        s -> num[s -> top + 1] = item;
        (s -> top) ++;
    }
    return;
}

int pop(Stack *s){
    if (!isEmptyStack(s)){
        int item;
        item = s -> num[s -> top];
        (s -> top)--;
        return item;
    } return NULL_VALUE;

    //AlTERNATE WAY:
    //if (!isEmptyStack(s)){
        //return (s -> num[(s -> top)--]);
    //} return NULL;
}

int peek(Stack *s){
    return s -> num[s -> top];
}

int isEmptyStack(Stack *s){
    if ((s -> top) == -1) return 1;
    return 0;
}

int isFullStack(Stack *s){
    if ((s -> top) == MAX - 1) {return 1;}
    return 0;
}

void printList(Stack* s){
    if(!isEmptyStack(s)){
        int i;
        for (i = 0; i <= (s -> top); i++){
            printf("%d ", s -> num[i]);
        }
    } else {
        printf("Empty");
    }
    printf("\n");
}
