#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;    
} Node;

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

void display(Node *head)
{
    Node* ptr = head;
    while(ptr!=NULL)
    {
        printf("%d ", ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}


Node *add(int num1[], int len1, int num2[], int len2)
{
    //len1 >= len2 always
    int len3 = len1+1;
    int num3[len3];
    //printf("%d\n", len3);
    int carry = 0;
    int i;
    for(i=0; i<len2; i++)
    {
        int temp;
        temp = num1[i] + num2[i] + carry;
        if(temp > 9) {
            carry = 1;
            num3[i] = temp%10;
        } else {
            carry = 0;
            num3[i] = temp;
        }
    }
    
    for(; i<len1; i++) {
        int temp;
        temp = num1[i] + carry;
        if(temp > 9) {
            carry = 1;
            num3[i] = temp%10;
        } else {
            carry = 0;
            num3[i] = temp;
        }
    }

    if(carry == 1)
        num3[i] = carry;
    else
        len3--;
    
    Node *head = NULL;
    for(int i=0; i < len3; i++) {
        head = append(head, num3[i]);
    }
    return head;
}

int main()
{
    int l1[] = {2,4,3}; //342
    int size1 = sizeof(l1)/sizeof(l1[0]);
    int l2[] = {5,6,4}; //465
    int size2 = sizeof(l2)/sizeof(l2[0]);
    // 342 + 465 = 807
    Node *head = NULL;
    if(size1 >= size2)
        head = add(l1, size1, l2, size2);
    else
        head = add(l2, size2, l1, size1);

    display(head);

}