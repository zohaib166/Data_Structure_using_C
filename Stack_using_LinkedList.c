#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct stack
{
    node *top;
} stack;

node *createNode(int data)
{
    node *n = (node*) malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
}

void init(stack *s) {
    s->top = NULL;
    printf("Empty stack initialized\n");
}

void push(stack *s, int num)
{
    node *n = createNode(num);
    if(s->top == NULL)
    {
        s->top = n;
        return;
    }
    n->next = s->top;
    s->top = n;
}

void pop(stack *s)
{
    if(s->top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    node *temp = s->top;
    s->top = s->top->next;
    free(temp);
}

int peek(stack *s)
{
    if(s->top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return s->top->data;
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