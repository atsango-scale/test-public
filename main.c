#include <stdio.h>
#include "graph.h"

int main() {
    printf("Starting 3D Graph Tool Demo\n");

    // Create a graph with initial capacity for 5 nodes and 5 edges
    Graph* my_graph = create_graph(5, 5);
    if (!my_graph) {
        fprintf(stderr, "Failed to create graph. Exiting.\n");
        return 1;
    }

    // Add some nodes
    Point3D p1 = {1.0f, 2.0f, 3.0f};
    int node0_id = add_node(my_graph, p1);
    if (node0_id == -1) {
        fprintf(stderr, "Failed to add node 0\n");
    } else {
        printf("Added node %d at (%.2f, %.2f, %.2f)\n", node0_id, p1.x, p1.y, p1.z);
    }

    Point3D p2 = {4.0f, 5.0f, 6.0f};
    int node1_id = add_node(my_graph, p2);
    if (node1_id == -1) {
        fprintf(stderr, "Failed to add node 1\n");
    } else {
        printf("Added node %d at (%.2f, %.2f, %.2f)\n", node1_id, p2.x, p2.y, p2.z);
    }

    Point3D p3 = {7.0f, 8.0f, 9.0f};
    int node2_id = add_node(my_graph, p3);
    if (node2_id == -1) {
        fprintf(stderr, "Failed to add node 2\n");
    } else {
        printf("Added node %d at (%.2f, %.2f, %.2f)\n", node2_id, p3.x, p3.y, p3.z);
    }
    
    // Add some more nodes to test resizing (if initial capacity was small, e.g. 1 or 2)
    Point3D p4 = {10.0f, 11.0f, 12.0f};
    add_node(my_graph, p4);
    Point3D p5 = {13.0f, 14.0f, 15.0f};
    add_node(my_graph, p5);
    Point3D p6 = {16.0f, 17.0f, 18.0f}; // This should trigger resize if initial_max_nodes was 5
    add_node(my_graph, p6);

    // Add some edges
    if (add_edge(my_graph, node0_id, node1_id) == 0) {
        printf("Added edge between node %d and node %d\n", node0_id, node1_id);
    } else {
        fprintf(stderr, "Failed to add edge between node %d and node %d\n", node0_id, node1_id);
    }

    if (add_edge(my_graph, node1_id, node2_id) == 0) {
        printf("Added edge between node %d and node %d\n", node1_id, node2_id);
    } else {
        fprintf(stderr, "Failed to add edge between node %d and node %d\n", node1_id, node2_id);
    }
    
    if (add_edge(my_graph, node0_id, node2_id) == 0) { // Edge 0 -> 2
        printf("Added edge between node %d and node %d\n", node0_id, node2_id);
    } else {
        fprintf(stderr, "Failed to add edge between node %d and node %d\n", node0_id, node2_id);
    }

    // Try adding an edge with an invalid node ID
    printf("\nAttempting to add an invalid edge (node 99 does not exist):\n");
    if (add_edge(my_graph, node0_id, 99) != 0) {
        printf("Correctly failed to add edge with invalid node ID.\n");
    }

    // Print the graph
    print_graph(my_graph);

    // additional comments so that I have permissions to push

    // Free the graph memory
    free_graph(my_graph);
    my_graph = NULL; // Avoid dangling pointer

    printf("\n3D Graph Tool Demo Finished\n");
    return 0;
} 
