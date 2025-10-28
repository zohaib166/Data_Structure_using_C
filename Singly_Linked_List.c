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

Node *insertAtPosition(Node *head, int data, int position)
{
    //Create a new node
    Node *n = (Node*) malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;

    //If the linked list is empty or position is 0, make the new node as head
    if(head==NULL || position==0)
    {
        n->next = head;
        head = n;
        return head;
    }

    Node *ptr = head;
    //Traverse to the node just before the desired position
    for(int i=0; i<position-1 && ptr!=NULL; i++)
    {
        ptr = ptr->next;
    }
    //If ptr is NULL, it means position is greater than the length of the linked list
    if(ptr==NULL)
    {
        printf("Position out of bounds\n");
        free(n);
        return head;
    }
    //Insert the new node at the desired position
    n->next = ptr->next;
    ptr->next = n;

    return head;
}

Node *deleteAtEnd(Node *head)
{
    //If the linked list is empty
    if(head==NULL)
    {
        printf("Linked List is empty\n");
        return head;
    }
    //If the linked list has only one node
    if(head->next==NULL)
    {
        free(head);
        head = NULL;
        return head;
    }
    Node *ptr = head;
    //Traverse to the second last node
    while(ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    //Free the last node and set the next of second last node to NULL
    free(ptr->next);
    ptr->next = NULL;

    return head;
}

Node* deleteAtPosition(Node *head, int position)
{
    //If the linked list is empty
    if(head==NULL)
    {
        printf("Linked List is empty\n");
        return head;
    }
    //If the position is 0, delete the head node
    if(position==0)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node *ptr = head;
    //Traverse to the node just before the desired position
    for(int i=0; i<position-1 && ptr!=NULL; i++)
    {
        ptr = ptr->next;
    }
    //If ptr is NULL or ptr->next is NULL, it means position is out of bounds
    if(ptr==NULL || ptr->next==NULL)
    {
        printf("Position out of bounds\n");
        return head;
    }
    //Delete the node at the desired position
    Node *temp = ptr->next;
    ptr->next = ptr->next->next;
    free(temp);

    return head;
}

Node *deleteAtbeginning(Node *head)
{
    //If the linked list is empty
    if(head==NULL)
    {
        printf("Linked List is empty\n");
        return head;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
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

    head = insertAtPosition(head, 99, 4);
    display(head);
}
