#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int val;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node Node;

struct Queue {
    Node *front;
    Node *rear;
};

typedef struct Queue Queue;


Queue *createQueue();
int isEmpty(Queue *queue);
void enQueue(Queue *queue, int data);
int deQueue(Queue *queue);
int deQueueRear(Queue *queue);
void enQueueFront(Queue *queue, int data);
