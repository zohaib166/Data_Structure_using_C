#ifndef STD

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *next;
} node;

typedef struct stack
{
    node *top;
} stack;

node *createNode(char data)
{
    node *n = (node*) malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
}

void init(stack *s) {
    s->top = NULL;
    printf("A Stack is initialized\n");
}

int isEmpty(stack *s) {
    if(s->top == NULL)
        return 1;
    return 0;
}

void push(stack *s, char num)
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

char peek(stack *s)
{
    if(s->top == NULL)
    {
        printf("Stack is empty\n");
        return '\0';
    }
    return s->top->data;
}

// int main()
// {
//     stack s;
//     init(&s);

//     push(&s, 'A');
//     push(&s, 'B');
//     push(&s, 'C');

//     printf("%c\n", peek(&s));
//     pop(&s);
//     printf("%c\n", peek(&s));
//     pop(&s);
//     printf("%c\n", peek(&s));
//     pop(&s);
//     printf("%c\n", peek(&s));
// }

#endif // INCLUDE