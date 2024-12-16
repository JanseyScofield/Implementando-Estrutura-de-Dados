#include <stdio.h>
#include <stdlib.h>

typedef struct mo Mo;

typedef struct mo{
    int value;
    Mo *next;
}Mo;

Mo* initList(int value);
void push(Mo **start, int value);
void deleteItem(Mo **start, int valueDelete);
void printList(Mo *start);

int main(){
    Mo *list = initList(10);
    printList(list);
    push(&list, 102);
    printList(list);
    push(&list, -231);
    printList(list);
    return 1;
}

Mo* initList(int value){
    Mo *mo = malloc(sizeof(Mo));
    mo->value = value;
    mo->next = NULL;
    return mo;
}

void push(Mo **start, int value){
    Mo *newMo = malloc(sizeof(Mo));
    newMo->value = value;
    newMo->next = (*start)-> next;
    (*start)-> next = newMo;
}

void deleteItem(Mo **start, int valueDelete){
    if(start == NULL){
        return;
    }

    Mo **temp = malloc(sizeof(Mo));
    temp = start;

    if((*start)->value == valueDelete){
        *start = (*start)->next;
        free(*temp);
        return;
    }

    Mo **tempAnt = malloc(sizeof(Mo));
    tempAnt = temp;
    *temp = (*temp)->next;

    while(temp != NULL){
        if((*temp)->value == valueDelete){
            (*tempAnt)->next = (*temp)->next;
            free(*temp);
            return;
        }
        tempAnt = temp;
        *temp = (*temp)->next;
    }
}

void printList(Mo *start){
    Mo *temp = malloc(sizeof(Mo));
    temp = start;
    printf("List:\n");
    while(temp != NULL){
        printf("%d ", temp->value);
        temp = temp->next;
    }
    free(temp);
}
