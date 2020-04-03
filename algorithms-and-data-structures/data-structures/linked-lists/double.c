#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    int data; // could be a struct to hold more data
    struct node_t *prev;
    struct node_t *next;
} node_t;

node_t *head = NULL;

void insertNode(int pos, int data) {
    node_t *node = malloc(sizeof(node_t) * 1);
    node->data = data;
    node->prev = NULL;
    node->next = NULL;

    // handle case where list is empty
    if (head == NULL) {
        head = node;
        return;
    }

    int idx = 0;

    node_t *prev = NULL;
    node_t *cur = head;

    // walk through list until pos or end is reached
    while (cur != NULL && idx != pos) {
        ++idx;
        prev = cur;
        cur = cur->next;
    }

    // insertion point reached

    // beginning, includes head update
    if (idx == 0) {
        head = node;
        node->next = cur;
        cur->prev = node;
        return;
    }

    // end
    if (cur == NULL) {
        prev->next = node;
        node->prev = prev;
        return;
    }

    // middle
    prev->next = node;
    node->prev = prev;
    node->next = cur;
    cur->prev = node;
}

void addAtBeginning(int data) {
    insertNode(0, data);
}

void addAtEnd(int data) {
    insertNode(-1, data);
}

void removeNode(int data) {
    node_t *cur = head;

    while (cur != NULL && cur->data != data) {
        cur = cur->next;
    }

    // null cur means no match, do nothing
    if (cur == NULL) {
        return;
    }

    // handle first item
    if (cur->prev == NULL) {
        if (cur->next == NULL) {
            // only item?
            head = NULL;
        } else {
            // more items?
            head = cur->next;
            head->prev = NULL;
        }

        free(cur);
        return;
    }

    // handle last item
    if (cur->next == NULL) {
        cur->prev->next = NULL;

        free(cur);
        return;
    }

    // handle middle item
    if (cur->prev != NULL && cur->next != NULL) {
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;

        free(cur);
        return;
    }
}

void printList() {
    node_t *temp = head;

    printf(" --------- list --------\n");
    while (temp != NULL) {
        printf("\tdata: %d\n", temp->data);
        temp = temp->next;
    }
    printf(" -----------------------\n");
}

void printListReverse() {
    node_t *temp = head;

    // seek to the end
    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf(" -------- reverse list -------\n");

    while (temp != NULL) {
        printf("\tdata: %d\n", temp->data);
        temp = temp->prev;
    }
    printf(" -----------------------------\n");
}

int main(int argc, char **argv) {
    addAtEnd(2);
    addAtEnd(3);
    addAtEnd(5);
    addAtBeginning(1);
    insertNode(2, 4);

    printf("Forward :\n");
    printList();

    removeNode(1);
    removeNode(3);
    removeNode(5);

    printf("Reverse:\n");
    printListReverse();

    return 0;
}