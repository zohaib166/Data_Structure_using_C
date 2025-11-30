#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct node {
    struct node *left;
    int data;
    struct node *right;
} Node;

typedef struct queue 
{
    int front;
    int rear;
    Node* arr[SIZE];
} queue;

void init(queue *s)
{
    s->front = -1;
    s->rear = -1;
}

void enqueue(queue *s, Node *n)
{
    if(s->rear == SIZE-1) {
        printf("\nQueue is full\n");
        return;
    }
    
    s->arr[++s->rear] = n;
}

void dequeue(queue *s)
{
    if(s->rear == s->front & s->rear != SIZE-1) {
        printf("\nQueue is empty\n");
        return;
    }
    s->front++;
}

Node* get_front(queue *s) {
    if(s->front!=s->rear) {
        return s->arr[(s->front)+1];
    }
    return NULL;
}

Node* get_rear(queue *s) {
    if(s->front!=s->rear) {
        return s->arr[s->rear];
    }
    return NULL;
}

int isEmpty(queue *s) {
    if(s->rear == s->front & s->rear != SIZE-1) {
        return 1;
    }
    return 0;
}

Node *createNode(int data) {
    Node *n = (Node*) malloc(sizeof(Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Node *createTree() {
    Node *root = NULL;
    printf("Enter the data for root node: ");
    int num;
    scanf("%d", &num);
    root = createNode(num);
    queue q;
    init(&q);
    enqueue(&q,root);

    while(!isEmpty(&q)) {
        Node *ptr = get_front(&q);
        dequeue(&q);
        printf("Enter the left child of %d: ", ptr->data);
        scanf("%d", &num);
        if(num!=-1) {
            Node *n = createNode(num);
            ptr->left = n;
            enqueue(&q,n);
        }
        printf("Enter the right child of %d: ", ptr->data);
        scanf("%d", &num);
        if(num!=-1) {
            Node *n = createNode(num);
            ptr->right = n;
            enqueue(&q,n);
        }
    }
    return root;
}

void inorder(Node *p) {
    if(p) {
        inorder(p->left);
        printf("%d ", p->data);
        inorder(p->right);
    }
}

int main()
{
    Node *root = NULL;
    root = createTree();

    inorder(root);
    printf("\n");
}