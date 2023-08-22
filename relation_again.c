#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NODES 100004

typedef long long ll;

typedef struct Node {
    ll node;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} LinkedList;

void dfs(ll node, ll par, ll h[], LinkedList tree[]) {
    Node* curr = tree[node].head;
    while (curr) {
        ll i = curr->node;
        if (i != par) {
            h[i] = h[node] + 1;
            dfs(i, node, h, tree);
        }
        curr = curr->next;
    }
}

void addEdge(ll u, ll v, LinkedList tree[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->node = v;
    newNode->next = tree[u].head;
    tree[u].head = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->node = u;
    newNode->next = tree[v].head;
    tree[v].head = newNode;
}

void initializeTree(ll n, LinkedList tree[]) {
    for (ll i = 0; i <= n; i++) {
        tree[i].head = NULL;
    }
}

void clearTree(ll n, LinkedList tree[]) {
    for (ll i = 0; i <= n; i++) {
        Node* curr = tree[i].head;
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

int main() {
    ll n;
    while (scanf("%lld", &n) != EOF) {
        LinkedList tree[MAX_NODES];
        ll h[MAX_NODES] = {0};

        initializeTree(n, tree);
        for (ll i = 1; i <= n - 1; i++) {
            ll a, b;
            scanf("%lld %lld", &a, &b);
            addEdge(a, b, tree);
        }

        dfs(0, -1, h, tree);
        int maxnode = -1;
        for (ll i = 0; i <= n - 1; i++) {
            if (h[i] > maxnode) {
                maxnode = h[i];
            }
        }

        printf("%d\n", maxnode);
        clearTree(n, tree);
    }

    return 0;
}
