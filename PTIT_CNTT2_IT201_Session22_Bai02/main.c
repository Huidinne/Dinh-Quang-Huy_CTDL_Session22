#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int vertex;
    struct Node *next;
}Node;
Node* createNode(int vertex) {
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
};
Node* adj[100];
void addEdge(int u, int v) {
    Node* newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;

    Node* newNode2 = createNode(v);
    newNode2->next = adj[u];
    adj[u] = newNode2;
};
void printAdjList(int n) {
    for (int i = 0; i < n; i++) {
        Node* temp = adj[i];
        printf("%d: ", i);
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main(void) {
    int n,u,v;
    scanf("%d",&n);
    for (int i = 0; i < 6; i++) {
        scanf("%d %d",&u,&v);
        addEdge(u,v);
    };
    printAdjList(n);
    return 0;
}