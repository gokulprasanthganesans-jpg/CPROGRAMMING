#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct OrderNode {
    char orderID[10];
    struct OrderNode* next;
} OrderNode;
typedef struct {
    OrderNode *front;
    OrderNode *rear;
    int count;
} OrderQueue;
void initQueue(OrderQueue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
}
int isEmpty(OrderQueue* q) {
    return q->count == 0;
}
void enqueue(OrderQueue* q, char id[]) {
    OrderNode* newNode = (OrderNode*)malloc(sizeof(OrderNode));
    if (newNode == NULL) {
        printf("System Error: Could not allocate memory for order.\n");
        return;
    }
    strcpy(newNode->orderID, id);
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->count++;
    printf("Order placed: %s\n", id);
}

void dequeue(OrderQueue* q) {
    if (isEmpty(q)) {
        printf("No pending orders to process.\n");
        return;
    }
    OrderNode* temp = q->front;
    printf("Order processed → %s\n", temp->orderID);
    
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp); 
    q->count--;
}
void front(OrderQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Next order → %s\n", q->front->orderID);
    }
}
int main() {
    OrderQueue q;
    initQueue(&q);
    enqueue(&q, "O101");
    enqueue(&q, "O102");
    enqueue(&q, "O103");
    dequeue(&q);    
    front(&q);    
    printf("Pending orders: %d\n", q.count);
    return 0;
}