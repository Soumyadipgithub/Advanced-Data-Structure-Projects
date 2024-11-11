#include <stdio.h>
#include <stdlib.h>

// Node structure for adjacency list
struct Node {
    int dest;
    struct Node* next;
};

// Structure to represent an adjacency list
struct AdjList {
    struct Node* head;
};

// Function to create a new adjacency list node
struct Node* createNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Recursive function for DFS traversal
void DFSRec(struct AdjList adj[], int visited[], int s) {
    // Mark the current vertex as visited
    visited[s] = 1;

    // Print the current vertex
    printf("%d ", s);

    // Traverse all adjacent vertices that are not visited yet
    struct Node* current = adj[s].head;
    while (current != NULL) {
        int dest = current->dest;
        if (!visited[dest]) {
            DFSRec(adj, visited, dest);
        }
        current = current->next;
    }
}

// Main DFS function that initializes the visited array and calls DFSRec
void DFS(struct AdjList adj[], int V, int s) {
    // Initialize visited array to false
    int visited[5] = {0};
    DFSRec(adj, visited, s);
}

// Function to add an edge to the adjacency list
void addEdge(struct AdjList adj[], int s, int t) {
    // Add edge from s to t
    struct Node* newNode = createNode(t);
    newNode->next = adj[s].head;
    adj[s].head = newNode;

    // Add edge from t to s (for undirected graph)
    newNode = createNode(s);
    newNode->next = adj[t].head;
    adj[t].head = newNode;
}

int main() {
    int V, E, s, t, source;

    // Get number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    // Create an array of adjacency lists
    struct AdjList adj[V];

    // Initialize each adjacency list as empty
    for (int i = 0; i < V; i++) {
        adj[i].head = NULL;
    }

    // Get edges from the user
    for (int i = 0; i < E; i++) {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &s, &t);
        addEdge(adj, s, t);
    }

    // Get the source vertex for DFS
    printf("Enter the source vertex for DFS: ");
    scanf("%d", &source);

    // Perform DFS from the source vertex
    printf("DFS from source: %d\n", source);
    DFS(adj, V, source);

    return 0;
}