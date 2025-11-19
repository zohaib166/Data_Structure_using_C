#include <stdio.h>
#define SIZE 5

typedef struct queue 
{
    int front;
    int rear;
    int arr[SIZE];
} queue;

void init(queue *s)
{
    s->front = -1;
    s->rear = -1;
}

void enqueue(queue *s, int num)
{
    if(s->rear == SIZE-1) {
        printf("\nQueue is full\n");
        return;
    }
    
    s->arr[++s->rear] = num;
}

void dequeue(queue *s)
{
    if(s->rear == s->front & s->rear != SIZE-1) {
        printf("\nQueue is empty\n");
        return;
    }
    s->front++;
}

int get_front(queue *s) {
    if(s->front!=s->rear) {
        return s->arr[(s->front)+1];
    }
    return -1;
}

int get_rear(queue *s) {
    if(s->front!=s->rear) {
        return s->arr[s->rear];
    }
    return -1;
}

int main()
{
    queue s;
    init(&s);
    
    printf("%d ", get_rear(&s));
    
    enqueue(&s, 30);
    enqueue(&s, 40);
    enqueue(&s, 50);
    enqueue(&s, 60);
    enqueue(&s, 70);
    
    printf("%d ", get_front(&s));
    
    dequeue(&s);

    printf("%d ", get_front(&s));
    dequeue(&s);
    dequeue(&s);
    dequeue(&s);
    dequeue(&s);

}
