#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Person {
    char name[50];
    struct Person *parent;
    struct Person *child1;
    struct Person *child2;
};


struct Person* createPerson(const char* name) {
    struct Person* newPerson = (struct Person*)malloc(sizeof(struct Person));
    if (newPerson == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strncpy(newPerson->name, name, 49);
    newPerson->name[49] = '\0';
    newPerson->parent = NULL;
    newPerson->child1 = NULL;
    newPerson->child2 = NULL;
    return newPerson;
}

int main() {
    
    struct Person* grandparent = createPerson("John");
    struct Person* parent1 = createPerson("Parent1");
    struct Person* parent2 = createPerson("Parent2");
    struct Person* child1 = createPerson("Child1");
    struct Person* child2 = createPerson("Child2");


    grandparent->child1 = parent1;
    parent1->parent = grandparent;
    grandparent->child2 = parent2;
    parent2->parent = grandparent;

    parent1->child1 = child1;
    child1->parent = parent1;
    parent1->child2 = child2;
    child2->parent = parent1;

    
    printf("Grandparent: %s\n", grandparent->name);
    printf("First child: %s\n", grandparent->child1->name);
    printf("Second grandchild of first child: %s\n", grandparent->child1->child2->name);

    
    free(grandparent->child1->child1);
    free(grandparent->child1->child2);
    free(grandparent->child1);
    free(grandparent->child2);
    free(grandparent);

    return 0;
}