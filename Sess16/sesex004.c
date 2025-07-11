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

Node* createNode() {
    int x;
    printf("Nhap so nguyen: ");
    scanf("%d", &x);
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->data = x;
        newNode->next = NULL;
    }
    return newNode;
}

void enqueue(Queue* q) {
    Node* newNode = createNode();
    if (newNode == NULL) return;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int peekFrontValue(Queue* q) {
    if (isEmpty(q)) {
        printf("empty queue\n");
        return -1;
    } else {
        return q->front->data;
    }
}

void printQueue(Queue* q) {
    Node* temp = q->front;
    printf("Queue: front->");
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Queue* q = createQueue();
    int value = peekFrontValue(q);
    if (value != -1) printf("%d\n", value);
    enqueue(q);
    enqueue(q);
    enqueue(q);
    printQueue(q);
    value = peekFrontValue(q);
    if (value != -1) printf("%d\n", value);
    free(q);
    return 0;
}
