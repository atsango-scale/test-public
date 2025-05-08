#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For memcpy if we implement resizing later

Graph* create_graph(int initial_max_nodes, int initial_max_edges) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (!graph) {
        perror("Failed to allocate graph");
        return NULL;
    }

    graph->nodes = (Node*)malloc(initial_max_nodes * sizeof(Node));
    if (!graph->nodes) {
        perror("Failed to allocate nodes");
        free(graph);
        return NULL;
    }
    graph->num_nodes = 0;
    graph->max_nodes = initial_max_nodes;

    graph->edges = (Edge*)malloc(initial_max_edges * sizeof(Edge));
    if (!graph->edges) {
        perror("Failed to allocate edges");
        free(graph->nodes);
        free(graph);
        return NULL;
    }
    graph->num_edges = 0;
    graph->max_edges = initial_max_edges;

    printf("Graph created with capacity for %d nodes and %d edges.\n", initial_max_nodes, initial_max_edges);
    return graph;
}

int add_node(Graph* graph, Point3D position) {
    if (!graph) {
        fprintf(stderr, "Graph is NULL\n");
        return -1;
    }
    // Basic resizing (double capacity if full)
    // A more robust implementation would handle realloc failure.
    if (graph->num_nodes >= graph->max_nodes) {
        int new_max_nodes = graph->max_nodes == 0 ? 1 : graph->max_nodes * 2;
        Node* new_nodes_ptr = (Node*)realloc(graph->nodes, new_max_nodes * sizeof(Node));
        if (!new_nodes_ptr) {
            perror("Failed to reallocate nodes array");
            return -1; // Node not added
        }
        graph->nodes = new_nodes_ptr;
        graph->max_nodes = new_max_nodes;
        printf("Resized nodes array to %d\n", new_max_nodes);
    }

    Node* new_node = &(graph->nodes[graph->num_nodes]);
    new_node->id = graph->num_nodes; // Simple ID assignment
    new_node->position = position;
    
graph->num_nodes++;
    return new_node->id;
}

int add_edge(Graph* graph, int start_node_id, int end_node_id) {
    if (!graph) {
        fprintf(stderr, "Graph is NULL\n");
        return -1;
    }

    // Check if node IDs are valid
    if (start_node_id < 0 || start_node_id >= graph->num_nodes ||
        end_node_id < 0 || end_node_id >= graph->num_nodes) {
        fprintf(stderr, "Invalid node ID for edge: %d -> %d (num_nodes: %d)\n", start_node_id, end_node_id, graph->num_nodes);
        return -1;
    }

    // Basic resizing (double capacity if full)
    // A more robust implementation would handle realloc failure.
    if (graph->num_edges >= graph->max_edges) {
        int new_max_edges = graph->max_edges == 0 ? 1 : graph->max_edges * 2;
        Edge* new_edges_ptr = (Edge*)realloc(graph->edges, new_max_edges * sizeof(Edge));
        if (!new_edges_ptr) {
            perror("Failed to reallocate edges array");
            return -1; // Edge not added
        }
        graph->edges = new_edges_ptr;
        graph->max_edges = new_max_edges;
        printf("Resized edges array to %d\n", new_max_edges);
    }

    Edge* new_edge = &(graph->edges[graph->num_edges]);
    new_edge->start_node_id = start_node_id;
    new_edge->end_node_id = end_node_id;

    graph->num_edges++;
    return 0; // Success
}

void print_graph(const Graph* graph) {
    if (!graph) {
        printf("Graph is NULL\n");
        return;
    }

    printf("\n--- Graph Data ---\n");
    printf("Nodes: %d (Capacity: %d)\n", graph->num_nodes, graph->max_nodes);
    for (int i = 0; i < graph->num_nodes; ++i) {
        printf("  Node %d: (%.2f, %.2f, %.2f)\n", 
               graph->nodes[i].id, 
               graph->nodes[i].position.x, 
               graph->nodes[i].position.y, 
               graph->nodes[i].position.z);
    }

    printf("Edges: %d (Capacity: %d)\n", graph->num_edges, graph->max_edges);
    for (int i = 0; i < graph->num_edges; ++i) {
        printf("  Edge %d: Node %d -> Node %d\n", 
               i, 
               graph->edges[i].start_node_id, 
               graph->edges[i].end_node_id);
    }
    printf("--- End Graph Data ---\n\n");
}

void free_graph(Graph* graph) {
    if (!graph) {
        return;
    }
    if (graph->nodes) {
        free(graph->nodes);
        graph->nodes = NULL;
    }
    if (graph->edges) {
        free(graph->edges);
        graph->edges = NULL;
    }
    free(graph);
    graph = NULL;
    printf("Graph memory freed.\n");
} 