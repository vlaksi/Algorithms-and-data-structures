#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    int data; // could be a struct to hold more data
    struct node_t *next;
} node_t;

node_t *head = NULL;

void insertNode(int pos, int data) {
    node_t *node = malloc(sizeof(node_t) * 1);
    node->data = data;
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
        return;
    }

    // end
    if (cur == NULL) {
        prev->next = node;
        return;
    }

    // middle
    prev->next = node;
    node->next = cur;
}

void addAtBeginning(int data) {
    insertNode(0, data);
}

void addAtEnd(int data) {
    insertNode(-1, data);
}

// we remove with that 'data'
void removeNode(int data) {
    node_t *prev = NULL;
    node_t *cur = head;

    while (cur != NULL && cur->data != data) {
        prev = cur;
        cur = cur->next;
    }

    // null cur means no match, do nothing
    if (cur == NULL) {
        return;
    }

    // handle first item
    if (prev == NULL) {
        if (cur->next == NULL) {
            // only item?
            head = NULL;
        } else {
            // more items?
            head = cur->next;
        }

        free(cur);
        return;
    }

    // handle last item
    if (cur->next == NULL) {
        prev->next = NULL;

        free(cur);
        return;
    }

    // handle middle item
    if (prev != NULL && cur->next != NULL) {
        prev->next = cur->next;

        free(cur);
        return;
    }
}

void printList() {
    node_t *temp = head;

    printf("\n -------- list ---------\n");
    while (temp != NULL) {
        printf("\tdata: %d\n", temp->data);
        temp = temp->next;
    }
    printf(" -----------------------\n");

}

int main(int argc, char **argv) {
    addAtBeginning(2);
    addAtBeginning(1);
    addAtEnd(3);
    insertNode(1,9);

    printList();

    // after we remove some data
    removeNode(9);
    printList();


    return 0;
}