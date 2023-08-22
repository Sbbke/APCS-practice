#include <stdio.h>
#include <stdlib.h>

typedef struct node *treePointer;
typedef struct node
{
    int value;
    treePointer parent;
}node;

treePointer newNode(int data)
{
    treePointer nNode = malloc(sizeof(node));
    nNode->value = data;

    nNode->parent = NULL;
    //nNode->right_child = NULL;

    return (nNode);

}

treePointer treeTravesal(treePointer tree, int k){
    if(!tree) return NULL;
    if(k == tree->value){
        return (&tree);
    }
    return treeTravesal( tree->parent, k);
}

int main(){
    int n, ans = 0;
    scanf("%d", &n);
    int child, parent;
    scanf("%d %d",  &parent, &child);
    treePointer root = newNode(child);
    root->parent = newNode(parent);
    printf("address of root = %d\n address of parent = %d\n", &root, &(root->parent));
    treePointer tmpP;
    treePointer tmpC;
    for(int i = 1; i < n; i++){

        scanf("%d %d", &parent, &child);
        tmpP = treeTravesal(root, parent);
        tmpC = treeTravesal(root, child);
        printf("test1\n");
        printf("address of tmpP = %d\n address of tmpC = %d\n", &tmpP, &tmpC);
        if( tmpP != NULL){
            printf("tmpP = %d\n", tmpP->value);
            if(tmpC != NULL){
                printf("tmpC = %d\n", tmpC->value);
                printf("ERROR!!\n multiple relationship of parent and child!!\n");
            }else{
                printf("tmpP != NULL and tmpC == NULL\n");
                tmpC->parent = tmpP;
            }
        }else{
            printf("tmpP = NULL\n");
            if(tmpC != NULL){
                printf("tmpC = NULL\n");
                tmpC->parent = newNode(parent);
            }else{
                printf("ERROR!!\n unrelated relationship");
            }
        }

    }

    return 0;
}