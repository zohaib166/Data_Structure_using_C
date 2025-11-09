#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} Node;

Node *createNode(int data)
{
    Node *n = (Node*) malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}
Node *append(Node *tail, int data)
{
    Node *n = createNode(data);
    if(tail == NULL)
    {
        tail = n;
        n->next = n;
        return tail;
    }
    
    n->next = tail->next;
    tail->next = n;
    tail = n;
    return tail;
}

Node *prepend(Node *tail, int data)
{
    Node *n = createNode(data);
    if(tail == NULL)
    {
        tail = n;
        n->next = n;
        return tail;
    }
    n->next = tail->next;
    tail->next = n;
    return tail;
}

Node *insertAtPos(Node *tail, int data, int pos)
{
    Node *n = createNode(data);
    if(tail == NULL)
    {
        tail = n;
        n->next = n;
        return tail;
    }
    
    if(pos == 0)
    {
        tail = prepend(tail, data);
        return tail;
    }
    Node *ptr = tail->next;
    for(int i = 0; i < pos - 1; i++)
    {
        if(ptr == tail) {
            break;
        }
        ptr = ptr->next;
    }
    n->next = ptr->next;
    ptr->next = n;
    if(ptr==tail) {
        tail = tail->next;
    }
    return tail;
}

void display(Node *tail)
{
    if(tail == NULL)
        printf("Linked List is empty\n");
    Node *ptr = tail->next;
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while(ptr != tail->next);
    printf("\n");
}

int main()
{
    Node *tail = NULL;
    tail = append(tail, 10);
    tail = append(tail, 20);
    tail = append(tail, 30);
    tail = append(tail, 40);
    display(tail);
    tail = prepend(tail, 50);
    tail = prepend(tail, 60);
    tail = prepend(tail, 70);
    tail = prepend(tail, 80);
    display(tail);
    
    tail = insertAtPos(tail, 12, 3);
    display(tail);
    tail = insertAtPos(tail, 13, 9);
    display(tail);
}
