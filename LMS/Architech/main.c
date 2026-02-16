#include <stdlib.h>
#include <stdio.h>

#include "linked_list.h"

int main(){
    int size = 0;
    scanf("%d", &size);
    LinkedList* list = InitList();
    for (int i = 0; i < size; ++i){
        int value = 0;
        scanf("%d", &value);
        Node* node = NewNode(value);
        PushBack(list, node);
    }
    PrintList(list);
    FreeList(list);
    free(list);

    return 0;
}