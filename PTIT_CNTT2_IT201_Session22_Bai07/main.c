#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adj[MAX];
int visited[MAX];

int queue[MAX];
int front = 0, rear = 0;

void enqueue(int v) {
    queue[rear++] = v;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    Node* nodeV = createNode(v);
    nodeV->next = adj[u];
    adj[u] = nodeV;

    Node* nodeU = createNode(u);
    nodeU->next = adj[v];
    adj[v] = nodeU;
}

void BFS(int start) {
    visited[start] = 1;
    enqueue(start);

    while (!isEmpty()) {
        int u = dequeue();
        printf("%d ", u);

        for (Node* p = adj[u]; p != NULL; p = p->next) {
            int v = p->vertex;
            if (!visited[v]) {
                visited[v] = 1;
                enqueue(v);
            }
        }
    }
}

int main() {
    int v, e;
    printf("Nhap so dinh va canh: ");
    scanf("%d %d", &v, &e);

    for (int i = 0; i < v; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Nhap %d canh (u v):\n", e);
    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        addEdge(u, w);
    }

    int start;
    printf("Nhap dinh bat dau BFS: ");
    scanf("%d", &start);

    printf("Thu tu duyet BFS: ");
    BFS(start);
    return 0;
}
