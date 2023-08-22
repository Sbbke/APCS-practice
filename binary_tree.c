#include <stdio.h>
#include <stdlib.h>


typedef struct node *treePointer;
typedef struct node
{
    int value;
    treePointer left_child;
    treePointer right_child;
};

treePointer *newNode(int data)
{
    treePointer nNode = malloc(sizeof(treePointer));
    nNode->value = data;

    nNode->left_child = NULL;
    nNode->right_child = NULL;

    return(nNode);

};

int main(){

    int n, ans=0;
    scanf("%d", &n);
    



    return 0;
}