/** 
 * Doubly_Linked_List.c
 * Implementation of a Doubly Linked List in C
 **/

#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    struct Node* next;
    int data;
    struct Node* prev;    
} Node;

Node *createNode(int data)
{
    Node *n = (Node*) malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

Node *prepend(Node *head, int data)
{
    //Create a new node
    Node *n = createNode(data);
    //if this node is the first node of the linked list
    if(head==NULL)
    {
        head = n;
        return head;
    }
    n->next = head;
    head->prev = n;
    head = n;
    return head;
}

Node *insertAtPosition(Node *head, int data, int position)
{
    //Create a new node
    Node *n = createNode(data);

    //If the linked list is empty or position is 0, make the new node as head
    if(head==NULL || position==0)
    {
        n->next = head;
        if(head != NULL) {
            head->prev = n;
        }
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
    n->prev = ptr;
    if(ptr->next != NULL) {
        ptr->next->prev = n;
    }
    ptr->next = n;

    return head;
}

//Append function adds a new node at the end of the Doubly Linked List
Node *append(Node *head, int data)
{
    //Create a new node
    Node *n = createNode(data);
    //If the linked list is empty
    if(head==NULL)
    {
        head = n;
        return head;
    }
    Node *ptr = head;
    //Traverse to the last node
    while(ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    //Append the new node at the end
    ptr->next = n;
    n->prev = ptr;
    return head;
}   

//Code to display the Doubly Linked List in forward direction
void displayForward(Node *head)
{
    Node *ptr = head;
    while(ptr!=NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    Node *head = NULL;
    head = append(head, 10);
    head = append(head, 20);
    head = prepend(head, 5);
    head = insertAtPosition(head, 15, 2);
    displayForward(head);
    return 0;
}