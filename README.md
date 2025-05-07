# 3D Graph Tool (Core)

This is a basic command-line tool in C for creating and representing 3D graphs.
It currently allows for programmatic definition of nodes (with 3D coordinates) and edges.

## Features

*   Define 3D points, nodes, and edges.
*   Create a graph data structure.
*   Add nodes with 3D positions.
*   Add edges connecting nodes by their IDs.
*   Print a textual representation of the graph (nodes and their coordinates, edges and their connections).
*   Basic dynamic resizing of node and edge arrays.

## Files

*   `graph.h`: Header file with data structure definitions and function prototypes.
*   `graph.c`: Source file with the implementation of graph functions.
*   `main.c`: Example program demonstrating the usage of the graph library.
*   `Makefile`: For compiling the project.

## Prerequisites

*   A C compiler (e.g., GCC)
*   Make

## How to Build and Run

1.  **Build the project:**
    Open your terminal in the project directory and run:
    ```sh
    make
    ```
    This will compile the source files and create an executable named `graph_tool`.

2.  **Run the executable:**
    ```sh
    ./graph_tool
    ```
    This will run the demo program in `main.c`, which creates a sample graph, prints its details to the console, and then cleans up.

3.  **Clean up build files:**
    ```sh
    make clean
    ```
    This will remove the compiled object files and the executable.

## Future Enhancements

This is a foundational version. Potential future enhancements include:

*   Interactive command-line interface for graph manipulation.
*   Loading graph data from files (e.g., CSV, custom format).
*   Saving graph data to files.
*   More sophisticated graph algorithms (e.g., traversals, shortest path).
*   Interface with a 3D graphics library (e.g., OpenGL, Mesa) for visualization.
*   More robust error handling and memory management.