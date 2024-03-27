#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node BILA;

BILA* createNode(int data) {
    BILA* newNode = (BILA*)malloc(sizeof(BILA));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void remove_specified_node(BILA **head, BILA *node) {
    if (*head == node) {
        *head = (*head)->next;
        free(node);
        return;
    }
    BILA *current = *head;
    while (current->next != node) {
        current = current->next;
    }
    current->next = node->next;
    free(node);
}

int main(){

    int nr_bile_rosii = 15;
    BILA* bile = createNode(1);
    BILA* p = bile;
    for (int i = 0; i < 14;i++){
        p->next = createNode(1);
        p = p->next;
    }

    for (int i = 2; i <= 7;i++)
    {
        p->next = createNode(i);
        p = p->next;
    }

    BILA *meci = NULL;
    p = bile;
    int a;

    printf("A cata bila rosie a fost extrasa? (1-&d)", nr_bile_rosii);
    scanf("%d", &a);
    for (int i = 0;i < a-1;i++){
       p = p->next;
    }
    meci = p;
    remove_specified_node(&bile, p);
    nr_bile_rosii--;

    
}
