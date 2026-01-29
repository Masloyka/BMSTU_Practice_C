#include <stdio.h>

typedef struct Node{
    int value;
    struct Node* next;
}Node;
typedef struct {
    Node* head;
}SimpleLinkedList;

// Односвязанные линейные списки
int main(){
    Node second = {2, NULL};
    Node first = {1, &second};
    Node head = {0, &first};
    SimpleLinkedList list = {&head};
    return 0;
}
