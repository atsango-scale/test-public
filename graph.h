#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a 3D point
typedef struct {
    float x;
    float y;
    float z;
} Point3D;

// Structure to represent a node in the graph
typedef struct {
    int id;
    Point3D position;
    // Add other node-specific data here if needed
} Node;

// Structure to represent an edge in the graph
typedef struct {
    int start_node_id;
    int end_node_id;
    // Add edge-specific data here (e.g., weight) if needed
} Edge;

// Structure to represent the graph
typedef struct {
    Node* nodes;
    int num_nodes;
    int max_nodes;

    Edge* edges;
    int num_edges;
    int max_edges;
} Graph;

// Function prototypes

/**
 * @brief Creates and initializes a new graph.
 * @param initial_max_nodes Initial capacity for nodes.
 * @param initial_max_edges Initial capacity for edges.
 * @return Pointer to the newly created graph, or NULL on failure.
 */
Graph* create_graph(int initial_max_nodes, int initial_max_edges);

/**
 * @brief Adds a new node to the graph.
 * @param graph Pointer to the graph.
 * @param position The 3D position of the new node.
 * @return The ID of the newly added node, or -1 on failure.
 */
int add_node(Graph* graph, Point3D position);

/**
 * @brief Adds a new edge to the graph.
 * @param graph Pointer to the graph.
 * @param start_node_id ID of the starting node for the edge.
 * @param end_node_id ID of the ending node for the edge.
 * @return 0 on success, -1 on failure (e.g., invalid node IDs, graph full).
 */
int add_edge(Graph* graph, int start_node_id, int end_node_id);

/**
 * @brief Prints the graph information (nodes and edges) to stdout.
 * @param graph Pointer to the graph.
 */
void print_graph(const Graph* graph);

/**
 * @brief Frees all memory allocated for the graph.
 * @param graph Pointer to the graph to be freed.
 */
void free_graph(Graph* graph);

#endif // GRAPH_H 