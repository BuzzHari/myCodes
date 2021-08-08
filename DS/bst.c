#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Bstree Bstree;

struct Node {
    int key;
    Node *left;
    Node *right;
};

struct Bstree {
    int num_of_node;
    Node *root;
};

Node* getNewNode(int key) {
    
    Node *new_node = (Node*) malloc(sizeof(Node));
    if (!new_node) {
        printf("getNewNode: Malloc failed\n");
        exit(0);
    }
    
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

Node* insert_recur_utill(Node *root, int key) {

    if (!root) {
        return getNewNode(key);
    }

    if (key < root->key) {
        root->left = insert_recur_utill(root->left, key);
    }
    else if (key > root->key) {
        root->right = insert_recur_utill(root->right, key);
    }

    return root;
}

void insert_recur(Bstree *bst, int key) {

    if (!bst) {
        printf ("Tree doesn't exist\n");
        return;
    }

    if (!bst->root) {
        bst->root = getNewNode(key);
        return;
    }

    insert_recur_utill(bst->root, key);
    
    return;
} 

void insert_iterative(Bstree *bst, int key) {

    if (!bst) {
        printf ("Tree doesn't exist\n");
        return;
    }

    Node **ptr = &bst->root;

    while(*ptr) {
        if (key < (*ptr)->key)
            ptr = &(*ptr)->left;
        else if (key > (*ptr)->key)
            ptr = &(*ptr)->right;
        else {
            printf("Inserting Duplicate\n");
            return;
        }
    }
    *ptr = getNewNode(key);
    bst->num_of_node += 1;

    return;
}

Node *getMaxLeft(Node *root) {

    if (root->right)
        return getMaxLeft(root->right);
    return root;
}

Node* delete_recur_utill(Node *root, int key) {
   
    if (!root)
        return root;

    if (key < root->key)
       root->left = delete_recur_utill(root->left, key);
    else if (key > root->key)
        root->right = delete_recur_utill(root->right, key);
    else {
        
        Node *temp;
        // Case 1: leaf node.
        if (!root->left && !root->right)  {
            temp = root;
            root = NULL;
            free(temp);
        }
        // Case 2: Only left child.
        else if (root->left && !root->right) {
            temp = root;
            root = root->right;
            free(temp);
        }
        // Case 3: Only right child.
        else if (root->right && !root->left) {
            temp = root;
            root = root->left;
            free(temp);
        } 
        // Case 4: Both left child and rigth child.
        else if (root->right && root->left) {
            temp = getMaxLeft(root->left);
            root->key = temp->key;
            root->left = delete_recur_utill(root->left, temp->key);
        }

    }

    return root;

}

void delete_recur(Bstree *bst, int key) {

    if (!bst) {
        printf ("Tree doesn't exist\n");
        return;
    }

    if (!bst->root) {
        printf("Tree is empty\n");
    }

    delete_recur_utill(bst->root, key);

    return;
}

void inorder(Node *root) {

    if (root) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

Bstree* newTree() {

    Bstree *new_tree = (Bstree*) malloc(sizeof(Bstree));
    new_tree->num_of_node = 0;
    new_tree->root = NULL;

    return new_tree;
}

int main(int argc, char *argv[]) {
    
    Bstree *tree = newTree();

    insert_iterative(tree, 50);
    insert_iterative(tree, 30);
    insert_iterative(tree, 70);
    insert_iterative(tree, 20);
    insert_iterative(tree, 40);
    insert_iterative(tree, 60);
    insert_iterative(tree, 80);

    inorder(tree->root);
    printf("\n");

    delete_recur(tree, 50);

    inorder(tree->root);
    printf("\n");

}
