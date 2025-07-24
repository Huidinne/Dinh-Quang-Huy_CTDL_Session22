#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node** adj, int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

int countNeighbors(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    int n, v;
    Node* adj[MAX] = {NULL};

    printf("Nhap so dinh va so canh: ");
    scanf("%d %d", &n, &v);

    printf("Nhap cac canh:\n");
    for (int i = 0; i < v; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        addEdge(adj, u, w);
    }

    int k;
    printf("Nhap dinh k muon kiem tra: ");
    scanf("%d", &k);

    int result = countNeighbors(adj[k]);
    printf("So dinh ke voi %d la: %d\n", k, result);
    return 0;
}
