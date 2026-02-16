#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node{
    int value;
    struct Node* next;
}Node;

typedef struct{
    Node* head;
    Node* tail;
    size_t size;
}LinkedList;

LinkedList* InitList(){
    LinkedList* list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

Node* NewNode(int value){
    Node* node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

void PushBack(LinkedList* self, Node* node){
    if (!self->head){
        self->head = node;
        self->tail = node;
    } else{
        self->tail->next = node;
        self->tail = node;
    }
    self->size++;
}

void PushFront(LinkedList* self, Node* node){
    if (!self->head){
        self->head = node;
        self->tail = node;
        node->next = NULL;
    } else{
        node->next = self->head;
        self->head = node;
    }
    self->size++;
}

void InsertAt(LinkedList* self, Node* node, size_t index){
    if (self->size < index){
        return;
    }
    if (index == 0){
        PushFront(self, node);
        return;
    }
    if (index == self->size){
        PushBack(self, node);
        return;
    }

    Node* current = self->head;
    for (size_t i = 0; i < index - 1; ++i){
        current = current->next;
    }
    node->next = current->next;
    current->next = node;
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

void FreeList(LinkedList* self) {
    // Реализуйте функцию очистки данных списка самостоятельно
    Node* next_address;
    for (size_t i = 0; i < self->size; ++i){
        next_address = self->head->next;
        free(self->head);
        self->head = next_address;
    }
    self->head = NULL;
    self->tail = NULL;
    self->size = 0;
}

void RemoveAt(LinkedList* self, size_t index){
    if (self->size <= index || self->size == 0){
        return;
    }

    if (index == 0){
        Node* old_head = self->head;
        self->head = old_head->next;
        if (self->size == 1){
            self->tail == NULL;
        }
        free(old_head);
        self->size--;
        return;
    }
}
void TestSimpleWork(){
    LinkedList* list = InitList();
    assert(list->size == 0 && !list->head && !list->tail);
    for (int i = 0; i < 10; ++i){
            Node* node = NewNode(i*10);
            assert(node->value == i * 10);
            assert(!node->next);
            if (i % 2 == 0){
                PushBack(list, node);
            } else {
                PushFront(list, node);
            }
            assert(list->size == i + 1);
        }
    FreeList(list);
    assert(list->size == 0 && !list->head && !list->tail);
    free(list);
    printf("[TEST#1] PASS\n");
    }
int main(){
    LinkedList* list = InitList();
    // for (int i = 0; i < 10; ++i){
    //     Node* node = NewNode(i*10);
    //     if (i % 2 == 0){
    //         PushBack(list, node);
    //     } else {
    //         PushFront(list, node);
    //     }
    // }
    Node* node = NewNode(54);
    InsertAt(list, node, 0);
    PrintList(list);
    RemoveAt(list, 0);
    PrintList(list);
    FreeList(list);
    free(list);
    TestSimpleWork();
    return 0;
}