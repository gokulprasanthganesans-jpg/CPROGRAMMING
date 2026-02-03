#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int pageID[MAX_SIZE];
    int top;
} Stack;


void initStack(Stack *s) {
    s->top = -1;
}


int isEmpty(Stack *s) {
    return s->top == -1;
}


int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}


int size(Stack *s) {
    return s->top + 1;
}


void push(Stack *s, int pageID) {
    if (isFull(s)) {
        printf("ERROR: History is full! Cannot push page ID %d\n", pageID);
        return;
    }
    s->pageID[++s->top] = pageID;
    printf("Opened Page: %d (Stack size: %d)\n", pageID, size(s));
}


int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("ERROR: No pages to go back to!\n");
        return -1;
    }
    int pageID = s->pageID[s->top];
    s->top--;
    printf("Back button pressed - Closed Page: %d (Stack size: %d)\n", pageID, size(s));
    return pageID;
}


int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("ERROR: No pages in history!\n");
        return -1;
    }
    return s->pageID[s->top];
}


void displayHistory(Stack *s) {
    if (isEmpty(s)) {
        printf("History is empty!\n");
        return;
    }
    printf("\nBrowser History (from current to oldest):\n");
    for (int i = s->top; i >= 0; i--) {
        if (i == s->top) {
            printf("-> %d (Current Page)\n", s->pageID[i]);
        } else {
            printf("   %d\n", s->pageID[i]);
        }
    }
    printf("\n");
}

int main() {
    Stack browserStack;
    initStack(&browserStack);

    printf("=== Browser History Stack Demo ===\n\n");

    
    printf("--- Opening Pages ---\n");
    push(&browserStack, 101);
    push(&browserStack, 102);
    push(&browserStack, 103);

    displayHistory(&browserStack);

    
    printf("Current Page: %d\n", peek(&browserStack));
    printf("Total pages in history: %d\n\n", size(&browserStack));

    
    printf("--- Back Button Pressed ---\n");
    pop(&browserStack);

    displayHistory(&browserStack);

    
    printf("Current Page: %d\n", peek(&browserStack));
    printf("Total pages in history: %d\n\n", size(&browserStack));

    
    printf("--- Additional Operations ---\n");
    pop(&browserStack);
    displayHistory(&browserStack);

    printf("Current Page: %d\n", peek(&browserStack));

    
    pop(&browserStack);
    printf("Is history empty? %s\n", isEmpty(&browserStack) ? "YES" : "NO");

    
    pop(&browserStack);

    return 0;
}
