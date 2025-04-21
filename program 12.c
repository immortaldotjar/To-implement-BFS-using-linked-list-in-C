#include <stdio.h>
#include <stdlib.h>

// node for tree
struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue Node for BFS
struct QueueNode 
{
    struct Node* treeNode;
    struct QueueNode* next;
};

// Queue structure using linked list
struct Queue 
{
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Function to create a new tree node
struct Node* createTreeNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create an empty queue
struct Queue* createQueue() 
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// insertion in tree 
void enqueue(struct Queue* q, struct Node* node) 
{
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->treeNode = node;
    temp->next = NULL;

    if (q->rear == NULL) 
    {
        q->front = q->rear = temp;
        return;
    }
    else
    {
        q->rear->next = temp;
        q->rear = temp;
    }
}

// deletion in the tree
struct Node* dequeue(struct Queue* q) 
{
    if (q->front == NULL)
    {
        return NULL;
    }
    else
    {
        struct QueueNode* temp = q->front;
        struct Node* node = temp->treeNode;
        q->front = q->front->next;

        if (q->front == NULL)
        {
            q->rear = NULL;
        }
        free(temp);
        return node;
    }
}

// BFS Traversal (Level Order)
void bfsTraversal(struct Node* root) 
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        struct Queue* q = createQueue();
        enqueue(q, root);

        while (q->front != NULL) 
        {
            struct Node* current = dequeue(q);
            printf("%d\t", current->data);

            if(current->left)
            {
                enqueue(q, current->left);
            }
            if(current->right)
            {
                enqueue(q, current->right);
            }
        }
    }
}

// Main function
int main() 
{
    struct Node* root = createTreeNode(1);
    root->left = createTreeNode(2);
    root->right = createTreeNode(3);
    root->left->left = createTreeNode(4);
    root->left->right = createTreeNode(5);
    root->right->left = createTreeNode(6);
    root->right->right = createTreeNode(7);

    printf("Breadth-First Search (Level Order) Traversal : \n");
    bfsTraversal(root);
    printf("\n");

    return 0;
}
