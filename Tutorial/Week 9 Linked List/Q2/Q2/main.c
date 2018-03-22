#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int i;
    struct node *next;
} listNode;

int main()
{
    int i;
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

    if (head == NULL){return 0;}
    /*THIS IS VERY IMPORTANT SINCE IF USERS ENTER -1 */
    /*THEN THE PROGRAM WILL RUN IN ERROR WITHOUT THIS LINE*/

    cur -> next = NULL;

    printf("Current list: ");
    cur = head;
    while (cur != NULL) {
        printf("%d ", cur -> i);
        cur = cur -> next;
    }
    return 0;
}
