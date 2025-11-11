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
    printf("Hello\n");
    for(int i = 0; i < pos - 1; i++)
    {
        ptr = ptr->next;
    }
    n->next = ptr->next;
    ptr->next = n;
    if(ptr==tail) {
        tail = tail->next;
    }
    return tail;
}

Node *deleteAtPos(Node *tail, int pos)
{
    if(tail == NULL)
    {
        printf("CLL is empty\n");
        return tail;
    }

    Node *ptr = tail->next;
    if(pos == 0)
    {
        if(ptr == tail) // only node to be deleted
        {
            free(tail);
            tail = NULL;
            return tail;
        }
        tail->next = ptr->next;
        free(ptr);
        return tail;
    }
    Node *tptr = ptr; //trailing pointer for ptr;
    for(int i=0; i < pos; i++)
    {
        tptr = ptr;
        ptr = ptr -> next;
    }

    tptr->next = ptr->next;
    if(ptr == tail) {
        tail = tptr;
    }
    free(ptr);
    return tail;
}

void display(Node *tail)
{
    if(tail == NULL) {
        printf("Linked List is empty\n");
        return;
    }
        
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

    tail = prepend(tail, 50);
    tail = prepend(tail, 60);
    tail = prepend(tail, 70);
    tail = prepend(tail, 80);
    display(tail);
    
    tail = insertAtPos(tail, 12, 3);
    display(tail);
    tail = insertAtPos(tail, 13, 2);
    display(tail);

    tail = deleteAtPos(tail, 3);

    display(tail);
}
