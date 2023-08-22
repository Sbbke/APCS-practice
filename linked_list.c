#include <stdio.h>
#include <stdlib.h>
#define IS_EMPTY(first) (!(first))
typedef struct listnode *listPointer;

typedef struct listnode
{
    int data;
    listPointer next;

}listnode;

void insert(listPointer *first, listPointer x, int data){
    listPointer tmp;
    tmp = malloc(sizeof(*tmp));
    tmp->data = data;
    if(*first) {
        tmp->next = x->next;
        x->next = tmp;
    }else{
        tmp->next = NULL;
        *first = tmp;
    }

}
void delete(listPointer *first, listPointer trail, listPointer x){
    if(trail){
        trail->next = x->next;
    }else{
        *first = (*first)->next;
    }
    free(x);
}

void printList(listPointer first){
    for ( ; first; first = first->next)
    {
        printf("%4d", first->data);
    }
    printf("\n");
    
}

int main(){

    listPointer first = NULL;
    // first = malloc(sizeof(*first));
    // first->data = 5;
    // listPointer secound = NULL;
    // secound = malloc(sizeof(*secound));
    // secound->data = 8;
    // secound->next = NULL;
    // first->next = secound;
    insert(&first,NULL,6);
    insert(&first,first,8);

    printList(first);
    return 0;
}