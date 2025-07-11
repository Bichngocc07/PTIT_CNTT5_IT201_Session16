//
// Created by Owner on 7/11/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q != NULL) {
        q->front = NULL;
        q->rear = NULL;
    }
    return q;
}

int isEmpty(Queue* q) {
    return (q->front == NULL);
}

int main() {
    Queue* q = createQueue();
    if (q != NULL && isEmpty(q)) {
        printf("Hang doi da duoc khoi tao thanh cong va dang rong.\n");
    } else {
        printf("Co loi khi khoi tao hang doi.\n");
    }
    free(q);
    return 0;
}
