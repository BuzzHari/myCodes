#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int value;
    Node *next;
};

Node* getNewNode(int value) {

    Node *new_node = (Node*) malloc(sizeof(Node));
    if (!new_node) {
        printf("getNewNode: Malloc error\n");
        exit(0);
    }

    new_node->value = value;
    new_node->next = NULL;

    return new_node;
}

void push(Node **top, int value) {

    if (!top) {
        printf("No valid refernce to a stack node\n");
        return;
    }

    Node *new_node = getNewNode(value);
    new_node->next = *top;
    *top = new_node;
}

int pop(Node **top) {
    
    if (!top) {
        printf("No valid reference to a stack node\n");
        return INT_MIN;
    }

    if (!*top) {
        printf("Stack is empty.\n");
        return INT_MIN;
    }

    Node *popped = *top;
    *top = (*top)->next;

    int popped_value = popped->value;
    free(popped);

    return popped_value;
}

int peek(Node *top) {

    if (!top) {
        printf("Stack is empty.\n");
        return INT_MIN;
    }

    return top->value;
}

int main(int argc, char *argv[]) {

    Node *stack;

    push(&stack, 10);
    printf("Peek: %d\n", peek(stack));
    push(&stack, 20);
    printf("Peek: %d\n", peek(stack));
    push(&stack, 30);
    printf("Peek: %d\n", peek(stack));
    push(&stack, 40);
    printf("Peek: %d\n", peek(stack));

    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));

    printf("Peek: %d\n", peek(stack));

    push(&stack, 50);

    printf("Peek: %d\n", peek(stack));

    return 0;
}
