#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Structure to represent the adjacency list for each node
struct Node {
    int vertex;
    struct Node* next;
};

// Array of adjacency lists representing the graph
struct Node* adj[MAX_NODES];

// Array to keep track of visited nodes
int visited[MAX_NODES];

// Queue structure for BFS
int queue[MAX_NODES];
int front = -1;
int rear = -1;

// Function to add an edge to the graph
    void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    // For an undirected graph, add the reverse edge as well
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

// Function to enqueue a vertex
void enqueue(int v) {
    if (rear == MAX_NODES - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = v;
}

// Function to dequeue a vertex
int dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return -1; // Indicate an empty queue
    }
    int v = queue[front++];
    if (front > rear) {
        front = rear = -1; // Reset queue if it becomes empty
    }
    return v;
}

// Breadth First Search function
void BFS(int startVertex, int numNodes) {
    // Initialize visited array
    for (int i = 0; i < numNodes; i++) {
        visited[i] = 0;
    }

    // Enqueue the starting vertex and mark it as visited
    enqueue(startVertex);
    visited[startVertex] = 1;

    printf("Breadth First Search starting from vertex %d: ", startVertex);

    while (front != -1) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        // Traverse the adjacency list of the current vertex
        struct Node* neighbor = adj[currentVertex];
        while (neighbor != NULL) {
            int adjVertex = neighbor->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(adjVertex);
            }
            neighbor = neighbor->next;
        }
    }
    printf("\n");
}

int main() {
    int numNodes = 6; // Example graph with 6 nodes (0 to 5)

    // Initialize adjacency lists
    for (int i = 0; i < numNodes; i++) {
        adj[i] = NULL;
    }

    // Add edges to the graph (example undirected graph)
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(3, 5);
    addEdge(4, 5);

    // Perform BFS starting from vertex 0
    BFS(0, numNodes);

    return 0;
}
