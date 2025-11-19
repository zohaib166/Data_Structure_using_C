#include <stdio.h>
#define SIZE 5

typedef struct cqueue
{
    int front;
    int rear;
    int arr[SIZE];
} cqueue;

void init(cqueue *cq) 
{
    cq->front = 0;
    cq->rear = 0;
}

int isEmpty(cqueue *cq)
{
    if(cq->front == cq->rear) 
        return 1;
    
    return 0;
}

int isFull(cqueue *cq)
{
    if((cq->rear+1)%SIZE == cq->front) 
        return 1;
    
    return 0;
}

void enqueue(cqueue *cq, int num)
{
    if(isFull(cq))
    {
        printf("The Queue is Full, inserting %d failed\n", num);
        return;
    }
    cq->rear = (cq->rear+1) % SIZE;
    cq->arr[cq->rear] = num;
    printf("Added %d...\n", num);
}

void dequeue(cqueue *cq)
{
    if(isEmpty(cq)) 
    {
        printf("The Queue is Empty, dequeue failed\n");
        return;
    }
    
    cq->front = (cq->front+1)%SIZE;
    printf("Removed %d...\n", cq->arr[cq->front]);
}

int get_front(cqueue *cq) {
    if(!isEmpty(cq)) {
        return cq->arr[(cq->front+1)%SIZE];
    }
    return -1;
}

int get_rear(cqueue *cq) {
    if(!isEmpty(cq)) {
        return cq->arr[(cq->rear)%SIZE];
    }
    return -1;
}

int main()
{
    cqueue cq;
    init(&cq);
    enqueue(&cq, 10);
    enqueue(&cq, 20);
    enqueue(&cq, 30);
    enqueue(&cq, 40);
    dequeue(&cq);
    enqueue(&cq, 50);

    printf("Front element: %d\n", get_front(&cq));
    printf("Last element: %d\n", get_rear(&cq));

    dequeue(&cq);
    printf("Front element: %d\n", get_front(&cq));
}