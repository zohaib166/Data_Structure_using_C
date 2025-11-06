#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node *createNode(int data)
{
    Node *n = (Node*) malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}

Node *insertAtStart(Node *last, int data)
{
    Node *n = createNode(data);
    if(last == NULL)
    {
        last = n;
        last->next = last;
        return last;
    }
    n->next = last->next;
    last -> next = n;
    return last;
}

Node *insertAtEnd(Node *last, int data)
{
    Node *n = createNode(data);
    if(last == NULL)
    {
        last = n;
        last->next = last;
        return last;
    }
    n->next = last->next;
    last -> next = n;
    last = n;
    return last;
}

void display(Node *last)
{
    if(last == NULL)
    {
        printf("CLL is empty\n");
        return;
    }
    Node *ptr = last->next;
    do 
    {
        printf("%d ", ptr->data);
        ptr = ptr -> next;
    } while(ptr != last -> next);
    
    printf("\n");
}

int main()
{
    Node *last = NULL;
    last = insertAtStart(last, 2);
    last = insertAtStart(last, 3);
    last = insertAtStart(last, 4);
    
    display(last);
    
    last = insertAtEnd(last, 5);
    last = insertAtEnd(last, 6);
    last = insertAtEnd(last, 7);
    
    display(last);
}