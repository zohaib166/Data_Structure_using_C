#include <stdio.h>
#define SIZE 5

typedef struct stack
{
    int data[SIZE];
    int top;
} stack;

void init(stack *s)
{
    s->top = -1;
}

void push(stack *s, int num)
{
    if(s->top == SIZE-1)
    {
        printf("Stack is full\n");
        return;
    }
    s->data[++s->top] = num;
    return;
}

void pop(stack *s)
{
    if(s->top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    s->top--;
    return;
}

int peek(const stack *s)
{
    if(s->top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return s->data[s->top];
}

int main()
{
    stack s;
    init(&s);

    push(&s, 40);
    push(&s, 30);
    push(&s, 20);

    printf("%d\n", peek(&s));
    pop(&s);
    printf("%d\n", peek(&s));
    pop(&s);
    printf("%d\n", peek(&s));
    pop(&s);
    printf("%d\n", peek(&s));
}