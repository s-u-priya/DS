#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Structure to represent an adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Array of adjacency lists representing the graph
struct Node* adj[MAX_NODES];

// Array to keep track of visited nodes (0 for not visited, 1 for visited)
int visited[MAX_NODES];

// Stack for DFS (using array for simplicity)
int stack[MAX_NODES];
int top = -1;

// Function to push onto the stack
void push(int v) {
    if (top == MAX_NODES - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = v;
}

// Function to pop from the stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1; // Indicate empty stack
    }
    return stack[top--];
}

// Function to add an edge to the graph (undirected)
void addEdge(int u, int v) {
    // Add edge from u to v
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
    // Add edge from v to u (for undirected graph)
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

// Depth First Search function (Iterative using stack)
void DFS(int startVertex, int numNodes) {
    // Initialize visited array
    for (int i = 0; i < numNodes; i++) {
        visited[i] = 0;
    }

    // Push the starting vertex onto the stack and mark it as visited
    push(startVertex);
    visited[startVertex] = 1;

    printf("Depth First Search starting from vertex %d: ", startVertex);

    while (top != -1) {
        int currentVertex = pop();
        printf("%d ", currentVertex);

        // Traverse the adjacency list of the current vertex
        struct Node* neighbor = adj[currentVertex];
        while (neighbor != NULL) {
            int adjVertex = neighbor->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                push(adjVertex);
            }
            neighbor = neighbor->next;
        }
    }
    printf("\n");
}
int main() {
    int numNodes = 7; // Example graph with 7 nodes (0 to 6)
    // Initialize adjacency lists
    for (int i = 0; i < numNodes; i++) {
        adj[i] = NULL;
    }

    // Add edges to the graph (example undirected graph)
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);
    addEdge(2, 6);
    int startVertex = 0;
    DFS(startVertex, numNodes);
    return 0;
}
