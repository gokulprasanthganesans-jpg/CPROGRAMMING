#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node *left;
    struct node *right;
};

struct node* create(char data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    struct node* root = create('*');
    root->left = create('+');
    root->right = create('c');
    root->left->left = create('a');
    root->left->right = create('b');

    preorder(root);
    return 0;
}