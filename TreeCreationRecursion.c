#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

void inorder(Node *p) {
    if(p) {
        inorder(p->left);
        printf("%d ", p->data);
        inorder(p->right);
    }
}
Node *createTree()
{
    Node *n = (Node*) malloc(sizeof(Node));
    printf("Enter data, (-1 for no data)\n");
    int num;
    scanf("%d", &num);
    if(num == -1) {
        return NULL;
    }
    n->data = num;
    printf("Enter the left child of %d: ", num);
    n->left = createTree();
    printf("Enter the right child of %d: ", num);
    n->right = createTree();

    return n;
}

int main ()
{
    Node *root = NULL;
    root = createTree();

    inorder(root);
    printf("\n");
}
