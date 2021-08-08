#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int key;
    struct Node *next;
}Node;

Node* getNewNode(int key) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    if (!new_node) {
        printf("getNewNode: Malloc failed");
        exit(0);
    }
    new_node->key = key; 
    new_node->next = NULL;

    return new_node;
}

void insertAtBack(Node **head, int key) {
    
    if (!head) {
        printf("No reference to a list");
        return;
    }
    
    if (!*head) {
        Node *new_node = getNewNode(key);
        *head = new_node;
    }
    else {
        Node *ptr = *head;

        while (ptr->next)
            ptr = ptr->next;

        ptr->next = getNewNode(key);
    }

    return;
}

void insertAtFront(Node **head, int key) {

    if (!head) {
        printf("No reference to a list\n");
        return;
    }

    Node *new_node = getNewNode(key);
    new_node->next = *head;
    *head = new_node;
}

void delete(Node **head, int key) {

    if (!*head) {
        printf("List is empty\n");
        return;
    }

    Node *ptr = *head;
    Node *prev = NULL;
    while(ptr) {
        
        if (ptr->key == key) {
            printf("Key found, deleting it.: %d\n", key);

            if (prev)
                prev->next = ptr->next;
            else {
                free(ptr); 
                *head =NULL;
            }
            return;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    
    printf("Key not found\n");
    return;
}

void display(Node *head) {
    
    if (!head) {
        printf("List is empty\n");
        return;
    }

    Node *ptr = head;
    while(ptr) {
        printf("%d -> ", ptr->key);
        ptr = ptr->next;
    }
    printf("\n");

    return;
}

int main(int argc, char *argv[]) {
    
    Node *list = NULL;

    insertAtFront(NULL, 10);
    insertAtFront(&list, 10);
    display(list);
    delete(&list, 10);
    display(list);
    insertAtFront(&list, 20);
    display(list);
    insertAtFront(&list, 40);
    display(list);
    insertAtBack(&list, 30);
    display(list);
    return 0;
}

