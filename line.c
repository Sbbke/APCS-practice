#include <stdio.h>
#include <stdlib.h>

struct line
{
    int start;
    int end;
    /* data */
};

void insert(struct line e,struct line *kv, int n);
void insertionSort(struct line *kv, int n);

void calculateAns(struct line *kv,int *ans, int n);

int main(){

    int n, ans =0;
    scanf("%d", &n);
    struct line *kv = malloc((n+1) * sizeof(struct line ));

    for(int i = 1; i <= n; i++){
        scanf("%d %d", &kv[i].start, &kv[i].end);
    }

    for(int i = 1; i <= n; i++){
        printf("%d %d", kv[i].start, kv[i].end);
    }
    printf("---------------------\n enter sort\n");

    insertionSort(kv, n);

    printf("---------------------\n after sort\n");
    for(int i = 1; i <= n; i++){
        printf("%d %d", kv[i].start, kv[i].end);
    }
    calculateAns(kv, &ans, n);
    printf("%d\n", ans);
    

}
void calculateAns(struct line *kv,int *ans, int n){
    struct line currLine = kv[1];
    for(int i = 2; i <= n; i++){
        if(kv[i].start > currLine.end){
            *ans += currLine.end - currLine.start;
            currLine = kv[i];
        }else if(kv[i].end < currLine.end){
            currLine.end = kv[i].end;
        }
    }

    *ans += currLine.end - currLine.start;
}

void insertionSort(struct line *kv, int n){
    for(int j = 2; j <= n; j++){
        struct line temp = kv[j];
        insert(temp, kv, j-1);
    }
}

void insert(struct line e,struct line *kv, int i){
    kv[0] = e;
    while (e.start < kv[i].start)
    {
        kv[i+1] = kv[i];
        i--;
    }
    kv[i+1] = e;
    
}