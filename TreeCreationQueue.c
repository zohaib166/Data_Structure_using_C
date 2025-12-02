#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
} Node;

typedef struct queue 
{
    int front;
    int rear;
    Node *arr[SIZE];
} queue;

void init(queue *s)
{
    s->front = -1;
    s->rear = -1;
}

void enqueue(queue *s, Node *num)
{
    if(s->rear == SIZE-1) {
        printf("\nQueue is full\n");
        return;
    }
    
    s->arr[++s->rear] = num;
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
    if(s->front==s->rear) {
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
    queue q;
    init(&q);
    printf("Enter the value of root (-1 for no data): ");
    int num;
    scanf("%d", &num);
    if(num == -1) {
        return NULL;
    }
    Node *n = createNode(num);
    enqueue(&q, n);
    while(!isEmpty(&q)) {
        Node *temp = get_front(&q);
        dequeue(&q);

        printf("Enter the value for left child of %d: ", temp->data);
        scanf("%d", &num);
        if(num != -1) {
            Node *n = createNode(num);
            enqueue(&q, n);
            temp->left = n;
        }

        printf("Enter the value for right child of %d: ", temp->data);
        scanf("%d", &num);
        if(num != -1) {
            Node *n = createNode(num);
            enqueue(&q, n);
            temp->right = n;
        }
    }
    return n;
}

void preorder(Node *ptr) {
    if(ptr!=NULL) {
        printf("%d ", ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

int main()
{
    Node *root = createTree();
    preorder(root);
}