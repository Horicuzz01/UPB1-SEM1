#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct val
{
    int x;
    int y;
    int z;
};

typedef struct val VAL;

struct node
{
    VAL val;
    struct node *next;
};

typedef struct node Node;


int isEmpty(Node*top);
void deleteStack(Node**top);
VAL pop(Node**top);
void push(Node**top, VAL v);
VAL top(Node *top);
void printStack(Node* stack);

 

