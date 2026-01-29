#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    size_t size;
} LinkedList;

Node* NewNode(const int value){
    Node* node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

LinkedList* InitList(){
    LinkedList* list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void Push(LinkedList* self, Node* node){
    if (!self->head){
        self->head = node;
        self->tail = node;
    } else {
        self->tail->next = node;
        self->tail = node;
    }
    self->size++;
}
void PrintList(LinkedList* list){
    Node* current = list->head;
    printf("{\n");
    printf("size: %d\n", list->size);
    printf("items: [\n");
    int index = 0;
    while (current){
        printf(
            "{index: %d, value: %d}\n",
            index++,
            current->value
        );
        current = current->next;
    }
    printf("]\n");
}
int main(){
    LinkedList* list = InitList();
    for (int i = 0; i < 10; ++i){
        Node* node = NewNode(i);
        Push(list, node);
    }
    PrintList(list);
    return 0;
}
