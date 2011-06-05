#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node * next;
};

struct node * get_new_node(int new_value) {
    struct node * new_node = malloc(sizeof(struct node));
    if (new_node) {
        new_node->value = new_value;
        new_node->next = NULL;
    }
    return new_node;
}

struct node * insert_node(struct node * head, struct node * new_node) {
    if (new_node) {
        new_node->next = head;
        return new_node;
    }
    return head;
}

void print_list(struct node* head) {
    while (head) {
        printf("%d\n", head->value);
        head = head->next;
    }
}

void delete_list(struct node* head) {
    struct node * temp = NULL;
    while (head) {
        temp = head;
        head = temp->next;
        free(temp);
    }
}

struct node * reverse_list(struct node* head) {
    struct node * prev = NULL;
    struct node * next = NULL;
    while (head) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

int main() {
    struct node * list = NULL;
    list = insert_node(list, get_new_node(1));
    list = insert_node(list, get_new_node(2));
    list = insert_node(list, get_new_node(3));
    print_list(list);
    list = reverse_list(list);
    print_list(list);
    delete_list(list);
    return 0;
}
