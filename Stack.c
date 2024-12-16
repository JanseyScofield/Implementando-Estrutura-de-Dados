#include <stdio.h>
#include <stdlib.h>

typedef struct itemStack ItemStack;

typedef struct itemStack{
    ItemStack *next;
    int value;
}ItemStack;

ItemStack* initStack(int value);
void push(int value, ItemStack **top);
int pop(ItemStack **top);

int main(){
    ItemStack *stack = initStack(12);
    printf("%d\n", stack->value);
    push(2, &stack);
    printf("%d\n", stack->value);
    push(-13, &stack);
    printf("%d\n", stack->value);
    int deleteValue = pop(&stack);
    printf("%d %d\n", stack->value, deleteValue);
    int deleteValue2 = pop(&stack);
    printf("%d %d\n", stack->value, deleteValue2);
    int deleteValue3 = pop(&stack);
    printf("%d\n", deleteValue3);
    int deleteValue4 = pop(&stack);
    return 1;
}

ItemStack* initStack(int value){
    ItemStack *newItem = malloc(sizeof(ItemStack));
    newItem->next = NULL;
    newItem->value = value;
    return newItem;
}

void push(int value, ItemStack **top){
    ItemStack *newItem = malloc(sizeof(ItemStack));
    newItem->value = value;
    newItem->next = *top;
    *top = newItem;
}

int pop(ItemStack **top){
    if(*top == NULL){
        printf("Error : Empty stack");
        return 0;
    }
    int tempValue = (*top)->value;
    *top = (*top)->next;
    return tempValue;
}
