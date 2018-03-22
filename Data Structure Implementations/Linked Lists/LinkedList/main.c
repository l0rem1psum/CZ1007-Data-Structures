#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int i;
    struct node *next;
} listNode;
void printList(listNode * head);
listNode * findNode(listNode * head, int i);

int main()
{
    int i, pos, val, tmp;
    listNode *cur, *head = NULL;/*INITIALIZE HEAD TO A NULL POINTER*/

    printf("Enter a list of numbers, terminated by the value -1:\n");

    scanf("%d", &i);/*ASK FOR INPUT BEFORE WHILE LOOP*/
    while (i != -1) {
        if (head == NULL) {/*CHECK IF HEAD IS NULL TO ALLOCATE SPACE TO THE FIRST NODE*/
            head = malloc(sizeof(listNode));
            cur = head;
        } else {
            cur -> next = malloc(sizeof(listNode));
            cur = cur -> next;
        }
        cur -> i = i;
        scanf("%d", &i);
    }

    cur -> next = NULL;

    printf("Current list: ");
    printList(head);


    printf("Please enter where do you want to insert the value: ");
    scanf("%d", &pos);
    printf("Please enter what value you want to insert at index %d: ", pos);
    scanf("%d", &val);
    printf("Inserted list: ");
    tmp = insertNode(&head, pos, val);
    printList(head);

    return 0;
}

void printList(listNode * head){

    listNode * temp = head;
    if (temp == NULL){
        return;
    /*THIS IS VERY IMPORTANT SINCE IF USERS ENTER -1 */
    /*THEN THE PROGRAM WILL RUN IN ERROR WITHOUT THIS LINE*/
    } else {
        while (temp) {
            printf("%d ", temp -> i);
            temp = temp -> next;
        }
        printf("\n");
    }
}

listNode * findNode(listNode * head, int i){
    listNode * temp = head;
    if (head == NULL || i < 0){return NULL;}
    while (i > 0) {
        temp = temp -> next;
        if (temp == NULL) {return NULL;}
        i--;
    }
    return temp;
}

int insertNode(listNode ** ptrHead, int index, int value){
    listNode * pre, * cur;
    if (*ptrHead == NULL || index == 0){
        pre = *ptrHead;
        *ptrHead = malloc(sizeof(listNode));
        (*ptrHead) -> i = value;
        (*ptrHead) -> next = pre;
        return 0;//Remember to return 0 upon successful execution
    } else if ((pre = findNode(*ptrHead, index - 1))) {
        cur = malloc(sizeof(listNode));
        cur -> i = value;
        cur -> next = pre -> next;
        pre -> next = cur;
        return 0;
    }
    return -1;
}
