#include <stdio.h>
#include <stdlib.h>
typedef struct relation
{
    int parent;
    int child;
}relation;

int findDeepest(relation *re, int n, int *deepestIndex){
    //printf("deepest =%d\n", *deepest);
    for (int i = 0; i < n; i++)
    {
        if(re[*deepestIndex].parent == re[i].parent){
            for (int j = 0; j < n; j++)
            {
                if(j == *deepestIndex){
                    continue;
                }
                 if(re[i].child == re[j].parent){
                    *deepestIndex = j;
                    findDeepest(re, n, deepestIndex);

                 }
            }
            
        }
       
    }
}

int exist(int *node, int i, int n){
    for (int j = 0; j < n; j++)
    {
        if(node[j] == i){
            return 1;
        }
    }
    return 0;
}

void addElement(relation *traveled, relation item, int n){
    int i = 0;

        while (traveled[i].parent != -1)
        {
            i++;
        }
        if(i < n){
            traveled[i] = item;
        }else{
            printf("exceed limitation\n");
        }

    
}

int childExist(relation *re, int node,int n){
    for (int i = 0; i < n; i++)
    {
        if (node == re[i].parent)
        {
            return 1;
        }
        
    }
    return 0;
}
int childCount(relation *re, int node, int n){
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (node == re[i].parent)
        {
            count++;
        }
        
    }
    return count;
}
int findParent(int parent, relation *re, int n){
    for (int i = 0; i < n; i++)
    {
        if(re[i].parent == parent){
            return 1;
        }
    }
    return -1;
    

}
int findIndex(relation node, relation *re, int  n){

    for (int i = 0; i < n; i++)
    {
        if(re[i].parent == node.parent && re[i].child == node.child){
            return i;
        }
    }
    return -1;
    
}

relation pop(relation *re, int index, int *n){
    relation tmp = re[index];
    for (int i = index; i < *n-2; i++)
    {
        re[i]= re[i+1];
    }
    *n-=1;
    return tmp;
}

void findLongest(relation node,relation *re, relation *traveled, int n, int *ans){

    addElement(traveled, node, n);
    printf("node = %d %d, ans = %d\n", node.parent, node.child, *ans);
    //go up
    int hasParent = 0;
    for (int i = 0; i < n; i++)
    {
        
        if (findIndex(re[i], traveled, n) != -1)
        {
            continue;
        }
        if(node.parent == re[i].child){
            hasParent = 1;
            *ans += 1;
            findLongest(re[i], re, traveled, n, ans);
        }

    }
    // if(hasParent != 1){
    //     *ans -= 1;
    // }

    //search sibling
    for (int i = 0; i < n; i++)
    {
        if (findIndex(re[i], traveled, n) != -1)
        {
            continue;
        }
        if(node.parent == re[i].parent){
            *ans += 1;
            findLongest(re[i], re, traveled, n, ans);
        }
        
    }

    //go down
    for (int i = 0; i < n; i++)
    {
        if (findIndex(re[i], traveled, n) != -1)
        {
            continue;
        }
        if(node.child == re[i].parent){
            findLongest(re[i], re, traveled, n, ans);
        }
        
    }




    
}
int main(){

    int n, ans = 1;
    scanf("%d ", &n);
    relation *re = malloc( (n-1) * sizeof(relation) );
    int *node = malloc( n * sizeof(int));
    int count = 0;

    for(int i = 0; count < n; i++){
        scanf("%d %d", &re[i].parent, &re[i].child);
        //printf("%d %d \n", re[i].parent, re[i].child);
        
        if(!exist(node, re[i].parent, count)){
            node[count] = re[i].parent;
            count++;
        }
        if(!exist(node, re[i].child, count)){
            node[count] = re[i].child;
            count++;
        }


        // for (int j = 0; j < count; j++)
        // {
        //     printf("%d ", node[j]);
        // }
        // printf("\n");
        

    }

    
    int root = re[0].parent, rootIndex = 0;
    //find the root
    for(int i = 1; i < n ; i++){
        if(re[i].child == root){
            root = re[i].parent;
            rootIndex = i;
        }
    }
    printf("-----------------------------\nfind root\n");
    printf("root= %d\n", root);


    //From root fing the deepest child
    int deepest = rootIndex;
    findDeepest(re, n, &deepest);

    printf("-----------------------------\nfind deepest\n");
    // for (int j = 0; j < n-1; j++)
    // {
    //     printf("%d %d\n", re[j].parent, re[j].child);
    // }
    // printf("\n");
    
    printf("deepest = %d\n ", re[deepest].child);
    //printf("index = %d value = %d\n", deepest, re[deepest].child);

    relation *traveled = malloc((n-1) * sizeof(relation));
    for (int i = 0; i < n-1; i++)
    {
        traveled[i].parent = -1;
        traveled[i].child = -1;
    }
    
    printf("-----------------------------\nfind longest\n");

    findLongest(re[deepest],re, traveled, n, &ans);
    for (int h = 0; h < n; h++)
    {
        printf("%d %d\n", traveled[h].parent, traveled[h].child);
    }
    
    printf("ans = %d \n", ans);

    free(re);
    free(traveled);
    
    return 0;
}