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

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("queue is empty\n");
        return;
    }
    Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
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
    dequeue(q);
    enqueue(q);
    enqueue(q);
    enqueue(q);
    printQueue(q);
    dequeue(q);
    printQueue(q);
    free(q);
    return 0;
}
