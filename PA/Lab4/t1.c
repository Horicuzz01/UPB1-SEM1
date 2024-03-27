#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* mergeLists(Node* list1, Node* list2) {
    Node* mergedList = NULL;
    Node* tail = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            if (mergedList == NULL) {
                mergedList = tail = list1;
            } else {
                tail->next = list1;
                tail = tail->next;
            }
            list1 = list1->next;
        } else {
            if (mergedList == NULL) {
                mergedList = tail = list2;
            } else {
                tail->next = list2;
                tail = tail->finext;
            }
            list2 = list2->next;
        }
    }

    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    return mergedList;
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Create two example lists
    Node* list1 = (Node*)malloc(sizeof(Node));
    Node* list2 = (Node*)malloc(sizeof(Node));
    Node* node1 = (Node*)malloc(sizeof(Node));
    Node* node2 = (Node*)malloc(sizeof(Node));
    Node* node3 = (Node*)malloc(sizeof(Node));
    Node* node4 = (Node*)malloc(sizeof(Node));

    list1->data = 1;
    list1->next = node1;
    node1->data = 3;
    node1->next = node3;
    node3->data = 5;
    node3->next = NULL;

    list2->data = 2;
    list2->next = node2;
    node2->data = 4;
    node2->next = node4;
    node4->data = 6;
    node4->next = NULL;

    // Merge the lists
    Node* mergedList = mergeLists(list1, list2);

    // Print the merged list
    printList(mergedList);

    // Clean up memory
    free(list1);
    free(list2);
    free(node1);
    free(node2);
    free(node3);
    free(node4);

    return 0;
}