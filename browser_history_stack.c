#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int pageID[MAX_SIZE];
    int top;
} Stack;

// Initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Check if stack is full
int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Get the size of the stack
int size(Stack *s) {
    return s->top + 1;
}

// Push a page ID onto the stack
void push(Stack *s, int pageID) {
    if (isFull(s)) {
        printf("ERROR: History is full! Cannot push page ID %d\n", pageID);
        return;
    }
    s->pageID[++s->top] = pageID;
    printf("Opened Page: %d (Stack size: %d)\n", pageID, size(s));
}

// Pop the top page ID from the stack
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

// Peek at the current page without removing it
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("ERROR: No pages in history!\n");
        return -1;
    }
    return s->pageID[s->top];
}

// Display the entire history
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

    // Sample Use Case: Open pages 101, 102, 103
    printf("--- Opening Pages ---\n");
    push(&browserStack, 101);
    push(&browserStack, 102);
    push(&browserStack, 103);

    displayHistory(&browserStack);

    // Display current page
    printf("Current Page: %d\n", peek(&browserStack));
    printf("Total pages in history: %d\n\n", size(&browserStack));

    // User clicks Back button
    printf("--- Back Button Pressed ---\n");
    pop(&browserStack);

    displayHistory(&browserStack);

    // Display current page after back
    printf("Current Page: %d\n", peek(&browserStack));
    printf("Total pages in history: %d\n\n", size(&browserStack));

    // Additional operations
    printf("--- Additional Operations ---\n");
    pop(&browserStack);
    displayHistory(&browserStack);

    printf("Current Page: %d\n", peek(&browserStack));

    // Try to go back when only one page left
    pop(&browserStack);
    printf("Is history empty? %s\n", isEmpty(&browserStack) ? "YES" : "NO");

    // Try to pop from empty stack
    pop(&browserStack);

    return 0;
}
