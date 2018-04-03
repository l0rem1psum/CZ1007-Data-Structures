#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define NULL_VALUE -1
typedef struct _queue{
    int num[MAX];
    int front;
    int rear;
    int size;
}Queue;
int isEmptyQueue(Queue *q);
int peek(Queue *q);
void enqueue(Queue *q, int item);
int dequeue(Queue *q);
void printList(Queue *q);

int main()
{
    int i;
    Queue q;
    q.size = 0;
    q.front = -1;
    q.rear = -1;
    enqueue(&q, 1);
    printf("Current size of the queue is %d\n", q.size);
    enqueue(&q, 2);
    printf("Current size of the queue is %d\n", q.size);
    enqueue(&q, 3);
    printf("Current size of the queue is %d\n", q.size);
    printList(&q);
    printf("Dequeue:%d\n", dequeue(&q));
    printf("Current size of the queue is %d\n", q.size);
    printList(&q);
    printf("Dequeue:%d\n", dequeue(&q));
    printf("Current size of the queue is %d\n", q.size);
    printList(&q);
    printf("\n");
    for(i = 0; i < 8; i++){
        enqueue(&q, i);
    }
    printList(&q);
    printf("Current size of the queue is %d\n", q.size);
    enqueue(&q, 8);
    printList(&q);
    printf("Current size of the queue is %d\n", q.size);
    printf("Dequeue:%d\n", dequeue(&q));
    printf("Current size of the queue is %d\n", q.size);
    printList(&q);
    printf("Dequeue:%d\n", dequeue(&q));
    printf("Current size of the queue is %d\n", q.size);
    printList(&q);
    /*Queue q;
    q.size = 0;
    q.front = 0;
    q.rear = 0;
    enqueue(&q, 1);
    enqueue(&q, 2);
    dequeue(&q);
    printf("Current size of the queue is %d\n", q.size);
    printList(&q);
    dequeue(&q);
    printf("Current size of the queue is %d\n", q.size);
    printList(&q);
    enqueue(&q, 1);
    printList(&q);*/

}

int isEmptyQueue(Queue *q){
    if (q -> size == 0){return 1;}
    return 0;
}

int isFullQueue(Queue *q){
    if (q -> size == MAX){return 1;}
    return 0;
}

int peek(Queue *q){
    return q -> num[q -> front];
}

void enqueue(Queue *q, int item){
    if (q -> size < MAX){
        if (!isEmptyQueue(q)){
            q -> rear = ((q -> rear) + 1) % MAX;
            q -> num[q -> rear] = item;
            (q -> size)++;
        } else {
            q -> num[q -> front] = item;
            (q -> size)++;
        }
    }
    return;
}

int dequeue(Queue *q){
    if (!isEmptyQueue(q)){
        int temp;
        temp = q -> num[q -> front];
        (q -> size)--;
        if (q -> size > 0)//THIS LINE IS FUCKING IMPORTANT
            q -> front = (q -> front + 1) % MAX;
        return temp;
    } else {return NULL_VALUE;}
}

void printList(Queue *q){
    int i;
    if (!isEmptyQueue(q)){
        if (q -> front <= q -> rear){
            for (i = q -> front; i <= q -> rear; i++){
                printf("%d ", q -> num[i]);
            }
        } else {
            for (i = q -> front; i < MAX; i++){
                printf("%d ", q -> num[i]);
            }
            for (i = 0; i <= q -> rear; i++){
                printf("%d ", q -> num[i]);
            }
        }
    } else {printf("Empty\n");}
    printf("\n");
}
