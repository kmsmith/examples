#include <iostream>

using namespace std;

struct node {
    int value;
    struct node * next;
};

void insert(node* & head, int newValue) {
    node * newNode = new node();
    newNode->value = newValue;
    newNode->next = head;
    head = newNode;
}

void printList(node* head) {
    while (head) {
        cout << head->value << endl;
        head = head->next;
    }
}

void deleteList(node* head) {
    while (head) {
        node* temp = head;
        head = temp->next;
        delete temp;
    }
}

void reverseList(node* & head) {
    node* prev = NULL;
    while (head) {
        node* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    head = prev;
}

int main() {
    node * head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    printList(head);
    reverseList(head);
    printList(head);
    deleteList(head);
    return 0;
}
