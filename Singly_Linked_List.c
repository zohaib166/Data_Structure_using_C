/*
Singly Linked List - Creation, Insertion, Deletion and Printing
*/
//Singly Linked List Definition
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;    
} Node;

/* Append function takes the address of the first node of the Linked List
    and the data, it creates a new node, appends it at the last of the existing
    Linked List. This function returns the address of the head node of the updated Linked List
*/
Node *append(Node *head, int data)
{
    //Creating a new node, putting data in it and setting its pointer to NULL
    Node *n = (Node*) malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;

    //If the Linked List is empty make the newly created node as head node, and return its address
    if(head == NULL)
    {
        head = n;
        return head;
    }
    //if the linked list already has one or more nodes,
    //put a temporary pointer at head, it will be used for traversal of LL
    Node *ptr = head;
    //take the ptr pointer to the last node
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    //Link the last node with the newly created node n
    ptr->next = n;

    return head;
}

Node *prepend(Node *head, int data)
{
    //Create a new node
    Node *n = (Node*) malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    //if this node is the first node of the linked list
    if(head==NULL)
    {
        head = n;
        return head;
    }
    n->next = head;
    head = n;
    return head;
}

/*Display function prints the Singly Linked List*/
void display(Node *head)
{
    Node* ptr = head;
    while(ptr!=NULL)
    {
        printf("%d ", ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
    Node *head = NULL;
    for(int i = 10; i <=20 ; i+=5)
    {
        head = append(head, i); 
    }
    for(int i = 5; i >= -20 ; i-=5)
    {
        head = prepend(head, i);
    }
    display(head);
}
