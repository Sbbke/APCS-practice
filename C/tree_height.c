#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100005
#define MAX_ELEMENTS 100

int n, H=0;
int v[MAX_SIZE];
long long int ans = 0;
int M[MAX_SIZE][MAX_ELEMENTS];

int tall(int id) {
    if (v[id] != -1) return v[id];
    int t = 0, len = M[id][0], tmp;
    printf("id = %d\n", id);

    for (int i = 1; i <= len; i++) {

        printf("i = %d, tmp = %d\n", i, tmp);

        tmp = tall(M[id][i]) + 1;
        if (tmp > t) t = tmp;
    }

    v[id] = t;
    return t;
}

int main() {
    scanf("%d", &n);
    memset(v, -1, sizeof(v));

    for (int i = 1; i <= n; i++) {
        M[i][0] = 0;
    }

    for (int i = 1, a; i <= n; i++) {
        scanf("%d", &a);
        M[i][0] = a;
        for (int j = 1, b; j <= a; j++) {
            scanf("%d", &b);
            M[i][j] = b;
        }
    }

    for (int i = 1, tmp; i <= n; i++) {
        tmp = tall(i);
        ans += tmp;
        if (tmp > v[H]) H = i;
    }


    printf("%d\n%lld\n", H, ans);

    return 0;
}
