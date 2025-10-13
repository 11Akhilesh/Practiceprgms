#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} Queue;

static Queue *queue_create(void) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (!queue) {
        return NULL;
    }
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

static void queue_push(Queue *queue, int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (!node) {
        return;
    }
    node->value = value;
    node->next = NULL;
    if (!queue->tail) {
        queue->head = node;
        queue->tail = node;
    } else {
        queue->tail->next = node;
        queue->tail = node;
    }
}

static int queue_pop(Queue *queue, int *out_value) {
    if (!queue->head) {
        return 0;
    }
    Node *node = queue->head;
    *out_value = node->value;
    queue->head = node->next;
    if (!queue->head) {
        queue->tail = NULL;
    }
    free(node);
    return 1;
}

static void queue_destroy(Queue *queue) {
    Node *node = queue->head;
    while (node) {
        Node *next = node->next;
        free(node);
        node = next;
    }
    free(queue);
}

int main(void) {
    Queue *queue = queue_create();
    if (!queue) {
        return 1;
    }
    for (int i = 0; i < 5; ++i) {
        queue_push(queue, i * 10);
    }
    int value;
    while (queue_pop(queue, &value)) {
        printf("Popped %d
", value);
    }
    queue_destroy(queue);
    return 0;
}
