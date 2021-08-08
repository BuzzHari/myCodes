#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node Node;
typedef struct Queue Queue;

struct Node {
    int value;
    Node *next;
    Node *prev;
};

struct Queue {
    int size;
    Node *head;
    Node *tail;
};

Node* getNewNode(int value) {

    Node *new_node = (Node*) malloc(sizeof(Node));
    if (!new_node) {
        printf("getNewNode: Malloc error\n");
        exit(0);
    }

    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

void pushFront(Queue *queue, int value) {

    if (!queue) {
        printf("Queue doesn't exist\n");
        return;
    }
    
    Node *new_node = getNewNode(value);

    new_node->next = queue->head;
    if (queue->head)
        queue->head->prev = new_node;
    else 
        queue->tail = new_node;
    queue->head = new_node;

    queue->size += 1;

    return;
}

void pushBack(Queue *queue, int value) {

    if (!queue) {
        printf("Queue doesn't exist\n");
        return;
    }

    Node *new_node = getNewNode(value);

    new_node->prev = queue->tail;
    if (queue->tail)
        queue->tail->next = new_node;
    else 
        queue->head = new_node;
    queue->tail = new_node;

    queue->size += 1;

    return;
}

void popFront(Queue *queue) {

    if (!queue) {
        printf("Queue doesn't exist\n");
        return;
    }
    
    if (!queue->head) {
        printf("Queue is empty\n");
        return;
    }

    if (queue->head == queue->tail) {
        free(queue->head);
        queue->head = NULL;
        queue->tail = NULL;
    }
    else {
        Node *popped = queue->head;
        queue->head = queue->head->next;
        queue->head->prev = NULL;

        free(popped);
    }
    queue->size -= 1;

    return;
}

void popBack(Queue *queue) {

    if (!queue) {
        printf("Queue doesn't exist\n");
        return;
    }
    
    if (!queue->head) {
        printf("Queue is empty\n");
        return;
    }

    if (queue->tail == queue->head) {
        free(queue->tail);
        queue->head = NULL;
        queue->tail = NULL;
    }
    else {
        Node *popped = queue->tail;
        queue->tail = queue->tail->prev;
        queue->tail->next = NULL;

        free(popped);
    }
    queue->size -= 1;

    return;
}

int front(Queue *queue) {

    if (!queue) {
        printf("Queue doesn't exist\n");
        return INT_MIN;
    }
    
    if (!queue->head) {
        printf("Queue is empty\n");
        return INT_MIN;
    }

    return queue->head->value;
}

int back(Queue *queue) {

    if (!queue) {
        printf("Queue doesn't exist\n");
        return INT_MIN;
    }
    
    if (!queue->tail) {
        printf("Queue is empty\n");
        return INT_MIN;
    }

    return queue->tail->value;
}

int isEmpty(Queue *queue) {

    if (!queue) {
        printf("Queue doesn't exist\n");
        return INT_MIN;
    }

    if (!queue->head) {
        printf("Queue is empty\n");
        return 1;
    }

    return 0;
}

int size(Queue *queue) {

    if (!queue) {
        printf("Queue doesn't exist\n");
        return INT_MIN;
    }

    return queue->size;
}

Queue* newQueue() {

    Queue *new_queue = (Queue*) malloc(sizeof(Queue));
    if (!new_queue) {
        printf("newQueue: Malloc failed\n");
        exit(0);
    }

    new_queue->size = 0;
    new_queue->head = NULL;
    new_queue->tail = NULL;

    return new_queue;
}

int main() {
    
    Queue *myQueue = newQueue();
    
    pushFront(myQueue, 10);
    printf("Front: %d\n", front(myQueue));
    printf("Back: %d\n", back(myQueue));

    popFront(myQueue);
    printf("Front: %d\n", front(myQueue));
    printf("Back: %d\n", back(myQueue));

    printf("Front: %d\n", front(myQueue));
    printf("Back: %d\n", back(myQueue));

    pushFront(myQueue, 10);
    printf("Front: %d\n", front(myQueue));
    printf("Back: %d\n", back(myQueue));
    pushFront(myQueue, 20);
    printf("Front: %d\n", front(myQueue));
    printf("Back: %d\n", back(myQueue));
    pushFront(myQueue, 30);
    printf("Front: %d\n", front(myQueue));
    printf("Back: %d\n", back(myQueue));

    pushBack(myQueue, 40);
    printf("Back: %d\n", back(myQueue));
    printf("Front: %d\n", front(myQueue));
    pushBack(myQueue, 50);
    printf("Back: %d\n", back(myQueue));
    printf("Front: %d\n", front(myQueue));
    pushBack(myQueue, 60);
    printf("Back: %d\n", back(myQueue));
    printf("Front: %d\n", front(myQueue));
    
    popFront(myQueue);
    printf("Front: %d\n", front(myQueue));
    printf("Back: %d\n", back(myQueue));
    popFront(myQueue);
    printf("Front: %d\n", front(myQueue));
    printf("Back: %d\n", back(myQueue));
    popFront(myQueue);
    printf("Front: %d\n", front(myQueue));
    printf("Back: %d\n", back(myQueue));
    popFront(myQueue);
    printf("Front: %d\n", front(myQueue));
    printf("Back: %d\n", back(myQueue));
    popFront(myQueue);
    printf("Front: %d\n", front(myQueue));
    printf("Back: %d\n", back(myQueue));
    popFront(myQueue);
    printf("Front: %d\n", front(myQueue));
    printf("Back: %d\n", back(myQueue));

    return 0;
}
